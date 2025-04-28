#include <stdio.h>
#include <stdlib.h>

float a, b, c, x;

float quadratica(float a, float b, float c, float x) {  // aplica a formula quadratica para todos os valores de a, b, c e x
    return((a * x * x) + (b * x) + c);
}


int main() {
    // escolhendo os valores
    printf("Escolha A: ");
    scanf("%f", &a);
    printf("Escolha B: ");
    scanf("%f", &b);
    printf("Escolha C: ");
    scanf("%f", &c);
    printf("Escolha X: ");
    scanf("%f", &x);

    printf("\n%f", quadratica(a, b, c, x)); 

    getchar();
    return(0);
}