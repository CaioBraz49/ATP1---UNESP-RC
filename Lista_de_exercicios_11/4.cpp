#include <stdio.h>
#include <stdlib.h>


void imprimir_matriz(int n, int **matriz);

int main() {
    FILE *arquivo;
    int n;

    int **matrizA = NULL;
    int **matrizB = NULL;
    int **matrizSoma = NULL;

    arquivo = fopen("matriz.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo matriz.txt");
        return 1;
    }

    if (fscanf(arquivo, "%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Erro: Dimensao da matriz invalida no arquivo.\n");
        fclose(arquivo);
        return 1;
    }

    matrizA = (int **)malloc(n * sizeof(int *));
    matrizB = (int **)malloc(n * sizeof(int *));
    matrizSoma = (int **)malloc(n * sizeof(int *));

    if (matrizA == NULL || matrizB == NULL || matrizSoma == NULL) {
        fprintf(stderr, "Erro: Falha na alocacao de memoria.\n");
        free(matrizA);
        free(matrizB);
        free(matrizSoma);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        matrizA[i] = (int *)malloc(n * sizeof(int));
        matrizB[i] = (int *)malloc(n * sizeof(int));
        matrizSoma[i] = (int *)malloc(n * sizeof(int));
        if (matrizA[i] == NULL || matrizB[i] == NULL || matrizSoma[i] == NULL) {
            fprintf(stderr, "Erro: Falha na alocacao de memoria das colunas.\n");
            exit(1);
        }
    }

    printf("Lendo matrizes %dx%d do arquivo...\n\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(arquivo, "%d", &matrizA[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(arquivo, "%d", &matrizB[i][j]);
        }
    }
    fclose(arquivo);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrizSoma[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }

    printf("Matriz A:\n");
    imprimir_matriz(n, matrizA);
    printf("\nMatriz B:\n");
    imprimir_matriz(n, matrizB);
    printf("\nResultado da Soma (A + B):\n");
    imprimir_matriz(n, matrizSoma);

    for (int i = 0; i < n; i++) {
        free(matrizA[i]);
        free(matrizB[i]);
        free(matrizSoma[i]);
    }
    free(matrizA);
    free(matrizB);
    free(matrizSoma);

    return 0;
}


void imprimir_matriz(int n, int **matriz) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}