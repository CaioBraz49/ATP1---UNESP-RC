/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int numero1, numero2, soma;
    bool eh_int;
    char input[50];
    // DEFININDO AS VARIAVEIS
    
    printf("Bem vindo(a) ao somatorio de 2 numeros!\nEscolha seus numeros");
    // ESSE DO WHILE LOOP VAI FORÇAR O USUARIO A DIGITAR UM NUMERO
    do {
        eh_int = true; // DEFINIR COMO TRUE PARA TER CERTEZA DE QUE EM QUALQUER HORA QUE O LOOP REITERE ELE ESTEJA TRUE
        printf("\n\nNumero 1: ");
        scanf("%s", input); // EU ACHEI MAIS FACIL LER O INPUT COMO STRING PORQUE FICA MAIS FACIL DE REITERAR
        //  TERMO A TERMO PARA VER SE ELA POSSUI ALGUM CARACTERE QUE NAO SEJA UM INT

        // VERIFICA SE O CARACTERE E UM INT
        for (int i = 0; i < strlen(input); i++) {
            if (!isdigit(input[i])) {
                eh_int = false; // SE ENCONTRAR UM CARACTERE NAO NUMERICO MARCA COMO FALSO
                break;
                // COMO SO E NECESSARIO 1 CARACTERE NAO INT PARA SER FALSO, PODEMOS USAR BREAK PARA IGNORAR O RESTO
            }
        }
        if (eh_int == false) {
            printf("Nao e um inteiro! Tente novamente.");
        }

    } while (eh_int == false);
    numero1 = atoi(input); // CONVERTE A STRING (INPUT) PARA INT


    // RESESTANDO O eh_int PARA ELE NÃO PASSAR DIRETO PELO LOOP
    // A LOGICA DESSE LOOP E IGUAL A OUTRA
    do {
        eh_int = true;
        printf("\n\nNumero 2: ");
        scanf("%s", input); 

        for (int i = 0; i < strlen(input); i++) {
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
    
    soma = numero1 + numero2;
    printf("\n\nA soma de %i e %i é %i!", numero1, numero2, soma);
    // SOMANDO E PRINTANDO OS NUMEROS
    
    getchar();
    return 0;
}
