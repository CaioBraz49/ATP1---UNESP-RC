#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numero;
    bool eh_int;
    char input[50];
    
    // loop para forçar o usuario a escolher um numero inteiro
    do {
        eh_int = true; // definir como true para ter certeza de que em qualquer hora que o loop reitere ele esteja true
        printf("Escolha seu numero: ");
        scanf("%s", input); // eu achei mais facil ler o input como string porque fica mais facil de reiterar
        // termo a termo para ver se ela possui algum caractere que nao seja um int

        // verifica se o caractere e um intverifica se o caractere e um int
        for (int i = 0; i < int(strlen(input)); i++) {
            if (!isdigit(input[i]) && !strcmp(&input[i], "-")) {
                eh_int = false; // se encontrar um caractere nao numerico marca como falso
                break;
                // como so e necessario 1 caractere nao int para ser falso, podemos usar break para ignorar o resto
            }
        }
        if (eh_int == false) {
            printf("\nNao e um inteiro! Tente novamente.\n");
        }

    } while (eh_int == false);
    numero = atoi(input); // converte a string (input) para int


    // se o numero for positivo (ou zero) o sistema identifica como positivo
    if (numero >= 0){
        printf("\nO numero %d e positivo!", numero);
    }
    // caso contrario e negativo
    else {
        printf("\nO numero e negativo!");
    }

    getchar();
    return(0);
}