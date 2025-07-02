#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    char nome[100];
    float notae1;
    float notap1;
    float notap2;
    struct no *proximo;
} No;


No* iniciar() {
    No *lista = (No*)malloc(sizeof(No));
    lista->proximo = NULL;
    return lista;
}


void liberar_lista(No *lista) {
    No *atual = lista;
    while (atual != NULL) {
    No *temp = atual;
    atual = atual->proximo;
    free(temp);
    }
}


void adicionar(No *lista, char nome[100], float notae1, float notap1, float notap2) {
    if (lista->proximo == NULL) {
        strcpy(lista->nome, nome);
        lista->notae1 = notae1;
        lista->notap1 = notap1;
        lista->notap2 = notap2;
        lista->proximo = iniciar();
    }
    else {
        adicionar(lista->proximo, nome, notae1, notap1, notap2);
    }
}


float media(float notae1, float notap1, float notap2) {
    // Considerando o mesmo calculo de media do ex anterior
    float media = notae1 * 0.2 + notap1 * 0.8 + notap2 * 0.8 / (0.2 + 0.8 + 0.8);
    return (media);
}


void imprimir(No *lista) {
    No *atual = lista;
    if (lista->proximo != NULL) {
        while (atual->proximo != NULL) {
            printf("%s, ", atual->nome);
            printf("media = %f", media(atual->notae1, atual->notap1, atual->notap2));
            atual = atual->proximo;
        }
    }
}


int main() {
    //No lista = iniciar();
    No a, b;
    a.nome = 'A';
    b.nome = 'B';
    a.notae1 = 8;
    a.notap1 = 9;
    a.notap2 = 10;
    

}