#include <stdio.h>
#include <stdlib.h>

int minFact(int);

int main(int argc, char **argv) {
int input = atoi(argv[1]);
if(input<=0){
  printf("Must be a value greater than zero. GOODBYE!\n");
  return 1;
}
printf("The minimum factor of the given input is: %d", minFact(atoi(argv[1])));
printf("\n");

int factor = minFact(atoi(argv[1]));

printf("%d =", input);

while (input > 1){
  input = input / factor;
  printf(" %d", factor);
  if(input >1) printf(" x");
  factor = minFact(input);

}
printf("\n");

return 0;

}

int minFact (int input){
  int i =2;

    while(i <=input){
    if(input % i == 0) break;
    i++;
  }
  return i;
}
