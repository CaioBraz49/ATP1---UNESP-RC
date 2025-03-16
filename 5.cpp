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
    int numero1, numero2, numerofinal, operacao;
    bool eh_int;
    char input[50];
    // DEFININDO AS VARIAVEIS
    
    printf("Bem vindo(a) a calculadora de 2 numeros!\nEscolha seus numeros");
    // ESSE DO WHILE LOOP VAI FORÇAR O USUARIO A DIGITAR UM NUMERO
    do {
        eh_int = true; // DEFINIR COMO TRUE PARA TER CERTEZA DE QUE EM QUALQUER HORA QUE O LOOP REITERE ELE ESTEJA TRUE
        printf("\nNumero 1: ");
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
        printf("Numero 2: ");
        scanf("%s", input); 

        for (int i = 0; i < strlen(input); i++) {
            if (!isdigit(input[i])) {
                eh_int = false;
                break;
            }
        }
        if (eh_int == false) {
            printf("Nao e um inteiro! Tente novamente.\n");
        }

    } while (eh_int == false);
    numero2 = atoi(input); 
    
    // OUTRO DO WHILE LOOP PARA FORÇAR O USUARIO A ESCOLHER UMA OPERACAO DIGITANDO UM NUMERO
    printf("Otimo! Agora escolha a operacao que quiser\nDigite o numero da operacao que quiser realizar\n");
    do {
        printf("\n1. Soma\n2. Subtracao\n3. Multiplicacao\n4. Divisao\n");
        eh_int = true; // RESETAR eh_int PARA NAO IGNORAR LOOP
        scanf("%i", &operacao); // RECEBER INPUT DE QUAL OPERACAO O USUARIO ESCOLHEU
        getchar(); // ESPERAR POR INPUT
        if (operacao == 1 || operacao == 2 || operacao == 3 || operacao == 4) {
            printf("\nOperacao selecionada"); // VER SE O INPUT E VALIDO
        }
        else {
            printf("Comando nao entendido, tente novamente");
            eh_int = false; // SE NAO FOR VALIDO ELE DEFINE COMO FALSO E REITERA O LOOP
        }
    } while (eh_int == false);
    
    
    if (operacao == 1) { // NUMERO DA SOMA
        numerofinal = numero1 + numero2;
        printf("\n\nA soma de %i e %i é %i!", numero1, numero2, numerofinal);
    }
    
    if (operacao == 2) { // NUMERO DA SUBTRACAO
        numerofinal = numero1 - numero2;
        printf("\n\nA subtracao de %i e %i é %i!", numero1, numero2, numerofinal);
    }
    
    if (operacao == 3) { // NUMERO DA MULTIPLICACAO
        numerofinal = numero1 * numero2;
        printf("\n\nA multiplicacao de %i e %i é %i!", numero1, numero2, numerofinal);
    }
    
    if (operacao == 4) { // NUMERO DA DIVISAO
        numerofinal = numero1 / numero2;
        printf("\n\nA divisao de %i e %i é %i!", numero1, numero2, numerofinal);
    }
    
    getchar();
    return 0;
}