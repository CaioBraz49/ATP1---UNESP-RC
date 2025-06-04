#include <stdio.h>
#include <stdlib.h> 

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

    printf("\nValores armazenados no vetor:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);
    getchar();
    return 0; 
}