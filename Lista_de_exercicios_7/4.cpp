#include <stdio.h>
#include <stdlib.h>

int interseccao(int *array1, int *array2, int t, int *ambos) {
    int contadorArray = 0;

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            if (array1[i] == array2[j]) {
                ambos[contadorArray] = array1[i]; // ou array2[j]
                contadorArray++;
                break; // evita adicionar o mesmo valor mais de uma vez
            }
        }
    }
    return contadorArray; // número de elementos encontrados
}

int main() {
    int t = 10;
    int array1[t], array2[t], ambos[t];

    for (int i = 0; i < t; i++) {
        printf("Escolha um numero para A[%i]: ", i);
        scanf("%i", &array1[i]);
    }

    printf("\n");
    for (int i = 0; i < t; i++) {
        printf("Escolha um numero para B[%i]: ", i);
        scanf("%i", &array2[i]);
    }

    int n = interseccao(array1, array2, t, ambos);

    printf("\n\nElementos em comum:\n");
    for (int i = 0; i < n; i++) {
        printf("%i, ", ambos[i]);
    }
    printf("\n");

    return 0;
}
