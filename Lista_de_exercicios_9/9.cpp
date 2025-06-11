#include <stdio.h>
#include <stdlib.h>


// Imprime os elementos de uma matriz dinâmica no console.
void imprimirMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d\t", matriz[i][j]); 
        }
        printf("\n");
    }
}


// Permite que o usuário preencha os valores de uma matriz dinâmica.
void preencherMatriz(int **matriz, int linhas, int colunas) {
    printf("\n--- Preenchendo a Matriz ---\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Digite o valor para a posicao [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Aloca dinamicamente uma matriz com o número de linhas e colunas especificado.
int **alocador(int linhas, int colunas) {
    int **matriz = (int **) malloc(linhas * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro de alocacao para as linhas!\n");
        return NULL;
    }
    
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *) malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro de alocacao para as colunas na linha %d!\n", i);
            
            for (int k = 0; k < i; k++) {
                free(matriz[k]); 
            }
            free(matriz);
            
            return NULL;
        }
    }
    
    printf("\nMatriz de %d x %d alocada com sucesso!\n", linhas, colunas);
    return matriz;
}


// Libera o espaço alocado pela matriz.
void liberador(int **matriz, int linhas) {
    if (matriz == NULL) {
        return;
    }

    for (int i = 0; i < linhas; i++) {
        free(matriz[i]); 
    }
    free(matriz); 
    printf("Memoria da matriz liberada com sucesso!\n");
}

int main() {
    int linhas, colunas;
    int **minhaMatriz = NULL;

    printf("Escolha o numero de linhas desejadas: ");
    scanf("%d", &linhas);
    printf("Escolha o numero de colunas desejadas: ");
    scanf("%d", &colunas);
    
    minhaMatriz = alocador(linhas, colunas);

    preencherMatriz(minhaMatriz, linhas, colunas);

    imprimirMatriz(minhaMatriz, linhas, colunas);

    if (minhaMatriz != NULL) {    
        liberador(minhaMatriz, linhas);
    }

    getchar();
    return 0;
}