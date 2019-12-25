/*
 ============================================================================
 Name        : hw3.c
 Author      :Kevin Andrade
 Version     :
 Copyright   : Your copyright notice
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char **argv){
  //to initialize character array for string input
   int z=0;
     int size = 0;
     for (z=1; z < argc; z++) {
         size += strlen(argv[z]);
         if (argc > z+1)
             size++;
     }
  char input1[100];
  strcpy(input1, argv[1]);

//Second parameter intialization.
  int w=0;
   int size2 = 0;
   for (w=1; w < argc; w++) {
       size2 += strlen(argv[w]);
       if (argc > w+1)
           size2++;
   }
   char input2[100];
  strcpy(input2,argv[2]);
///////////GETTING A COPY OF THE ORIGINAL NOT MODIFIED STRING TO PRINT AT THE END/////////////

  int length1 = strlen(input1);
  int length1Copy = length1;
  int length2 = strlen(input2);
  int length2Copy = length2;
  char input1Copy[100];
  char input2Copy[100];

  /*RETRIVING FROM COMAND LINE*/
  strcpy(input1Copy, argv[1]);

  strcpy(input2Copy, argv[2]);
///////////REMOVING UNDERSCORES/////////////////////////////////////////////////
int i =0;
int j =0;
char ch;
for (i =0; i < strlen(input1); i++){
  if(input1[i] != '_'){
    ch = input1[i];
    input1[j] = ch;
    j++;
  }
}
input1[j] = '\0';


char ch2;
j=0;
i =0;
for ( i =0; i < strlen(input2); i++){
  if(input2[i] != '_'){
    ch2 = input2[i];
    input2[j] = ch2;
    j++;
    printf("%c", input2[i]);
  }
}

input2[j] = '\0';

//for(int i = 0 ; i < strlen(input2)-1; i++) printf("%c", input2[i]);

///////////////IF THE LENGTHS OF THE STRINGS AFTER removing underscores do not match then return 1 and say it is not an angram!////////////
if(strlen(input1) != strlen(input2)){
  for(int i = 0 ; i < length1Copy; i++) printf("%c", input1Copy[i]);
  printf(" is not an angram of ");
  for (int j = 0; j < length2Copy; j++) printf("%c", input2Copy[j]);
  printf(" UNEQUAL LENGTHS\n");
  return 1;
}


/////////////////Converting all to lowercase to avoid potential issues with capital letters////////////////////
  for(int i =0; i <strlen(input1); i++){
    input1[i] = tolower(input1[i]);
  }
  for(int j =0; j <strlen(input2); j++){
    input2[j] = tolower(input2[j]);
  }

  //printttt

////////Sort first and second char array in alphabetical order to verify if it is angram or not//////////////////////
char temp;
for(int i =0; i < strlen(input1); i++){
  for (int j =i+1; j <strlen(input2); j++){
    if(input1[i] > input1[j]){
    temp = input1[i];
    input1[i]= input1[j];
    input1[j] = temp;
  }
  if(input2[i] > input2[j]){
    temp = input2[i];
    input2[i]= input2[j];
    input2[j] = temp;
  }
}
}



/////////IF EACH CHARACTER IS NOT THE SAME THEN IT IS NOT AN ANGRAM
for(int i = 0; i < strlen(input1); i++){
  if(input1[i] != input2[i]){
    for(int i = 0 ; i < length1Copy; i++) printf("%c", input1Copy[i]);
    printf(" is not an angram of ");
    for (int j = 0; j < length2Copy; j++) printf("%c", input2Copy[j]);
    printf("\n");
    return 1;
  }
}
////////////If the loop does not fall into the if statement then the only thing left is that it is an angram!/////////////////////
for(int i = 0 ; i < length1Copy; i++) printf("%c", input1Copy[i]);
printf(" is an angram of ");
for (int j = 0; j < length2Copy; j++) printf("%c", input2Copy[j]);
printf("\n");
return 0;


}
