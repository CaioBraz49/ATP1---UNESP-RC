#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int tamanho; 
    char input[50];
    bool eh_int = true;
    
    // loop para forçar o usuario a escolher um numero inteiro
    do {
        eh_int = true; // definir como true para ter certeza de que em qualquer hora que o loop reitere ele esteja true
        printf("Informe o tamanho do triangulo: ");
        scanf("%s", input); // eu achei mais facil ler o input como string porque fica mais facil de reiterar
        // termo a termo para ver se ela possui algum caractere que nao seja um int

        // verifica se o caractere e um intverifica se o caractere e um int
        for (int i = 0; i < int(strlen(input)); i++) {
            if (!isdigit(input[i])) {
                eh_int = false; // se encontrar um caractere nao numerico marca como falso
                break;
                // como so e necessario 1 caractere nao int para ser falso, podemos usar break para ignorar o resto
            }
        }
        if (eh_int == false) {
            printf("\nNao e um inteiro positivo! Tente novamente.\n");
        }

    } while (eh_int == false);
    tamanho = atoi(input); // converte a string (input) para int

    for (int i = 0; i < tamanho; i++) { // loop principal do desenho
        for (int i0 = tamanho - 1; i0 > i; i0--) { // loop dedicado para exibir espaço para que fique em formato de piramide
            printf(" "); // existe o -1 no tamanho para que a ultima fileira nao fique com um espaco a mais
        }      
        for (int i1 = 0; i1 <= i*2; i1++) { // loop para imprimir os asteriscos
            printf("*"); // existe um vezes 2 para imprimir asteriscos para os dois lados (esquerda) e (direita)
        }  
        printf("\n"); // passa para a proxima linha
    }

    getchar();
    return(0);
}