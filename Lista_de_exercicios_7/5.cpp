#include <stdio.h>
#include <stdlib.h>

void inverter_array(int *array, int t) {
    int *inicio = array;
    int *fim = array + t - 1;
    while(inicio < fim) {
        int temp = *inicio;
        *inicio = *fim;
        *fim = temp;
        inicio++;
        fim--;
    }
}


int main() {
    int t = 5;
    int array[t];

    for (int i = 0; i < t; i++) {
        printf("Escolha um numero para A[%i]: ", i);
        scanf("%i", &array[i]);
    }

    inverter_array(array, t);
    for (int i = 0; i < t; i++) {
        printf("%d, ", array[i]);
    }

    getchar();
    return(0);
}