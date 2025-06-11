#include <stdio.h>
#include <stdlib.h>


int** alocarMatrizDinamica(int linhas, int colunas) {
    int **matriz = (int **) malloc(linhas * sizeof(int *));
    if (matriz == NULL) return NULL;
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *) malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            for (int k = 0; k < i; k++) free(matriz[k]);
            free(matriz);
            return NULL;
        }
    }
    return matriz;
}


void liberarMatriz(int **matriz, int linhas) {
    if (matriz == NULL) return;
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}


void preencherMatriz(int **matriz, int linhas, int colunas) {
    printf("\n--- Preenchendo a Matriz ---\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Digite o valor para a posicao [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}


void imprimirMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}


void produtoMatrizes(int **matA, int **matB, int **matResultado, int linA, int colA, int colB) {
    for (int i = 0; i < linA; i++) {
        for (int j = 0; j < colB; j++) {
            matResultado[i][j] = 0;
            for (int k = 0; k < colA; k++) { 
                matResultado[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

int main() {
    int linA, colA, linB, colB;
    int **matrizA = NULL, **matrizB = NULL, **matrizProduto = NULL;

    printf("--- Dimensoes da Primeira Matriz (A) ---\n");
    printf("Digite o numero de linhas: ");
    scanf("%d", &linA);
    printf("Digite o numero de colunas: ");
    scanf("%d", &colA);

    printf("\n--- Dimensoes da Segunda Matriz (B) ---\n");
    printf("Digite o numero de linhas: ");
    scanf("%d", &linB);
    printf("Digite o numero de colunas: ");
    scanf("%d", &colB);

    if (colA != linB) {
        printf("\nErro: O produto de matrizes nao e possivel.\n");
        printf("O numero de colunas de A (%d) deve ser igual ao numero de linhas de B (%d).\n", colA, linB);
        return 1;
    }

    matrizA = alocarMatrizDinamica(linA, colA);
    matrizB = alocarMatrizDinamica(linB, colB);
    matrizProduto = alocarMatrizDinamica(linA, colB);

    if (matrizA == NULL || matrizB == NULL || matrizProduto == NULL) {
        printf("Erro fatal de alocacao de memoria.\n");
        if (matrizA) liberarMatriz(matrizA, linA);
        if (matrizB) liberarMatriz(matrizB, linB);
        if (matrizProduto) liberarMatriz(matrizProduto, linA);
        return 1;
    }

    printf("\n--- Preenchendo Matriz A ---");
    preencherMatriz(matrizA, linA, colA);
    printf("\n--- Preenchendo Matriz B ---");
    preencherMatriz(matrizB, linB, colB);

    produtoMatrizes(matrizA, matrizB, matrizProduto, linA, colA, colB);

    printf("\n--- Matriz A ---\n");
    imprimirMatriz(matrizA, linA, colA);

    printf("\n--- Matriz B ---\n");
    imprimirMatriz(matrizB, linB, colB);

    printf("\n--- Matriz Produto (A * B) ---\n");
    imprimirMatriz(matrizProduto, linA, colB);

    liberarMatriz(matrizA, linA);
    liberarMatriz(matrizB, linB);
    liberarMatriz(matrizProduto, linA);
    
    printf("\nPrograma finalizado com sucesso!\n");

    getchar();
    return 0;
}