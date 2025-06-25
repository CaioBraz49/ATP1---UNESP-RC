#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void gerar_cartela(FILE *arquivo) {
    fprintf(arquivo, "B, I, N, G, O\n");
    for (int i = 0; i < 5; i++) {
        fprintf(arquivo, "%d, ", (rand() % 15) + 1);
        fprintf(arquivo, "%d, ", (rand() % 15) + 16);
        if (i == 2) {
            fprintf(arquivo, "FREE, ");
        }
        else {
            fprintf(arquivo, "%d, ", (rand() % 15) + 31);
        }
        fprintf(arquivo, "%d, ", (rand() % 15) + 46);
        fprintf(arquivo, "%d\n", (rand() % 15) + 61);
    }
}


double round(double valor, int casas = 0) {
    int fator = 1;
    for(int i = 0; i < casas; i++) {
        fator *= 10;
    }
    return((double)(int)(valor * fator + 0.5) / (double)fator);
}


int main(int argc, char *argv[]) {
    srand(time(NULL));

    FILE *arquivo = fopen("cartela.csv", "w");

    if (arquivo == NULL) {
        printf("Nao foi possivel criar o arquivo da cartela.\n");
        return 1;
    }

    gerar_cartela(arquivo);

    fclose(arquivo);

    printf("Cartela gerada com sucesso no arquivo 'cartela.txt'.\n");

    return 0;
}