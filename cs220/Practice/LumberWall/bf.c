#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
  if(argc<3){
  printf("please invoke as %s <width> <height>\n", argv[0]);
  return 1;
  }
  int width = atoi(argv[1]);
  int height = atoi(argv[2]);

  if(width <=0){
  printf("Width not valid\n");
  return 1;
  }

  if(height <=0){
  printf("Height not valid\n");
  return 1;
  }
  int boards = (height+7)/8;
  int bf = (boards*width+11)/12;
  printf("To cover a room that is %d x %d, i need %d feed of 8 imch lumber\n", width, height, bf);

  return 0;




}
