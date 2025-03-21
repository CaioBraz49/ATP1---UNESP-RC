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
    int* a,* b;
    // DEFININDO AS VARIAVEIS
    
    a = (int*)malloc(sizeof(int));
    b = (int*)malloc(sizeof(int)); // ALOCA MEMORIA PARA a E b
    
    if (a == NULL || b == NULL) { // GARANTE QUE A MEMORIA FOI ALOCADA CORRETAMENTE
        printf("Erro ao alocar memória.\n");
        return 1;
    }
    printf("Bem vindo(a) a substituicao de 2 numeros!\nEscolha seus numeros");
    // ESSE DO WHILE LOOP VAI FORÇAR O USUARIO A DIGITAR UM NUMERO

    printf("\na: ");
    if(scanf(" %i", a) != 1) { // CASO scanf RETORNE ALGUM VALOR DIFERENTE DE 1, QUE SIGNIFICA QUE NAO SERA
                                      // TOTALMENTE COMPOSTO POR NUMEROS, ELE RETORNA 1 COMO ERRO E FECHA
        printf("\nNao e um inteiro! Fechando programa...");
        return(1);
    }

    printf("b: ");
    if(scanf(" %i", b) != 1) { // MESMA LOGICA DO OUTRO
        printf("\nNao e um inteiro! Fechando programa...");
        return(1);
    }
    
    if (a != b) { // GARANTE QUE A ALOCACAO DE MEMORIA E DIFERENTE
       *a ^= *b; // ESSE E O METODO xorSwap, QUE UTILIZA POINTERS PARA TROCAR AS VARIAVEIS
       *b ^= *a;
       *a ^= *b;
    }

    printf("Trocando...\n\na: %i\nb: %i\n", *a, *b);

    free(a);
    free(b); // LIBERA A MEMORIA ALOCADA PARA a E b
    getchar();
    return(0);
}
