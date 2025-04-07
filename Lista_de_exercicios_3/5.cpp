#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numero, fibonacci = 0, f1 = 1, f2 = 0, i = 0; // valores iniciais para o loop for somar 
    char input[50];
    bool eh_int = true;
    
    // loop para forçar o usuario a escolher um numero inteiro
    do {
        eh_int = true; // definir como true para ter certeza de que em qualquer hora que o loop reitere ele esteja true
        printf("Informe um numero limite: ");
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
    numero = atoi(input); // converte a string (input) para int

    printf("Sequência de fibonacci ate %i:\n", numero);
    while (true) {
        printf("%i", fibonacci);
        if (f1 + f2 < numero) {
            printf(", "); // printar virgula para ficarem bonitos os numeros
        }
        else if (f1 + f2 > numero) {
            printf("\nO ultimo numero antes de %i eh %i!\n\n", numero, fibonacci);
            return(0);
            // o while loop so vai acabar aqui, quando o proximo termo exceder o numero escolhido
        }
        fibonacci = f1 + f2; // a sequencia eh a soma de f1 e f2
        f1 = f2; // depois os valores de f1 e f2 alteram, se preparando para o proximo termo 
        f2 = fibonacci; // f1 se torna f2, enquanto f2 se torna o termo atual de fibonacci
        i++;
    }
    
    getchar();
    return(1);   
}