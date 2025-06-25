#include <stdio.h>
#include <stdlib.h>

double round(double valor, int casas = 0) {
    int fator = 1;
    for(int i = 0; i < casas; i++) {
        fator *= 10;
    }
    return((double)(int)(valor * fator + 0.5) / (double)fator);
}


int main(int argc, char *argv[]) {
    if (argc != 2+1 && argc != 1+1) {
        printf("Uso: %s 'valor' 'casas'", argv[0]);
        return 1;
    }
    float valor = atof(argv[1]);
    int casas = atoi(argv[2]);

    double arredondado = round(valor, casas);

    printf("%f", arredondado);
}