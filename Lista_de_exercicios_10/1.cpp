#include <stdio.h>
#include <stdlib.h>

int count = 0;

int main (){
    
float *realPtr = NULL;
long *integerPtr = NULL;
(float *)integerPtr = *realPtr;
    count++;
    printf("count = %d", count);

    if (count < 10) {
        return(main());
    }

    getchar();
    return 0;
}
