/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    float raio, area;
    bool eh_int;
    char input[50];
    // DEFININDO AS VARIAVEIS
    
    printf("Bem vindo(a) a calculadora de area do circulo!\nInforme o tamanho do raio que queira");
    // ESSE DO WHILE LOOP VAI FORÇAR O USUARIO A DIGITAR UM NUMERO
    do {
        eh_int = true; // DEFINIR COMO TRUE PARA TER CERTEZA DE QUE EM QUALQUER HORA QUE O LOOP REITERE ELE ESTEJA TRUE
        printf("\nRaio: ");
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
    raio = atof(input); // CONVERTE A STRING (INPUT) PARA INT
    
    // FORMULA DE AREA = pi * raio ao quadrado
    area = M_PI * pow(raio, 2);
    printf("\nA area do circulo de raio %f e igual a %f\n", raio, area);
    
    getchar();
    return(0);
}