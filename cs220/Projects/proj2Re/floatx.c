#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef unsigned long floatx;
floatx doubleToFloatx(double, int, int);
void binaryToString(double , int [], double, int limit);

//int binaryToStringD(long double , char [], int, double);

void setBit(long *,int,int);
void setToLong(long *,char[],int , int);

int main (int argc, char **argv){

if(argc < 3){
  printf("Please invoke again");
  return 1;
}

int totBits = atoi(argv[1]);
int expBits = atoi(argv[2]);
if(totBits <= 2 || totBits >= 65 ){
  printf("Total number of bits must be between 3 - 64\n");
  return 1;
}
if(expBits<=0 || expBits > totBits - 2){
  printf("Total number of exponent bits must be from 0 - (totBits - 2)\n");
  return 1;
}



  while(!feof(stdin)) {
  double in=NAN; // NAN defined in math.h
  if(1==scanf("%lf ",&in)) {
   floatx fx = doubleToFloatx(in,totBits,expBits);
   printf("%14.8g = floatx(%d,%d) : %016lx\n",in,totBits,expBits,fx);
   printf("\n------------------------------------------------------------------------------------------------------------\n");

  } else {
    char buf[100];
    scanf("%s ",buf);
  printf("Input : %s not recognized as a double\n",buf);
  }
}


}


floatx doubleToFloatx(double in, int totBits, int expBits){
double Integral;
double fpart = modf((in), &Integral);
int bin [64];


//DETERMENING THE SIGN
int sign;
if(in >= 0){
  sign = 0;
}
else sign = 1;


printf("INTEGRAL PART: %f\n", Integral);
printf("FRACTION PART: %f\n\n", fpart);


//INTEGRAL BINARY REPRESENTATION
double check =pow(2, 63);//change
binaryToString(Integral, bin, check, 64);//change
printf("INTEGRAL BINARY REPRESENTATION: ");
for(int i = 0; i < 64; i++)//change
{
  if(i%4 ==0) printf(" ");
  printf("%d",bin[i]);
}


//FRACTION CONVERTION
int frac[64];
check = pow(2, -1);
printf("\n");
binaryToString(fpart, frac, check, 64);

printf("FRACTIONAL BINARY REPRESENTATION :" );
for(int i = 0; i < 64; i++)
{
  if(i%4 ==0) printf(" ");
  printf("%d",frac[i]);
}




//WILL LOOP UNTIL FIRST ONE AND SET CHECKPOINT IN INTEGRAL PART
int swap = -1;
int checkPoint=0; //change
for(int i = 0; i < 64; i++){
  if(bin[i] == 1){
    checkPoint = i;
    swap = i;
    break;
  }
}

//WILL GET ME THE AMOUNT OF DECIMAL POINT MOVE
if(swap > 0){ //checks to see if it was anywhere else between 0 and 62 index (i.e array goes from 0 -63)
  swap = 64 - swap - 1;//change?
}
//printf("\n Numbers of swaps till the end : %d",swap);


//Exponent representation
int bias =  swap + pow (2, (expBits-1))-1;
check = pow(2, expBits-1);
int exp [expBits];
binaryToString(bias, exp, check, expBits);

printf("\nEXPONENT BINARY REPRESENTATION: ");
for(int i = 0; i < expBits; i++){
  printf("%d", exp[i] );
}


//PADDING THE LEFT SIDE WITH 0's FOR COMPLETE BINARY REPRESENTATION
int complete[64];
int current_pos = 0;
if(totBits < 64){    //PADDING
  for(current_pos = 0; current_pos <  64 - totBits; current_pos++){
    complete[current_pos] = 0;
  }
}

/*
// check for padding
printf("\n");
for(int i =0; i < 32; i++){
  printf("%d", complete[i]);
}*/


//ASSIGNMENT OF SIGN
complete[current_pos] = sign;
current_pos++;


//Exponent adding to complete array
for(int j = 0; j < expBits; j++){
  complete[current_pos] = exp[j];
  current_pos++;
}

//getting the size of the mantisa
int mantisaSize = totBits - expBits -1;
int mantisa[mantisaSize];
int mantisaCount = 0;
printf("\nMANTISA SIZE: %d\n", mantisaSize);


int fracPos = 0;
//printf("%dCHECKPOINT\n", checkPoint );

//Mantisa filling
//if 63 then that means its at the end of the array and it will not incorporate last position or it never found anythin. adds just the fraction
if(checkPoint == 63 || checkPoint == -1){ //figure out
  for(int i = 0; i < mantisaSize; i++)
  { //FRACTION ARRAY STARTS IN  MANTISA
    mantisa[i] = frac[fracPos];
    //printf("%d FRACTION BIT --> %d\n",frac[fracPos], i);
    fracPos++;
  }
}
else{
  for(int i = checkPoint+1; i < 64; i++)
  {
    if(mantisaCount <  mantisaSize){
      //fill up the mantisa after the "." from the integral part
      mantisa[mantisaCount] = bin[i];
      mantisaCount++;
    }
    else break;// break to avoid unnecessary looping
  }
  for(int i = mantisaCount; i < mantisaSize; i++)
  { //fills up the frac part to the mantisa
    mantisa[i] = frac[fracPos];
    //printf("%d",mantisa[mantisaCount]);
    fracPos++;
  }
}

//adding the mantisa to the final array
mantisaCount = 0;
for(int i = current_pos; i < 64; i++){
  complete[i] = mantisa[mantisaCount];
  mantisaCount++;
}


printf("\nFINAL BINARY REPRESENTATION: ");
for(int i =0; i < 64; i++){
  printf("%d", complete[i]);
}

/*
for(int i = 0; i < expBits; i++)
{
  printf("%d",exp[i]);
}*/


floatx binary = 0;
int tracker = 0;
for(int i = 64; i >= 0; i--){
  floatx mask = complete[i];
  mask = mask << (tracker-1);
  binary |= mask;
  tracker++;

}
return binary;

}

void binaryToString(double Integral, int bin[], double check, int limit){

//printf("FROM FUNCTION: %f\n", Integral);
//printf("%f\n", check );
for(int i = 0; i < limit; i++)
{
  if(Integral >= check){
    bin[i] = 1;
    Integral = Integral - check;

  }
  else{
    bin[i] = 0;
  }
  //printf("%d", bin[i] );

  check = check/2;
}

}
