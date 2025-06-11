#include <stdio.h>
#include <stdlib.h>

// Função que calcula a soma dos elementos da diagonal principal
int somaDiagonalPrincipal(int **matriz) {
    int soma = 0;
    for (int i = 0; i < 3; i++) {
        soma += matriz[i][i];
    }
    return soma;
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
            for (int k = 0; k < i; k++) free(matriz[k]);
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
    int **matriz = alocarMatriz();
    
    printf("Digite os elementos da matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    int soma = somaDiagonalPrincipal(matriz);

    printf("\nA matriz informada foi:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nA soma dos elementos da diagonal principal e: %d\n", soma);

    liberarMatriz(matriz);

    getchar();
    return 0;
}