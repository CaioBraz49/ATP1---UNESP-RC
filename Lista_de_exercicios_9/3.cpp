#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int linha;
    int coluna;
} posicao;

posicao encontrar(int **matriz, int n, int linha, int coluna) {
    posicao parOrdenado;
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            if (matriz[i][j] == n) {
                parOrdenado.linha = i;
                parOrdenado.coluna = j;

                printf("linha %d e coluna %d", i, j);
            }
        }
    }
    return parOrdenado;
}

int main() {
    int numero, valor, linhas, colunas;

    printf("Escolha o numero de linhas desejadas: ");
    scanf("%d", &linhas);
    printf("Escolha o numero de colunas desejadas: ");
    scanf("%d", &colunas);


    int **matriz = (int **) malloc(linhas * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro de alocacao para linhas da matriz original.\n");
        return 1; 
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *) malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro de alocacao para colunas da matriz original (linha %d).\n", i);
            for (int k = 0; k < i; k++) {
                free(matriz[k]);
            }
            free(matriz);
            return 1; 
        }
    }

    printf("Digite os elementos da matriz 3x3:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Escolha a matriz[%d][%d] = ", i, j);
            if (scanf("%d", &numero) != 1) { 
                printf("Entrada invalida!\n");
                return 1;
            }
            matriz[i][j] = numero;
        }
    }

    printf("\nEscolha o numero que quer encontrar: ");
    scanf("%d", &valor);
    
    posicao imprimir = encontrar(matriz, valor, linhas, colunas);

    getchar(); 
    return 0; 
}