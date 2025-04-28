#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// estrutura do par ordenado
typedef struct {
    int x;
    int y;
} par;

float distancia(par ordenado1, par ordenado2) {     // aplica a formula da distancia
    return sqrt(pow((ordenado2.x - ordenado1.x), 2) + pow((ordenado2.y - ordenado1.y), 2));
}

int main() {
    par ordenado1, ordenado2;

    printf("Escolha o primeiro par ordenado\nx1: "); // salvando as variaveis
    scanf("%d", &ordenado1.x);
    printf("y1: ");
    scanf("%d", &ordenado1.y);
    printf("\nAgora para o segundo par ordenado\nx2: ");
    scanf("%d", &ordenado2.x);
    printf("y2: ");
    scanf("%d", &ordenado2.y);

    float d = distancia(ordenado1, ordenado2);  // utilizando pares ordenados dessa forma conseguimos passar apenas 2 parametros para a funcao
    printf("\nDistancia = %f", d);
    
    getchar();
    return(0);
}