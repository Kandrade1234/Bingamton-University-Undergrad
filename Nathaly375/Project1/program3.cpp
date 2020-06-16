#include <ctime>
#include <iostream>
#include <stdio.h>
#include<fstream>
#include <vector>
using namespace std;

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
int recursiveLCS(int i, int j,vector<vector<int> > &table ){
  if(table[i][j] == -1)
  {
    if(i >= xLength - 1 || j >= yLength -1 )
    {
      table[i][j] = 0;
    }
    else if (fileX[i] == fileY[j]){
       table[i][j] = recursiveLCS(i+1, j+1, table) + 1;
    }
    else{
      table[i][j] = std::max(recursiveLCS( i+1, j, table), recursiveLCS(i, j+1, table));
   }
 }
 return table[i][j];
}
void writeOut(int result, clock_t startTime, clock_t endTime){
  ofstream outputFile(output);
  if(!outputFile.is_open()){
    cout << "Cannot create output file" << endl;
    exit(-1);
  }
  else if(outputFile.is_open())
  {
    outputFile << result << endl << float((float)endTime - (float)startTime)/CLOCKS_PER_SEC << "sec";
    outputFile.close();
  }
}
int main (int argc, char *argv[])
{
  if(argc !=4){
    cout << "Invalid input. Please ensure correct format 'prompt> program2 <filex.txt> <filey.txt> <output1.txt>'" << endl;
    return -1;
 }
  fileX = readInput(argv[1]);
  fileY = readInput(argv[2]);
  output = argv[3];
  xLength = fileX.length() + 1;
  yLength = fileY.length() + 1;
  vector<vector<int> > table( xLength, vector<int> (yLength, -1));
  clock_t startTime, endTime;
  startTime = clock();
  int result = recursiveLCS(0, 0, table);
  endTime = clock();
  writeOut(result, startTime, endTime);
  return 0;
}
