#include <ctime>
#include <iostream>
#include <stdio.h>
#include<fstream>
#include <vector>
using namespace std;

#define DIAG 1
#define UP 2
#define LEFT 3

string fileX;
string fileY;
string output;
int xLength;
int yLength;
string readInput(string file){
  string in = "";
  ifstream fileRead(file);
  fileRead >> in;
  return in;
}
void initialize(vector<vector<int> > &table, vector<vector<int> > &dirTable){
  /*INITIALIZING*/
  for(unsigned int row = 0; row < xLength; row++){
    table[row][0] = 0;
    dirTable[row][0] = 0;
  }
  for(unsigned int col = 0; col< yLength; col++){
    table[0][col] = 0;
    dirTable[0][col] = 0;
  }
}

int LCS_RESULT(vector<vector<int> > &table, vector<vector<int> > &dirTable){
  for (int i = 1; i < xLength; i++){
    for (int j = 1; j < yLength; j++){
      if (fileX[i-1] == fileY[j-1]){ //if the char inputs match then store them in table
        table[i][j] = table[i-1][j-1] + 1;
        dirTable[i][j] = DIAG;      //indicating that xi = yi is an elemenct of LCS
      }
      else if (table[i-1][j] >= table[i][j-1])
      {
        table[i][j] = table[i-1][j];
        dirTable[i][j] = UP;      //move to row above
      }
      else{
        table[i][j] = table[i][j-1];
        dirTable[i][j] = LEFT;      //move to col on left
      }
    }
  }
  return table[xLength-1][yLength-1]; //length
}
string getSequence(vector<vector<int> > &table, vector<vector<int> > &dirTable){
  int row = xLength - 1;
  int col = yLength - 1;
  string subseq = "";
  while(row > 0 && col > 0)
  {
    if(dirTable[row][col] == DIAG){
      subseq = fileX[row-1] + subseq;
      row--;
      col--;
    }
    else if(dirTable[row][col] == UP) row--;
    else if (dirTable[row][col] == LEFT) col--;
  }
  return subseq;
}
void writeOut(vector<vector<int> > &table, vector<vector<int> > &dirTable, clock_t startTime, clock_t endTime, int result){
  ofstream outputFile(output);
  if(!outputFile.is_open()){
    cout << "Cannot create output file" << endl;
    exit(-1);
  }
  //if less than or equal to 10
  if(xLength - 1 <= 10 && yLength - 1 <= 10)
  {
    for(unsigned int row = 0; row < xLength; row++){
      for(unsigned int col = 0; col < yLength; col++){
        outputFile << table[row][col]<< " ";  //contents
      }
      outputFile << endl;
    }
    string subseq = getSequence(table, dirTable);
    outputFile << subseq << endl;
  }
  //greater than 10
  else  outputFile << result << endl;

  outputFile << float((float)endTime - (float)startTime)/CLOCKS_PER_SEC << " sec";
  outputFile.close();
}

int main (int argc, char *argv[])
{
  if(argc !=4){
    cout << "Invalid input. Please ensure correct format 'prompt> program1 <filex.txt> <filey.txt> <output1.txt>'" << endl;
    return -1;
 }
  fileX = readInput(argv[1]);
  fileY = readInput(argv[2]);
  output = argv[3];
  xLength = fileX.length() + 1;
  yLength = fileY.length() + 1;
  vector<vector<int> > table( xLength, vector<int> (yLength));
  vector<vector<int> > dirTable( xLength, vector<int> (yLength));  //direction table

  initialize(table, dirTable);
  clock_t startTime, endTime;

  startTime = clock();
  int result = LCS_RESULT(table, dirTable);
  endTime = clock();

  writeOut(table, dirTable, startTime, endTime, result);
  return 0;
}
