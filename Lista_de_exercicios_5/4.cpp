#include <stdio.h>
#include <stdlib.h>

int eh_primo(int numero) {
    if (numero <= 1) return(0);     // para nao precisarmos nos preocupar com numeros menores ou iguais a 1, que nao sao primos
    for (int i = numero - 1; i > 1; i--) {
        if ((numero % i) == 0) { // se for divisao exata nao eh primo
            return(0);
        }
    }
    return(1);   // se passar por todo o for loop sem entrar no if entao sera primo
}

int main() {
    int n;
    printf("Escolha um numero inteiro positivo: ");
    scanf("%d", &n);

    printf("%i\n", eh_primo(n));
    getchar();
    return(0);
}