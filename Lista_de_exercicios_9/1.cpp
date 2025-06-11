#include <stdio.h>
#include <stdlib.h>

// Função para somar duas matrizes 3x3
void somaMatrizes(int **matrizA, int **matrizB, int **resultado) {
    printf("\n--- Somando as Matrizes ---\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];
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
    if (matriz == NULL) {
        printf("Erro de alocacao de memoria para as linhas.\n");
        exit(1);
    }
    for (int i = 0; i < 3; i++) {
        matriz[i] = (int *) malloc(3 * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro de alocacao de memoria para as colunas.\n");
            for (int k = 0; k < i; k++) {
                free(matriz[k]);
            }
            free(matriz);
            exit(1);
        }
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
    int **matrizSoma = alocarMatriz();

    printf("Digite os elementos da primeira matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Matriz A[%d][%d]: ", i, j);
            scanf("%d", &matrizA[i][j]);
        }
    }

    printf("\nDigite os elementos da segunda matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Matriz B[%d][%d]: ", i, j);
            scanf("%d", &matrizB[i][j]);
        }
    }

    somaMatrizes(matrizA, matrizB, matrizSoma);

    printf("\nA matriz resultante da soma e:\n");
    imprimirMatriz(matrizSoma);

    liberarMatriz(matrizA);
    liberarMatriz(matrizB);
    liberarMatriz(matrizSoma);

    getchar();
    return 0;
}