/* This file runs a top-down implementation of the LCS problem.
 * It includes a main function for operating the program from the command line.
 * It also includes the recursive LCS function which is called with the input strings and determines the LCS.
 */

#include "common.h"

// Preprocessor macro which determines the max of two inputs
#define max(x, y) (((x) > (y)) ? (x) : (y))


/* Determines the LCS of input strings x and y recursively
 * x and y are non-empty strings and i and j are the lengths of x and y respectively
 * Function returns the length of LCS.
*/
int LCS_recursive(std::string x, std::string y, int i, int j) {
  if(i < 0 || j < 0) return 0;
  if(x[i] == y[j]) return LCS_recursive(x, y, i-1, j-1) + 1;
  return max(LCS_recursive(x, y, i-1, j), LCS_recursive(x, y, i, j-1));
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

  t1=clock();
  int result = LCS_recursive(x, y, x.length() - 1, y.length() - 1);
  t2=clock();

  writeOutput(argv[3], result, float((float)t2 - (float)t1)/CLOCKS_PER_SEC);

  return 0;
 }
  
