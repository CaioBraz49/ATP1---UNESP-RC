#include <stdio.h>
#include <stdlib.h>

// Função para calcular o produto de duas matrizes 3x3
void produtoMatrizes(int **matrizA, int **matrizB, int **resultado) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            resultado[i][j] = 0; // Inicializa o elemento do resultado
            for (int k = 0; k < 3; k++) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

// Função para imprimir uma matriz
void imprimirMatriz(int **matriz) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para alocar dinamicamente uma matriz 3x3
int** alocarMatriz() {
    int **matriz = (int **) malloc(3 * sizeof(int *));
    if (matriz == NULL) exit(1);
    for (int i = 0; i < 3; i++) {
        matriz[i] = (int *) malloc(3 * sizeof(int));
        if (matriz[i] == NULL) exit(1);
    }
    return matriz;
}

// Função para liberar a memória da matriz
void liberarMatriz(int **matriz) {
    for (int i = 0; i < 3; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int main() {
    int **matrizA = alocarMatriz();
    int **matrizB = alocarMatriz();
    int **matrizProduto = alocarMatriz();

    printf("Digite os elementos da primeira matriz (A):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Matriz A[%d][%d]: ", i, j);
            scanf("%d", &matrizA[i][j]);
        }
    }

    printf("\nDigite os elementos da segunda matriz (B):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Matriz B[%d][%d]: ", i, j);
            scanf("%d", &matrizB[i][j]);
        }
    }

    produtoMatrizes(matrizA, matrizB, matrizProduto);

    printf("\nO resultado do produto das matrizes e:\n");
    imprimirMatriz(matrizProduto);

    liberarMatriz(matrizA);
    liberarMatriz(matrizB);
    liberarMatriz(matrizProduto);

    getchar();
    return 0;
}