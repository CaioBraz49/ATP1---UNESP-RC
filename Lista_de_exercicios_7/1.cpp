#include <stdio.h>
#include <stdlib.h>

int main() {
    char *palavra;
    printf("Escolha uma palavra\n");
    scanf("%s", palavra);

    printf("%s comeca com '%c'\n", palavra, *palavra);

    getchar();
    return(0);
}