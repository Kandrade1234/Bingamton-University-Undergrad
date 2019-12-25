/* Contains methods common to all 3 implementations
 * getInput takes in a file name and returns the string in the first line of the input
 * writeOutput takes a file name, length of LCS, and time taken, and writes the length and time into the file at file_name in the manner specified by the instructions
 */

#ifndef COMMON_H
#define COMMON_H

#include<fstream>
#include<iostream>
#include<ctime>

// Returns the first string in the filex.txt input
std::string getInput(std::string file_name) {
  std::string x = "";
  std::ifstream xfile(file_name);
  xfile >> x;
  return x;
}

// Writes time and length of LCS to file designated by file_name
void writeOutput(std::string file_name, int length, float time) {
  std::ofstream output(file_name);
  if(output.is_open()) {
    output << length << std::endl;
    output << time << " seconds" << std::endl;
    output.close();
  }
  else std::cout << "Error creating output file" << std::endl;
}

#endif
