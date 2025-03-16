/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1, numero2;
    // DEFININDO AS VARIAVEIS
    printf("Bem vindo(a) ao somatorio de 2 numeros!\nEscolha seus numeros");
    // ESSE DO WHILE LOOP VAI FORÇAR O USUARIO A DIGITAR UM NUMERO

    printf("\nNumero 1: ");
    if(scanf(" %i", &numero1) != 1) { // CASO scanf RETORNE ALGUM VALOR DIFERENTE DE 1, QUE SIGNIFICA QUE NAO SERA
                                      // TOTALMENTE COMPOSTO POR NUMEROS, ELE RETORNA 1 COMO ERRO E FECHA
        printf("\nNao e um inteiro! Fechando programa...");
        return(1);
    }

    printf("\nNumero 2: ");
    if(scanf(" %i", &numero2) != 1) { // MESMA LOGICA DO OUTRO
        printf("\nNao e um inteiro! Fechando programa...");
        return(1);
    }
    
    numero1 += numero2; // UTILIZANDO numero1 COMO SENDO A SOMA DOS 2
    printf("\nA soma e %i!", numero1);
    getchar();
    return(0);
}