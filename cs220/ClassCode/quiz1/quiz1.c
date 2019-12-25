#include <stdio.h>

int * arrayPointer(int * start, int row, int col, int cols){

  //if (row<0) return NULL;
//  if(cols<0) return NULL;
//  if(col<0|| col>=cols) return NULL;

  return start + (row*cols)+col;




}


int main(int argc, char **argv){
  int test[3][4] = {{0,1,2,3}, {10,11,12,13}, {20,21,22,23}};

  printf("Address of test[2][3] is %p\n", &(test[2][3]));
  printf("Function result = %p \n", arrayPointer((int*)test,2,3,4));





}
