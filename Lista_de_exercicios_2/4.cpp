#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int idade, servico;
    char input[50];
    bool eh_int;
    
    // loop para forçar o usuario a escolher um numero inteiro
    do {
        eh_int = true; // definir como true para ter certeza de que em qualquer hora que o loop reitere ele esteja true
        printf("Informe a idade do requerinte: ");
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
            printf("\nNao e um inteiro! Tente novamente.\n");
        }

    } while (eh_int == false);
    idade = atoi(input); // converte a string (input) para int
    
    
    // exatamente a mesma logica do outro do while loop, mas agora para escolher os anos de servico
    do {
        eh_int = true; 
        printf("Agora informe a quantidade de anos prestados em servico: ");
        scanf("%s", input); 

        for (int i = 0; i < int(strlen(input)); i++) {
            if (!isdigit(input[i])) {
                eh_int = false; 
                break;
            }
        }
        if (eh_int == false) {
            printf("Nao e um inteiro! Tente novamente.");
        }

    } while (eh_int == false);
    servico = atoi(input); 
    

    // se tiver no mínimo 65 anos de vida, ou 30 de serviços, ou então 60 anos de vida com 25 de serviços ele entra no loop
    // ou seja, ele pode se aposentar
    if (idade >= 65 || servico >= 30 || (idade >= 60 && servico >= 25)){
        printf("O requerinte pode se aposentar");
        return(0);
    }
    // caso contrario, nao pode se aposentar
    else {
        printf("O requerinte nao pode se aposentar");
        return(1);
    }

    getchar();
    return(0);
}