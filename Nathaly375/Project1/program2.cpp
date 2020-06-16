#include <ctime>
#include <iostream>
#include <stdio.h>
#include<fstream>
using namespace std;

string fileX;
string fileY;
string output;

string readInput(string file){
  string in = "";
  ifstream fileRead(file);
  fileRead >> in;
  return in;
}
int recursiveLCS(int i, int j){
  if(i < 0  || j < 0) return 0;
  else if (fileX[i] == fileY[j]) return recursiveLCS(i-1, j-1) + 1;
  else return std::max(recursiveLCS(i-1, j), recursiveLCS(i, j-1));
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
  clock_t startTime, endTime;
  startTime = clock();
  int result = recursiveLCS(fileX.length() - 1, fileY.length() - 1);
  endTime = clock();

  writeOut(result, startTime, endTime);

  return 0;
}
