#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include<unistd.h>
#include <signal.h>
typedef void (*sighandler_t)(int);
sighandler_t signal (int signum, sighandler_t handler);
void my_signal_handler(int);
int sgnal =0;
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
	printf("shell> ");
  pid_t cpid[6] = {0};
  int fd[4];
  char * semiCol =";";
  char * pipeSymb = "|";
  char * bgExec = "&";
  char * lessThan = "<";
  char * greaterThan = ">";
  pid_t pidBgHold= 0;
  char * partition [256];
  char * pipePars1[256];
  char * pipePars2[256];
  char * pipePars3[256];
  char * redirParsin[256];
  char * redirPars[256];

  int inPipe = 0;
  int pipePOS1 = 0;
  int pipePOS2 = 0;
  bool pipef = false;
  bool redirInput= false;
	bool redirOutput = false;
  int currOutputPOS = 0;
  setbuf(stdout,NULL);
  if(signal(SIGINT, my_signal_handler) == SIG_ERR)
    printf("Error catching signal");


  fgets(input, sizeof(input), stdin);

while(strcmp("exit\n" ,input) != 0 && ((int)strlen(input) >= 2)){
  if(signal(SIGINT, my_signal_handler) == SIG_ERR)
    printf("Error catching signal");
	firstParse(parsed, input, delimit, &i);


	int count = 0;
	int inputFileIndexTracker[100];
	int outputFileIndexTracker[100];
	int inputFileCount = 0;
	int outputFileCount = 0;
	bool newcomand2 = false;
  bool prevComand = false;
  bool bgExecF = false;
  int startNewPOS = 0;
  int status;
	//SECOND PASS.....//
  int j;
  for( j = 0; j < i; j++)
	{
		bool newComand = semiColonParser(parsed, &j);													//WILL only excecute if there is a semicolon

		if(count == 0){	//if count "resets" it means it is a comand
      // printf("COMMAND: %s", parsed[j]);  //first is always command
			 count++;
     }
    else {	//rest of the arguments
			if(parsed[j]!= NULL){	//making sure we have a valid input in array
				if((strchr(parsed[j], '|' )!= NULL)){	//IF PIPE FOUND EXECUTE FOLLOWING ALGORITHM
					if(strcmp(pipeSymb, parsed[j]) == 0)	//IF FORMATTING IS CORRECT AND PIPE IS FOUND THEN (i.e: cat sample | grep -v a) then simply print
					  {
  						if(redirInput) checkRedInput(&redirInput, parsed, inputFileIndexTracker[inputFileCount]);
  					 	if(redirOutput) checkRedOutput(&redirOutput, parsed, outputFileIndexTracker[outputFileCount]);
  						//printf("\n... output of the above command will be redrecited to serve as the input of the following command ...\n");
  						count = 0;	//resets the count
              pipef = true;
              int d = 0;          //Parsing 1st part of pipe
              if(inPipe == 0)
              {
                for( d = 0; d < j; d++){
                  pipePars1[d] = parsed[d];
                  //printf("%s\n\n", pipePars1[d]);
                }
                pipePars1[d] = 0;
                inPipe += 1;
                pipePOS1 = j + 1;
                if(pipe(fd) < 0 ){
                  fprintf(stderr, "pipe() failed: %s\n", strerror(errno));
                  return 0;
                }
             }
             else if(inPipe == 1){
              inPipe += 1;
              pipePOS2 = j + 1;
              //printf("PIPEPOS2: %d", pipePOS2);
              //printf("%s", parsed[pipePOS2]);
               if(pipe(fd + 2) < 0 ){
                 fprintf(stderr, "pipe() failed: %s\n", strerror(errno));
                 return 0;
               }
             }

					 }
					else if(strcmp(&parsed[j][strlen(parsed[j])-1], pipeSymb) == 0){	//IF FORMATTING IS INCORRECT (i.e: cat sample| grep -v a)..pipe attached to sample
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
            if(redirInput)
            {
              currOutputPOS = j;
            }
						redirOutput = true;
						outputFileIndexTracker[outputFileCount] = j;
						//if(j == i-1) //if at the end
							//printf("\n... output of the above command will be redirected from file \"%s\"." , parsed[outputFileIndexTracker[outputFileCount]]);

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
					//	printf("\n... the above command will be executed in background.");
						count = 0;
            bgExecF = true;
            parsed[j] = 0;
					}
					else{
						parsed[j] = strtok(parsed[j], "&");
						printf(", arg-%d: %s", count , parsed[j]);																				//fixing misformating issues
						printf("\n... the above command will be executed in background.");
						count = 0;
					}
				}
				else{
					// printf(", arg-%d: %s", count , parsed[j]);																				//will print remaining arguments
					 if(redirInput && j == i-1) printf("\n... input of the above command will be redirected from file \"%s\"." , parsed[inputFileIndexTracker[inputFileCount]]);	//will only execute if at the end and we had a previous redirection (i.e: “wc -l < prog1.c -c)
					 if(redirOutput && j == i-1) printf("\n... output of the above command will be redirected from file \"%s\"." , parsed[outputFileIndexTracker[outputFileCount]]);
				 	++count;	//the count of arguments
			}
    }


    if(newComand == true)										//if there was a semicolon previously and newComand flag was turned on then it will print two new lines and reset count to 0
    {
      newcomand2 = true;
      prevComand = true;
      startNewPOS = j;
      printf("\n\n");
      count = 0;
		  newComand = false;
			redirOutput = false;
			redirInput = false;
    }

	}
  if((newcomand2 && !pipef && !redirOutput && !redirInput) || ((j+1 == i) && !pipef && !redirOutput && !redirInput))    //Will only execute single or multiple basic comands excluding pipelining or comand redirection
  {
    cpid[0] = fork();
    sgnal = 1;
    if(cpid[0] < 0){
      fprintf(stderr, "fork failed: %s\n", strerror(errno));
      return 0;
    }
    else if(0 == cpid[0]) {    //IN CHILD - 1
      //printf("\n\n>>>IN CHILD: pid=%d\n", getpid());
      //   EXECUTES everything up to first semicoln
/*previus else if*/ if(newcomand2 && j+1 != i){
        int z;
        //  Copying Everything up until the semicolon
        for( z = 0; z <= j; z++){
          partition[z] = parsed[z];
        }
        partition [z] = 0;
      /*  for ( int w = 0; w < j; w++){
          printf("\t %s \t ", partition [w]);
        }
        printf("ENDDDDD");*/
        if(execvp(partition[0], &partition[0]) < 0) //Error Checking / Executing first part
        {
          fprintf(stderr, "Cannot Execute \"%s\" : %s\n", parsed[0], strerror(errno));
          exit(-1);
        }
        exit(0);      //exits process
      }
      //  EXECUTING the NEW COMAND after semicolon
      else if(prevComand && j+1 == i){      //Comand after the semi semicolon && veryfying there was a prev comand
        if(startNewPOS == j && j+1 == i){   //if there is only one semi colon but nothing else after
          if(execvp(parsed[0],&parsed[0]) < 0){
            fprintf(stderr, "Cannot Execute \"%s\" : %s\n", parsed[0], strerror(errno));
            exit(-1);
          }
          exit(0);
        }
        int curr = 0;
          //Copying Everything from new comand
        for(int g = startNewPOS+1; g <= j; g++){
          partition[curr] = parsed[g];
          curr++;
        }
        partition[curr] = 0;
          /*for ( int w = 0; w < curr; w++){
            printf("\t %s \t ", partition [w]);
          }
          printf("ENDDDDD");*/
    if(execvp(partition[0], &partition[0]) < 0)   //execution of second comand / error Checking
      {
        fprintf(stderr, "Cannot Execute \"%s\" : %s\n", parsed[0], strerror(errno));
        exit(-1);
      }
     exit(0);
    }
    else                //No semi colons, just a simple comand
    {
      //CHECK IF PIPED PREVIOUSLY SO WE CAN REDIRECT ACCORDINGLY
      if(bgExecF) pidBgHold = cpid[0];
      if(execvp(parsed[0],&parsed[0]) < 0)
      {
        fprintf(stderr, "Cannot Execute \"%s\" : %s\n", parsed[0], strerror(errno));
        exit(-1);
      }
      exit(0);
    }

  }
   if(!bgExecF)        //parent
      {
        int ret = waitpid (cpid[0], NULL, 0);
        if(ret < 0)
        {
          fprintf(stderr, "wait failed: %s\n", strerror(errno));
        }
        else
        {
           printf("\n... child process (PID=%d) is waited/reaped\n", cpid[0]);
           newcomand2 = false;
           sgnal = 0;
        }
    }

  }
} //end of for loop
/*
for(int x = 0; x <i; x++){
  printf("\n%s\n", parsed[x]);
}
*/
int retBg = waitpid(pidBgHold, &status, WNOHANG); //checking to see if bg execution (child) has returned
if (retBg > 0)
  printf("\n... child process (PID=%d) is waited/reaped", retBg); //reap


if(pipef)
{
  if((cpid[0] = fork())== 0)
  {
        if(inPipe >= 1){

    //  pipePars1 will contain everything up till the pipe
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        if(inPipe == 2){
          close(fd[2]);
          close(fd[3]);
        }
        if(execvp(pipePars1[0], &pipePars1[0]) < 0){
          fprintf(stderr, "Cannot Execute \"%s\" : %s\n", parsed[0], strerror(errno));
          exit(-1);
        }
      }
  }
  else if (cpid[0] < 0)
  {
    fprintf(stderr, "fork failed: %s\n", strerror(errno));
    return 0;
  }
  else
  {
    if((cpid[1] = fork()) == 0)
    {
      if(inPipe >= 1)
      {
        if(0 ==cpid[1])  //CHILD - 2
        {
           if (inPipe >= 1)
          {
            //copy the second half of pipe arguments.
             int c;
             int currPipe = 0;
             if(inPipe == 1)
             {
               for(c = pipePOS1; c <= j; c++)
               {
                 pipePars2[currPipe] = parsed[c];
                //printf("%s\n\n", pipePars2[currPipe]);
                 currPipe++;
               }
             }
            if(inPipe == 2)
            {
              for(c = pipePOS1; c < pipePOS2 -1; c++)
              {
                pipePars2[currPipe] = parsed[c];
                currPipe++;
              }
            }

            pipePars2[currPipe] = 0;
            dup2(fd[0], STDIN_FILENO);
            if(inPipe == 2) dup2(fd[3], STDOUT_FILENO);
            close(fd[0]);
            close(fd[1]);
            if(inPipe == 2){
              close(fd[2]);
              close(fd[3]);
            }
            if(execvp(pipePars2[0], &pipePars2[0]) < 0)
            {
              fprintf(stderr, "Cannot Execute \"%s\" : %s\n", pipePars2[0], strerror(errno));
              exit(-1);
            }
            //pipef = true;
          }
        }
      }
   }
  else if(cpid[1] < 0)
  {
    fprintf(stderr, "fork failed: %s\n", strerror(errno));
    return 0;
  }
  else
  {
     if(inPipe == 2)
     {
      if((cpid[2] = fork()) == 0)
      {
        if(inPipe == 2)               //CHILD - 3
        {
          //copy third set of arguments into array
          int w;
          int currPipe2 = 0;
          //printf("LOOOK: %d", j);
          for(int b = pipePOS2; b < j; b++){
            pipePars3[currPipe2] = parsed[b];
            //printf("%s\n", pipePars3[currPipe2]);
            currPipe2++;
          }
          pipePars3[currPipe2] = 0;
          dup2(fd[2], STDIN_FILENO);

          close(fd[0]);
          close(fd[1]);
          close(fd[2]);
          close(fd[3]);

          if(execvp(pipePars3[0], &pipePars3[0]) < 0)
          {
            fprintf(stderr, "Cannot Execute \"%s\" : %s\n", pipePars3[0], strerror(errno));
            exit(-1);
          }
        }
      }
      else if(cpid[2] < 0)
      {
        fprintf(stderr, "fork failed: %s\n", strerror(errno));
        return 0;
      }
    }
  }


}

// PARENT
 close(fd[0]);
 close(fd[1]);
 if(inPipe == 2)
 {
   close(fd[2]);
   close(fd[3]);

   for(int i = 0; i < 3; i++)
   {
     int ret = wait(&status);
     if (ret > 0)  printf("\n... child process (PID=%d) is waited/reaped\n", ret); //reap
   }
 }
 else{
   for(int i =0; i < 2; i++){
     int ret = wait(&status);
     if (ret > 0)  printf("\n... child process (PID=%d) is waited/reaped\n", ret); //reap
   }
 }

}
////////////////////////////////REDIRECTION INPUT and OUTPUT///////////////////////
if(redirInput && redirOutput){
  cpid[5] = fork();
  if(cpid[5] < 0){
    fprintf(stderr, "fork() failed: %s\n", strerror(errno));
    return 0;
  }
  else if(0 == cpid[5])    //CHILD
  {
    int in, out;
    int x =0;
    for(x = 0; x < inputFileIndexTracker[inputFileCount] -1; x++)
      redirParsin[x] = parsed[x];
    redirParsin[x] = 0;

    in = open(parsed[inputFileIndexTracker[inputFileCount]], O_RDONLY);
    out = open(parsed[j-1], O_WRONLY |  O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);

    //replacing standard input
    dup2(in, 0);

    //replacing standard output
    dup2(out, 1);

    close(in);
    close(out);

    if(execvp(redirParsin[0], &redirParsin[0]) < 0){
      fprintf(stderr, "Cannot Execute \"%s\" : %s\n", redirParsin[0], strerror(errno));
      exit(-1);
    }
  }
  //PARENT
  int ret = waitpid (cpid[5], NULL, 0);
  if(ret < 0)
  {
    fprintf(stderr, "wait failed: %s\n", strerror(errno));
  }
  else
    printf("\n... child process (PID=%d) is waited/reaped\n", cpid[5]);
}

////////////////////////////////REDIRECTION INPUT ONLY///////////////////////
if(redirInput && !redirOutput){
  cpid[4] = fork();
  if(cpid[4] < 0){
    fprintf(stderr, "fork() failed: %s\n", strerror(errno));
    return 0;
  }

  else if( 0 == cpid [4]){
    int in;
    int x =0;
    for(x = 0; x < inputFileIndexTracker[inputFileCount] -1; x++)
      redirParsin[x] = parsed[x];

    redirParsin[x] = 0;

    in  = open(parsed[inputFileIndexTracker[inputFileCount]], O_RDONLY);
    dup2(in, 0);
    close(in);
    if(execvp(redirParsin[0], &redirParsin[0])< 0){
      fprintf(stderr, "Cannot Execute \"%s\" : %s\n", redirParsin[0], strerror(errno));
      exit(-1);
    }
  }
  //PARENT
  int ret = waitpid (cpid[4], NULL, 0);
  if(ret < 0)
  {
    fprintf(stderr, "wait failed: %s\n", strerror(errno));
  }
  else
    printf("\n... child process (PID=%d) is waited/reaped\n", cpid[4]);
}
//////////////////////////////////end//////////////////////////////////////////

///////////////////////////REDIRECTION OUTPUT ONLY///////////////////////////
if(redirOutput && !redirInput){
  cpid[3] = fork();
  if(cpid[3]  < 0){
    fprintf(stderr, "fork() failed: %s\n", strerror(errno));
    return 0;
  }
else if( 0 == cpid[3]){ //CHILD
  int out;
  int limit = outputFileIndexTracker[outputFileCount] -1;
  int currR = 0;
  int y = 0;
  //elements 0 through >
  for(y = 0; y < outputFileIndexTracker[outputFileCount]-1; y++){
    redirPars[y] = parsed[y];
  }
  redirPars[y] = 0;
    out = open(parsed[j-1], O_WRONLY |  O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);

  dup2(out,1);
  close(out);
  if(execvp(redirPars[0], &redirPars[0])< 0){
    fprintf(stderr, "Cannot Execute \"%s\" : %s\n", redirPars[0], strerror(errno));
    exit(-1);
  }
}

  //PARENT
  int ret = waitpid (cpid[3], NULL, 0);
  if(ret < 0)
  {
    fprintf(stderr, "wait failed: %s\n", strerror(errno));
  }
  else
    printf("\n... child process (PID=%d) is waited/reaped\n", cpid[3]);
}
////////////////////////////end/////////////////////////////////////////////////

    if(signal(SIGINT, my_signal_handler) == SIG_ERR)
      printf("Error catching signal");


	i = 0;
  memset(partition, 0, sizeof(partition));
  memset(pipePars1, 0 , sizeof(pipePars1));
  memset(pipePars2, 0 , sizeof(pipePars2));
  memset(pipePars2, 0 , sizeof(pipePars3));
  memset(redirParsin, 0, sizeof(redirParsin));
  memset(redirPars, 0, sizeof(redirPars));
  memset(parsed,0, sizeof(parsed));
  memset(input,0, sizeof(input));
  pipef = false;
  inPipe = 0;
  bgExecF = false;
  redirInput= false;
  redirOutput = false;
	redirOutput = false;
	redirInput = false;
	printf("\n");
	printf("shell> ");
  fgets(input, sizeof(input), stdin);
}


	return 0;
}
void my_signal_handler(int sig){
  if(sgnal == 1){
    signal(sig, SIG_IGN);
     kill(getpid(), sig);
     //sgnal =0
  }
  else{
      printf("\nCtrl-C catched. But currently there is no foreground process running.\n");
      printf("shell> ");
    }
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
		//if(*j == i-1) printf("\n... input of the above command will be redirected from file \"%s\"." , parsed[inputFileIndexTracker[*inputFileCount]]); //if at the end just simply print
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
