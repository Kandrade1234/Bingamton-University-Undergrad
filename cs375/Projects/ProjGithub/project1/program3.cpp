/* This file runs a top-down implementation of the LCS problem with memorization.
 * It includes a main function for operating the program from the command line.
 * It also includes the recursive LCS function which is called with the input strings and determines the LCS.
 */

#include "common.h"
#include <ctime>

// Preprocessor macro which determines the max of two inputs
#define max(x, y) (((x) > (y)) ? (x) : (y))

/* Determines the LCS of input strings x and y recursively with memorization
 * x and y are non-empty strings and i and j are the lengths of x and y respectively
 * values is a 2D integer array of mxn size initialized to all zeroes
 * Function returns the length of LCS.
*/
int LCS_recursive(int** values, std::string x, std::string y, int i, int j) {
  if(i < 0 || j < 0) return 0;
  if(values[i][j] != -1) return values[i][j];
  if(x[i] == y[j]) {
    values[i][j] = LCS_recursive(values, x, y, i-1, j-1) + 1;
    return values[i][j];
  } else {
    values[i][j] = max(LCS_recursive(values, x, y, i-1, j), LCS_recursive(values, x, y, i, j-1));
    return values[i][j];
  }
}

/* Reads file name inputs, reads strings from these inputs,
 * recursively calculates length of LCS of these strings, outputs time taken and length
 */
int main(int argc, char *argv[]) {
  if(argc != 4) {
    std::cout << "Invalid input." << std::endl;
    return -1;
  }
  std::string x = getInput(argv[1]);
  std::string y = getInput(argv[2]);
  std::clock_t t1, t2;

  //set up array
  int** values = new int*[x.length()];
  for(int i = 0; i < x.length(); i++) {
    values[i] = new int[y.length()];
  }
  for(int r = 0; r < x.length(); r++) {
    for(int c = 0; c < y.length(); c++) {
      values[r][c] = -1;
    }
  }


  t1=clock();
  int result = LCS_recursive(values, x, y, x.length() - 1, y.length() - 1);
  t2=clock();


  // Avoid memory leaks
  for(int i = 0; i < x.length(); i++) {
    delete[] values[i];
  }
  delete[] values;

  writeOutput(argv[3], result, float((float)t2 - (float)t1)/CLOCKS_PER_SEC);

  return 0;
}
