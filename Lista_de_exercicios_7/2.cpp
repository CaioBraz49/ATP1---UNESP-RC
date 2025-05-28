#include <stdio.h>
#include <stdlib.h>

int main() {
    int A[5], B[5];

    for (int i = 0; i < 5; i++) {
        printf("Escolha um valor para A[%i]: ", i);
        scanf("%i", &A[i]);
    }

    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf("Escolha um valor para B[%i]: ", i);
        scanf("%i", &B[i]);
    }

    for (int i = 0; i < 5; i++) {
        for (int i0 = 0; i0 < 2; i0++) {
            if (i0 == 0) {
                printf("%i, ", A[i]);
            }
            else if (i0 == 1) {
                printf("%i, ", B[i]);
            }
        }
    }

    getchar();
    return(0);
}