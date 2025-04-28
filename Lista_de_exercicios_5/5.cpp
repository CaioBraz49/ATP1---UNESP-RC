#include <stdio.h>
#include <stdlib.h>

void imprima_imc(float imc) {
    if(imc == 3) printf("Obeso(a)!\n");
    else if(imc == 2) printf("Sobrepeso!\n");
    else if(imc == 1) printf("Saudavel!\n");
    else if(imc == 0) printf("Magro(a)!\n");
}


void calcula_imc(float peso, float altura) {
    float imc = peso / (altura * altura);

    if(imc >= 30.0) imprima_imc(3); // obeso
    if(imc >= 25.0) imprima_imc(2); // sobrepeso
    if(imc >= 18.5) imprima_imc(1); // saudavel
    if(imc < 18.5) imprima_imc(0); // magro
}


int main() {
    float peso, altura;
    printf("Digite seu peso(kg): ");
    scanf("%f", &peso);
    printf("Digite sua altura(m): ");
    scanf("%f", &altura);

    calcula_imc(peso, altura); // ativa a funcao e passa peso e altura

    getchar();
    return(0);
}