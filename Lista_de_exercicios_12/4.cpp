#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int inteiro, decimal;
} Quebrado;

void somar (Quebrado *a, Quebrado *b) {
    int parte_inteira = a->inteiro + b->inteiro;
    int parte_decimal = a->decimal + b->decimal;
    if (parte_decimal >= 10000) {
        parte_inteira++;
        parte_decimal -= 10000;
    }
    soma.inteiro = parte_inteira;
    soma.decimal = parte_decimal;
    return soma;
}