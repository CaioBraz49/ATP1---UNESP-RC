#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int eh_palindromo(char n[]) {   // eh mais facil trabalhar com ela como string, ai podemos comparar termo a termo do numero mais facilmente
    int len = strlen(n);
    for (int i = 0; i < len / 2; i++) {     // o loop so precisa comparar ate metade da palavra, ja que a outra metade precia ser igual
        if (n[i] != n[len - i - 1]) {   // como começamos a contar do 0, o ultimo termo do numero sera n[len - 1]. Ainda subtraimos i para cada vez pegar um numero mais ao "centro"
            return(0);  // nao eh palindromo
        }
    }
    return(1);  // eh palindromo
}

int main() {
    char input[50];
    printf("Escolha um numero: ") ;
    scanf("%s", input);

    int palindromo = eh_palindromo(input); // ativa a funcao do palindromo
    if (palindromo == 0) printf("\nNao eh palindromo!");
    else if (palindromo == 1) printf("\nEh palindromo!");

    getchar();
    return(2);
}