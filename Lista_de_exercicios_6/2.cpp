#include <stdio.h>
#include <stdlib.h>

int somatorio(int n) {
  if (n == 1) {
    return(1);
  }
  return(n + somatorio(n - 1));
}

int main() {
  int n, soma;

  printf("Escolha um numero: ");
  scanf("%d", &n);

  soma = somatorio(n);
  printf("A soma de %d ate 1 eh %d\n", n, soma);

  getchar();
  return(0);
}