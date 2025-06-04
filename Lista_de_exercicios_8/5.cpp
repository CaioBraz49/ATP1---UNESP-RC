#include <stdio.h>
#include <stdlib.h>

int main() {
    int *v = NULL;
    v = (int *) calloc(9, sizeof(int));
    if (v == NULL) return 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", v[i * 3 + j]);
        }
        printf("\n");
    }

    free(v);
    getchar();
    return(0);    
}
