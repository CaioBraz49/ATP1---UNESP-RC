#include <stdio.h>
#include <stdlib.h>

float celsius_para_fahrenheit(float C) {    // aplica a formula de conversao
    return((C * 9.0/5.0) + 32.0);
}

int main() {
    float c;
    printf("Escolha os graus Celsius: ");
    scanf("%f", &c);

    printf("%f°F\n", celsius_para_fahrenheit(c));   // imprime o resultado da funcao
    getchar();
    return(0);
}