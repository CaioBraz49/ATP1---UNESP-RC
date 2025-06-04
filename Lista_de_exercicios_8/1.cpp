#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numero = (int*) malloc(3 * sizeof(int));
    printf("Escolha n: ");
    scanf("%d", numero);
    for(int i = 0; i < *numero; i ++) {
        printf("%d ", numero[i]);
    }
    
    free(numero);
    getchar();
    return(0);
}