#include <ctime>
#include <iostream>
#include <stdio.h>
#include<fstream>
using namespace std;
/* The recursive implementation of LCS (program 2)
* No additional files needed, just this main file along with its functions
* all functions are defined below with explanations on what they each do.
*/
string Input(string file);
int recursive_LCS(string filex, string filey, int i, int j);
void writeOutput(string fileOut, int LCS_RESULT, float time);

/* Recieves the arguments from the cmd and calls functions to parse, compute LCS, and write output to a file
 * error checking is made for the arguments but it is expected to recieve two input files and an output files
 */
int main (int argc, char *argv[])
{
  if(argc !=4){
    cout << "Invalid input. Please ensure correct format 'prompt> program2 <filex.txt> <filey.txt> <output1.txt>'" << endl;
    return -1;
 }
 string filex = Input(argv[1]);  //first file input
 string filey = Input(argv[2]);  //second file input
 string fileOut = argv[3];       //where the file will be written to
 clock_t start_Time, end_Time;   //the start and end time after LCS has been computed
 start_Time = clock();  //time before starting function
 int LCS_RESULT = recursive_LCS(filex, filey, filex.length()-1, filey.length()-1);
 end_Time = clock();  //time after ending functions
 writeOutput(fileOut, LCS_RESULT, float((float)end_Time - (float)start_Time)/CLOCKS_PER_SEC);
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
/* Recurses the non empty strings filex and filey
* checks for matches otherwise (i-1, j) and (i. j-1) indeces are checked
* returns the length of LCS_RESULT
*/
int recursive_LCS(string filex, string filey, int i, int j)
{
  if(i < 0  || j < 0) return 0;
  else if (filex[i] == filey[j]) return recursive_LCS(filex, filey, i-1, j-1) + 1;
  else return std::max(recursive_LCS(filex, filey, i-1, j), recursive_LCS(filex, filey, i, j-1));
}

/* Writes the output to the file specified
 * fileOut is the file to write to
 * start_Time and end_Time is the time before the function started and after the function ended
 * simply writes to desired file. LCS_RESULT will return some int and float time will be non zero.
 */
void writeOutput(string fileOut, int LCS_RESULT, float time){
  ofstream output(fileOut);
  if(!output.is_open()){
    cout << "Cannot create output file" << endl;
    exit(-1);
  }
  else if(output.is_open())
  {
    output << LCS_RESULT << endl;
    output << time << "sec";
    output.close();
  }
}
