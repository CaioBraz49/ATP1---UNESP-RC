#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// funcao principal
int main() {
    int numero1, numero2, numero3, temp;
    bool eh_int;
    char input[50];
    printf("Escolha seus numeros:");
    do {
        eh_int = true; // definir como true para ter certeza de que em qualquer hora que o loop reitere ele esteja true
        printf("\nNumero 1: ");
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
            printf("Nao e um inteiro! Tente novamente.");
        }

    } while (eh_int == false);
    numero1 = atoi(input); // converte a string (input) para int


    // exatamente a mesma logica do outro do while loop, mas agora para escolher o numero2
    do {
        eh_int = true; 
        printf("Numero 2: ");
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
    numero2 = atoi(input); 
    
    // exatamente a mesma logica do outro do while loop, mas agora para escolher o numero3
    do {
        eh_int = true; 
        printf("Numero 3: ");
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
    numero3 = atoi(input); 

    if (numero1 > numero2) {
        temp = numero1;
        numero1 = numero2;
        numero2 = temp;
    }
    // se numero1 for maior que numero2 ele inverte e deixa o numero2 como numero1 e numero2 como numero1

    if (numero1 > numero3) {
        temp = numero1;
        numero1 = numero3;
        numero3 = temp;
    }
    // se numero1 for maior que numero3 ele tambem inverte os dois 

    if (numero2 > numero3) {
        temp = numero2;
        numero2 = numero3;
        numero3 = temp;
    }
    // se numero2 for maior que numero3 tambem serao invertidos

    printf("ORDEM:\n");
    printf("%d, %d, %d", numero1, numero2, numero3);
    // imprime a ordem

    getchar();
    return(0);
}