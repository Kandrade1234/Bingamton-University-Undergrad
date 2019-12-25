#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void checkRedInput(bool *redirInput, char ** parsed , int );
void checkRedOutput(bool *redirOutput, char ** parsed , int);
void firstParse(char ** parsed, char * input, char * delimit, int *index);
bool semiColonParser(char ** parser, int * index);
void inputRedir(char ** parsed, char * lessThan, int *j, int i, bool *redirInput, int * inputFileIndexTracker, int * inputFileCount, int count);
int main(void)
{
	char input[255];
	char delimit[] = " \n\t";
	char* parsed[256];
	int i = 0;
	printf("cs-350-prog1> ");
  fgets(input, sizeof(input), stdin);

while(strcmp("exit\n" ,input) != 0 && ((int)strlen(input) >= 2)){
	firstParse(parsed, input, delimit, &i);
	char * semiCol =";";
	char * pipe = "|";
	char * bgExec = "&";
	char * lessThan = "<";
	char * greaterThan = ">";
	bool redirInput= false;
	bool redirOutput = false;
	int count = 0;
	int inputFileIndexTracker[100];
	int outputFileIndexTracker[100];
	int inputFileCount = 0;
	int outputFileCount = 0;
	bool tempnewComand;
	//SECOND PASS.....//
  for(int j = 0; j < i; j++)
	  {
		bool newComand = semiColonParser(parsed, &j);													//WILL only excecute if there is a semicolon

		if(count == 0){	//if count "resets" it means it is a comand
       printf("COMMAND: %s", parsed[j]);  //first is always command
			 count++;
     }
    else {	//rest of the arguments
			if(parsed[j]!= NULL){	//making sure we have a valid input in array
				if((strchr(parsed[j], '|' )!= NULL)){	//IF PIPE FOUND EXECUTE FOLLOWING ALGORITHM
					if(strcmp(pipe, parsed[j]) == 0)	//IF FORMATTING IS CORRECT AND PIPE IS FOUND THEN (i.e: cat sample | grep -v a) then simply print
					  {
						if(redirInput) checkRedInput(&redirInput, parsed, inputFileIndexTracker[inputFileCount]);
					 	if(redirOutput) checkRedOutput(&redirOutput, parsed, outputFileIndexTracker[outputFileCount]);
						printf("\n... output of the above command will be redrecited to serve as the input of the following command ...\n");
						count = 0;	//resets the count
					  }
					else if(strcmp(&parsed[j][strlen(parsed[j])-1], pipe) == 0){	//IF FORMATTING IS INCORRECT (i.e: cat sample| grep -v a)..pipe attached to sample
					    if(redirInput) checkRedInput(&redirInput, parsed, inputFileIndexTracker[inputFileCount]);
					   	if(redirOutput) checkRedOutput(&redirOutput, parsed, outputFileIndexTracker[outputFileCount]);
							parsed[j] = strtok (parsed[j], "|");		//gets rid of pipe and store it back into parsed array
							printf(", arg-%d: %s", count , parsed[j]);	//prints the argument without the pipe (i.e sample instead of sample|)
							printf("\n... output of the above command will be redrecited to serve as the input of the following command ...\n");
							count = 0;
						}
						else{	//IF FORMATTING IS INCORRECT (i.e: cat sample |grep -v a).....pipe attached to start of grep.
							if(redirInput ) checkRedInput(&redirInput, parsed, inputFileIndexTracker[inputFileCount]);
						 	if(redirOutput) checkRedOutput(&redirOutput, parsed, outputFileIndexTracker[outputFileCount]);
							parsed[j] = strtok (parsed[j], "|");
							printf("\n... output of the above command will be redrecited to serve as the input of the following command ...\n");
							printf(", arg-%d: %s", count , parsed[j]);
							count = 0;
						}
				}
				else if (strchr(parsed[j], '<' )!= NULL){													//looks for input redirector.
					inputRedir(parsed, lessThan, &j, i, &redirInput, inputFileIndexTracker, &inputFileCount, count);
				}
				else if (strchr(parsed[j], '>' ) != NULL){				//output operator....same steps as input
			 		if (strcmp(greaterThan, parsed[j]) == 0){
						j++;
						redirOutput = true;
						outputFileIndexTracker[outputFileCount] = j;
						if(j == i-1) //if at the end
							printf("\n... output of the above command will be redirected from file \"%s\"." , parsed[outputFileIndexTracker[outputFileCount]]);

					}
					else if(strcmp(&parsed[j][strlen(parsed[j])-1], greaterThan) == 0)	//IF FORMATTING IS INCORRECT (i.e: cat sample| grep -v a)..pipe attached to sample
					{
						parsed[j] = strtok(parsed[j], ">");
						redirOutput = true;
						printf(", arg-%d: %s", count , parsed[j]);	//prints the argument without the pipe (i.e sample instead of sample|)
						j++;
						outputFileIndexTracker[outputFileCount] = j;
						if (j == i-1)
							printf("\n... output of the above command will be redirected from file \"%s\"." , parsed[j]);
					}
					else{
						parsed[j] = strtok(parsed[j], ">");
						redirOutput = true;
						outputFileIndexTracker[outputFileCount] = j;
						if(j == i-1)
							printf("\n... output of the above command will be redirected from file \"%s\"." , parsed[j]);
					}

				}
				else if(strchr(parsed[j], '&')!= NULL){
					if(redirInput) checkRedInput(&redirInput, parsed, inputFileIndexTracker[inputFileCount]);
					if(redirOutput) checkRedOutput(&redirOutput, parsed, outputFileIndexTracker[outputFileCount]);
					if(strcmp(bgExec, parsed[j]) == 0){
						printf("\n... the above command will be executed in background.");
						count = 0;
					}
					else{
						parsed[j] = strtok(parsed[j], "&");
						printf(", arg-%d: %s", count , parsed[j]);																				//fixing misformating issues
						printf("\n... the above command will be executed in background.");
						count = 0;
					}
				}
				else{
					 printf(", arg-%d: %s", count , parsed[j]);																				//will print remaining arguments
					 if(redirInput && j == i-1) printf("\n... input of the above command will be redirected from file \"%s\"." , parsed[inputFileIndexTracker[inputFileCount]]);	//will only execute if at the end and we had a previous redirection (i.e: “wc -l < prog1.c -c)
					 if(redirOutput && j == i-1) printf("\n... output of the above command will be redirected from file \"%s\"." , parsed[outputFileIndexTracker[outputFileCount]]);
				 	++count;	//the count of arguments
			}
    }
		if(newComand == true)										//if there was a semicolon previously and newComand flag was turned on then it will print two new lines and reset count to 0
    {
      printf("\n\n\n");
      count = 0;
		  newComand = false;
			redirOutput = false;
			redirInput = false;
    }
	}
}

	i = 0;
  memset(parsed,0, sizeof(parsed));
  memset(input,0, sizeof(input));
	redirOutput = false;
	redirInput = false;
	printf("\n");
	printf("cs-350-prog1> ");
  fgets(input, sizeof(input), stdin);
}


	return 0;
}

