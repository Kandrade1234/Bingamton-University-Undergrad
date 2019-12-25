#include <stdlib.h>
#include <stdio.h>


int main(void) {
           int i = 0;
           printf("A");
           fflush(stdout);
        i++;
        fork();
        printf("B");
        fflush(stdout);
        i++;
        fork();
        printf("C");
        fflush(stdout);
        i++;
        fork();
        printf("D");
        fflush(stdout);
        i++;
        printf(" OUTPUT OF I: %d  ", i );
        fflush(stdout);
        return 0;
}
