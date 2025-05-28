#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

bool achador(int x, int *array, int t) {
    for (int i = 0; i < t; i++) {
        if (x == array[i]) {
            return true; 
        }
    }
    return false; 
}

int main() {
    int t = 10; 
    int numeros[t]; 
    int x; 

    for (int i = 0; i < t; i++) {
        printf("Escolha um valor para numero[%i]: ", i);
        scanf("%i", &numeros[i]);
    }

    printf("\nAgora escolha um numero para achar: ");
    scanf("%i", &x);

    if (achador(x, numeros, t)) {
        printf("\nAchado!\n");
    } else {
        printf("\nNao achado!\n");
    }

    getchar();
    return 0; 
}