void firstParse(char ** parsed, char * input, char * delimit, int *i)
{
	parsed[*i] = strtok(input, delimit); //gets rid of any spaces or \t
	//FIRST PASS...//
	while(parsed[*i]!= NULL){	//Will loop through remaining string and place a \0 at every 	newline and space
	  (*i)++;
	  parsed[*i] = strtok(NULL, delimit);	//getting rid of spaces and newlines
	}
}
bool semiColonParser(char ** parsed, int * j){
	char* position = strchr(parsed[*j], ';');	//will look for a semicolon
	if(position!= NULL)	//if stchr finds a semicolon then it will not return null
	{
			parsed[*j] = strtok(parsed[*j], ";");
			return true;
	}
	return false;
}
void inputRedir(char ** parsed, char * lessThan, int *j, int i, bool *redirInput, int * inputFileIndexTracker, int * inputFileCount, int count){
	if (strcmp(lessThan, parsed[*j]) == 0){												//if formating is correct
		(*j)++;	//skips over current index
		*redirInput = true;																					//sets the flag to true so we know we had a <
		inputFileIndexTracker[*inputFileCount] = *j;									//stores current index....in the future i will have it store multiple indexes for multiple redirection operators....for now just one of a kind.
		if(*j == i-1) printf("\n... input of the above command will be redirected from file \"%s\"." , parsed[inputFileIndexTracker[*inputFileCount]]); //if at the end just simply print
	}
	else if(strcmp(&parsed[*j][strlen(parsed[*j])-1], lessThan) == 0)	//IF FORMATTING IS INCORRECT (i.e: cat sample< grep -v a)..input redirector attached to sample
	{																														//misformated input
		parsed[*j] = strtok(parsed[*j], "<");
		*redirInput = true;
		printf(", arg-%d: %s", count , parsed[*j]);										//prints the argument without <
		(*j)++;
		inputFileIndexTracker[*inputFileCount] = *j;
		if(*j == i-1)
			printf("\n... input of the above command will be redirected from file \"%s\"." , parsed[*j]);
	}
	else{
		parsed[*j] = strtok(parsed[*j], "<");
		*redirInput = true;
		inputFileIndexTracker[*inputFileCount] = *j;
		if(*j == i-1)
			printf("\n... input of the above command will be redirected from file \"%s\"." , parsed[*j]);
	}
}
void checkRedInput(bool *redirInput, char **  parsed, int index){
		 printf("\n... input of the above command will be redirected from file \"%s\"." , parsed[index]);
		 *redirInput = false;
}
void checkRedOutput(bool *redirOutput, char **  parsed, int index){
		printf("\n... output of the above command will be redirected from file \"%s\"." , parsed[index]);
    *redirOutput= false;

}
