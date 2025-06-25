#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    bool primo;
    if (argc != 2+1) {
        printf("Uso: 'numero inicial' 'numero final'");
        return 1;
    }
    int n1 = atoi(argv[1]);
    int n2 = atoi(argv[2]);
    for (int i = n1; i < n2; i++) {
        primo = true;
        if (i <= 1) {
            primo = false;
        }
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                //printf("DEBUG: i=%d,j=%d, n1=%d, n2=%d\n\n", i, j, n1, n2);
                primo = false;
            }
        }
        if (primo == true) {
            printf("%d, ", i);
        }
    }

    getchar();
    return 0;
}