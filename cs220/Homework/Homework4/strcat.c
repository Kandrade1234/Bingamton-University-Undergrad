
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * strcatm(char [], char[]);
char * strcatp(char *, char*);
int main(int argc, char **argv){

    if(argv[1] == NULL || argv[2] == NULL){
        printf("MUST ENTER TWO STRINGS\n");
        return 1;
    }
	char array_version[254];
	char pointer_version[254];



	strcpy(array_version, argv[1]);
	strcatm(array_version, argv[2]);

	printf("strcat matrix form yields: %s\n", array_version);
	strcpy(pointer_version, argv[1]);

	strcatp(pointer_version, argv[2]);
	printf("strcat pointer form yields: %s\n", pointer_version);


return 0;


}
char * strcatp(char * input1, char * input2){
	int  i =0;
	while((*input1)!='\0'){
		i++;
		input1++;
	}

for(int x =0;(*input2)!='\0'; x ++){
	*(input1++) = *(input2++);
}

*(input1) = '\0';
	return (char*)input1;
}


char * strcatm(char input1 [],char input2 []){
	int length1 = 0;
	for(int i =0; input1[i]!= '\0'; i++)
	{
		length1++;
	}
	
	int length2 = 0;
	for(int i =0; input2[i]!= '\0'; i++)
		{
			length2++;
		}


	for(int i =0; i < length2; i++){
		input1[length1++] = input2[i];
	}
	input1[length1+length2] = '\0';

	return (char*)input1;
}
