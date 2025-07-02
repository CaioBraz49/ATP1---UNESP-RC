#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *nome;
    float notae1;
    float notap1;
    float notap2;
} Alunos;

int main() {
    Alunos aluno[100];
    char *nome;
    int qtd, e1, p1, p2;
    float mediafinal;
    printf("Escolha a quantidade de alunos (menor que 100): ");
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++) {
        printf("\nNome: ");
        scanf("%s", nome);
        aluno[i].nome = nome;

        printf("Nota exercicios: ");
        scanf("%f", &e1);
        aluno[i].notae1 = e1;

        printf("Nota P1: ");
        scanf("%f", &p1);
        aluno[i].notap1 = p1;

        printf("Nota P2: ");
        scanf("%f", &p2);
        aluno[i].notap2 = p2;
    }

    for (int i = 0; i < qtd; i++) {
        printf("\nAluno %s", aluno[i].nome);
        mediafinal = ((0.2 * aluno[i].notae1) + (0.8 * aluno[i].notap1) + (0.8 * aluno[i].notap2)) / 1.2;
        printf("Media final = %f", mediafinal);
    }
}