/* Bottom up implementation of the LCS problem. (program 1)
 * This program only uses main and a few function (no additional files)
 * all functions have a description on what they do down below vvvvvvv
 */
#include <ctime>
#include <iostream>
#include <stdio.h>
#include<fstream>
using namespace std;
//this will be the values to store in b_table for the direction of array
#define DIAG (1)
#define UP (2)
#define LEFT (3)

//will read Input and return the string read.
string Input(string file);
int LCS(string filex, string filey, int m, int n, int** C_TABLE, int** B_TABLE);
void writeOutput(int ** C_TABLE, int ** B_TABLE, string fileOut, string filex, string filey, clock_t start_Time, clock_t end_Time, int LCS_RESULT);

/* Recieves the arguments from the cmd and calls functions to parse, compute LCS, and write output to a file
 * error checking is made for the arguments but it is expected to recieve two input files and an output files
 */
int main (int argc, char *argv[])
{
  if(argc !=4){
    cout << "Invalid input. Please ensure correct format 'prompt> program1 <filex.txt> <filey.txt> <output1.txt>'" << endl;
    return -1;
 }
  string filex = Input(argv[1]);  //first file input
  string filey = Input(argv[2]);  //second file input
  string fileOut = argv[3];       //where the file will be written to
  clock_t start_Time, end_Time;   //the start and end time after LCS has been computed
  int ** C_TABLE = new int*[filex.length()+1];  //the array for the values
  int ** B_TABLE = new int *[filey.length()+1]; //direction of where to go in array

  //initializing arrays
  for (unsigned int row = 0; row < filex.length() +1; row++){
    C_TABLE[row] = new int [filey.length()+1];
    B_TABLE[row] = new int [filey.length()+1];

  }
  for(unsigned int row = 0; row < filex.length()+1; row++){
    C_TABLE[row][0] = 0;
    B_TABLE[row][0] = 0;
  }
  for(unsigned int col = 0; col< filey.length()+1; col++){
    C_TABLE[0][col] = 0;
    B_TABLE[0][col] = 0;
  }
  start_Time = clock();
  int LCS_RESULT = LCS(filex, filey, filex.length()+1, filey.length()+1, C_TABLE, B_TABLE );
  end_Time = clock();
  writeOutput(C_TABLE, B_TABLE, fileOut, filex, filey, start_Time, end_Time, LCS_RESULT);

  //taking care of memory leaks
  for(unsigned int row = 0; row < filex.length() + 1; row++)
  {
    delete[] C_TABLE[row];
    delete[] B_TABLE[row];
  }
  delete[] C_TABLE;
  delete[] B_TABLE;
  return 0;
}

/* Simply Reads a string and searches for file and returns content
 * file is the name of the file to open
 * in is the return of the contents in filex
*/
string Input(string file){
  string in = "";
  ifstream fileRead(file);
  fileRead >> in;
  return in;
}

/* Determines the LCS for inputs x and y
 * filex and filey are the strings contained within the files passed in..(non empty)
 * m & n are the lengths of each string respectively
 * C_TAble and B_Table are the arrays for the LCS with m x n size
 * returns the length of LCS
 */
int LCS(string filex, string filey, int m, int n, int** C_TABLE, int** B_TABLE){
  for (int i = 1; i < m; i++){
    for (int j = 1; j < n; j++){
      if (filex[i-1] == filey[j-1]) //if the char inputs match then store them in table
      {
        C_TABLE[i][j] = C_TABLE[i-1][j-1] + 1;
        B_TABLE[i][j] = DIAG;
      }
      else if (C_TABLE[i-1][j] >= C_TABLE[i][j-1])
      {
        C_TABLE[i][j] = C_TABLE[i-1][j];
        B_TABLE[i][j] = UP;
      }
      else{
        C_TABLE[i][j] = C_TABLE[i][j-1];
        B_TABLE[i][j] = LEFT;
      }
    }
  }
  return C_TABLE[m-1][n-1];
}

/* Writes the output to the file specified
 * C_TABLE and B_TABLE contains the values for our LCS and directions to choose correct characters.
 * fileOut is the file to write to
 * filex and filey are the strings contained in the given files
 * start_Time and end_Time is the time before the function started and after the function ended
 * function will write to output in regards of the size of the input strings. If less than 10, then writes to output file the matrix along with the LCS and end_Time
 * if greater than 10, then it will only write the time and length of longest common sequence.
 */
void writeOutput(int ** C_TABLE, int ** B_TABLE, string fileOut, string filex, string filey, clock_t start_Time, clock_t end_Time, int LCS_RESULT)
{
  ofstream output(fileOut);
  if(!output.is_open()){
    cout << "Cannot create output file" << endl;
    exit(-1);
  }
  //if less than or equal to 10
  if(filex.length() <= 10 && filey.length()<= 10)
  {
    for(unsigned int row = 0; row < filex.length() + 1; row++){
      for(unsigned int col = 0; col < filey.length() +1; col++){
        output << C_TABLE[row][col]<< " ";  //contents of C_TABLE onto file
      }
      output << endl; //next line formatting
    }
    //navigating through values and choosing correct subsequence
    int row = filex.length();
    int col = filey.length();
    string subsequence = "";
    while(row > 0 && col > 0)
    {
      if(B_TABLE[row][col] == DIAG){
        subsequence = filex[row-1] + subsequence;
        row--;
        col--;
      }
      else if(B_TABLE[row][col] == UP) row--;
      else if (B_TABLE[row][col] == LEFT) col--;
    }
    output << subsequence << endl;
  }
  //greater than 10
  else  output << LCS_RESULT << endl;

  output << float((float)end_Time - (float)start_Time)/CLOCKS_PER_SEC << " sec";
  output.close();
}
