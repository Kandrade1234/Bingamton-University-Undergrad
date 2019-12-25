#include <stdlib.h>
#include <stdio.h>

int main(void) {
         int i = 0;
         printf("A");
         fflush(stdout);
         i++;
         if (fork() > 0) wait(NULL);
         printf("B");
         fflush(stdout);
         i++;
         if (fork() > 0) wait(NULL);
         printf("C");
         fflush(stdout);
         i++;
         if (fork() > 0) wait(NULL);
         printf("D");
         fflush(stdout);
         i++;
         printf(" OUTPUT OF I: %d  ", i );
         fflush(stdout);
         return 0;
}
