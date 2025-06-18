#include <stdio.h>
#include <stdlib.h>

int count = 0;

int main() {
    count++;
    printf("Chamada da funcao main, count = %d\n", count);

    if (count < 10) {
        return main();
    }

    printf("\nFim da recursao. Pressione Enter para finalizar o programa.\n");
    getchar();

    return 0;
}
