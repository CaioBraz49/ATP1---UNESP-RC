#include <stdlib.h>
#include <stdio.h>

int main() {
    int *v = NULL;
    int tam;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tam);

    v = (int *) malloc(tam * sizeof(int));

    if (v == NULL) {
        printf("Erro na alocacao de memoria!");
        return 1;
    }

    printf("Digite os %d elementos do array:\n", tam);
    for (int i = 0; i < tam; i++) {
        scanf("%d", &v[i]);
    }

    printf("\nValores do array original:\n");
    for (int i = 0; i < tam; i++) {
        printf("%d ", v[i]); 
    }
    printf("\n");

    int novo_tam = tam / 2;
    int *v_realloc = (int *) realloc(v, novo_tam * sizeof(int));

    if (v_realloc == NULL && novo_tam > 0) {
        printf("Erro na realocacao de memoria!");
        free(v);
        return 1;
    }
    v = v_realloc;

    printf("\nValores do array apos a realocacao para a metade do tamanho:\n");
    for (int i = 0; i < novo_tam; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    free(v);
    return 0; 
}