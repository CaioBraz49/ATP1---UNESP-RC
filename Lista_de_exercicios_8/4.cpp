#include <stdio.h>
#include <stdlib.h> 

int *vetorPar (int *vetorV, int tamanho) {
    int contador = 0;
    int *vetorS = NULL;
    vetorS = (int *)malloc(1 * sizeof(int));
    for (int i = 0; i < tamanho; i++) {
        if ((vetorV[i] % 2) == 0) {
            realloc(vetorS, (contador + 2) * sizeof(int));
            vetorS[contador] = vetorV[i];
            contador++;
        }
    }
    return vetorS;
}



int main() {
    int n;
    int *vetor = NULL;

    printf("Quantos numeros voce deseja armazenar? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("O numero de elementos deve ser positivo.\n");
        return 1;
    }

    vetor = (int *)malloc(n * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    printf("\nDigite os %d numeros:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }


    int *vetorS = vetorPar(vetor, n);
    int tamanhoS = (sizeof(vetorS) / sizeof(int));

    printf("\nValores armazenados no vetor:\n");
    for (int i = 0; i < tamanhoS + 1; i++) {
        printf("%d ", vetorS[i]);
    }
    printf("\n");

    free(vetorS);
    free(vetor);
    getchar();
    return 0; 
}