#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
    int numero;
    char input[50];
    bool eh_int = true;
    
    do {
        eh_int = true; // definir como true para ter certeza de que em qualquer hora que o loop reitere ele esteja true
        printf("Informe um inteiro positivo: ");
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
    numero = atoi(input); // converte a string (input) para int
    
    if (numero > 1) { // considerando o caso do numero ser menor do que 1, que nao sao primos
        for (int i = numero - 1; i > 1; i--){
            if (numero % i == 0) { // se o numero tiver algum divisor nao eh primo
                printf("O numero nao eh primo!");
                return(1); // ja retorna, nao precisa nem terminar de verificar
            }
        }
    }
    else { // menor que 1 nao sao primos
        printf("O numero nao eh primo!");
        return(1);
    }
    printf("O numero eh primo!"); // caso nao entre em nenhum dos casos sera primo
    
    getchar();
    return(0);
}