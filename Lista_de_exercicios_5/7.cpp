#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define _USE_MATH_DEFINES

void calcular_circulo(float *raio, float *area, float *perimetro) {     // aplica as formulas ja conhecidas da matematica
    *area = M_PI * pow(*raio, 2);
    *perimetro = 2 * M_PI * *raio; 
}

int main() {
    float raio, area, perimetro;
    printf("Digite o raio de um circulo: ");
    scanf("%f", &raio);

    calcular_circulo(&raio, &area, &perimetro); // passa os endereços para a funcao

    printf("Perimetro = %f\n", perimetro);
    printf("Area = %f\n", area);

    getchar();
    return(0);
}