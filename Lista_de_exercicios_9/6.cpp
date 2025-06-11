#include <stdio.h>
#include <stdlib.h>


// Aloca dinamicamente uma matriz com o número de linhas e colunas especificado.
int** alocarMatrizDinamica(int linhas, int colunas) {
    int **matriz = (int **) malloc(linhas * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro de alocacao de memoria para as linhas.\n");
        return NULL;
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *) malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro de alocacao para colunas da matriz (linha %d).\n", i);
            for (int k = 0; k < i; k++) {
                free(matriz[k]);
            }
            free(matriz);
            return NULL;
        }
    }
    printf("Matriz de %d linhas e %d colunas alocada com sucesso.\n", linhas, colunas);
    return matriz;
}


// Libera a memória de uma matriz alocada dinamicamente.
void liberarMatrizDinamica(int **matriz, int linhas) {
    if (matriz == NULL) return;
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]); 
    }
    free(matriz); 
    printf("\nMemoria da matriz liberada com sucesso.\n");
}

int main() {
    int linhas, colunas;

    printf("Escolha o numero de linhas desejadas: ");
    scanf("%d", &linhas);
    printf("Escolha o numero de colunas desejadas: ");
    scanf("%d", &colunas);

    if (linhas <= 0 || colunas <= 0) {
        printf("Dimensoes invalidas.\n");
        return 1;
    }

    int **matrizUsuario = alocarMatrizDinamica(linhas, colunas);
    
    if (matrizUsuario == NULL) {
        return 1;
    }

    printf("\nDigite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%d", &matrizUsuario[i][j]);
        }
    }

    printf("\nMatriz criada:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d\t", matrizUsuario[i][j]);
        }
        printf("\n");
    }

    liberarMatrizDinamica(matrizUsuario, linhas);

    getchar();
    return 0;
}