#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int lado1, lado2, lado3;
    char input[50];
    bool eh_int;
    
    printf("Informe os lados do triangulo\n");
    
    // loop para forçar o usuario a escolher um numero inteiro
    do {
        eh_int = true; // definir como true para ter certeza de que em qualquer hora que o loop reitere ele esteja true
        printf("Lado 1: ");
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
            printf("Nao e um inteiro positivo! Tente novamente.\n\n");
        }

    } while (eh_int == false);
    lado1 = atoi(input); // converte a string (input) para int
    
    
    // exatamente a mesma logica do outro do while loop, mas agora para escolher o lado2
    do {
        eh_int = true; 
        printf("Lado 2: ");
        scanf("%s", input); 

        for (int i = 0; i < int(strlen(input)); i++) {
            if (!isdigit(input[i])) {
                eh_int = false; 
                break;
            }
        }
        if (eh_int == false) {
            printf("Nao e um inteiro positivo! Tente novamente.\n\n");
        }

    } while (eh_int == false);
    lado2 = atoi(input); 
        
        
    // exatamente a mesma logica do outro do while loop, mas agora para escolher o lado3
    do {
        eh_int = true; 
        printf("Lado 3: ");
        scanf("%s", input); 

        for (int i = 0; i < int(strlen(input)); i++) {
            if (!isdigit(input[i])) {
                eh_int = false; 
                break;
            }
        }
        if (eh_int == false) {
            printf("Nao e um inteiro! Tente novamente.\n\n");
        }

    } while (eh_int == false);
    lado3 = atoi(input); 


    // verificar os criterios de existencia de um triangulo
    if (abs(lado2 - lado3) < lado1 && lado1 < lado2 + lado3) {
        // mesmo ficando um pouco menos otimizado usar varios if's, eu preferi fazer assim mesmo 
        // pois senão a linha ficaria muito longa para acompanhar
        if (abs(lado1 - lado3) < lado2 && lado2 < lado1 + lado3) {
            if (abs(lado1 - lado2) < lado3 && lado3 < lado1 + lado2) {
                // caso os criterios de existencia de triangulo sejam atendidos, o triangulo pode ser formado
                printf("Triangulo possivel\n");
            }
        }
    }
    // caso contrario, o triangulo nao pode ser formado e retorna, fechando o programa
    else {
        printf("Os lados descritos nao podem formar um triangulo!");
        return(1);
    }
    
    // baseaia as condicoes no teorema de pitagoras
    // considera que a hipotenusa pode estar em qualquer um dos lados
    if  ((pow(lado1, 2) + pow(lado2, 2) == pow(lado3, 2)) || pow(lado2, 2) + pow(lado3, 2) == pow(lado1, 2) || (pow(lado3, 2) + pow(lado1, 2) == pow(lado2, 2))) {
        printf("\nO triangulo e retangulo!");
        return(0);
    }
    // caso nao atenda ao teorema de pitagoras, o triangulo nao e retangulo
    else {
        printf("\nO triangulo nao e retangulo!");
        return(1);
    }

    getchar();
    return(0);
}