/* This file runs a bottom-up implementation of the LCS problem.
 * It includes a main function for operating the program from the command line.
 * It also includes the LCS function which is called with the input strings and determines the LCS.
 */
#include "common.h"
#include <ctime>

// For easy reading in the code, will be stored in the direction array
#define DIAG (1)
#define UP (2)
#define LEFT (3)

/* Determines the LCS of input strings x and y
 * x and y are non-empty strings and m and m are the lengths of x and y respectively
 * c and b are 2D integer arrays of mxn size initialized to all zeroes
 * Function returns the length of LCS, b and c also set to correct values to determine actual LCS
*/
int LCS(int** c, int ** b, std::string x, std::string y, int m, int n) {
  for(int i = 1; i < m; i++) {
    for(int j = 1; j < n; j++) {

      if(x[i-1] == y[j-1]) {
	c[i][j] = c[i-1][j-1] + 1;
	b[i][j] = DIAG;
      }
      else if(c[i-1][j] >= c[i][j-1]) {
	c[i][j] = c[i-1][j];
	b[i][j] = UP;
      }
      else {
	c[i][j] = c[i][j-1];
	b[i][j] = LEFT;
      }
    }
  }
  return c[m-1][n-1];
}

/* Reads file name inputs, reads strings from these inputs,
 * calls LCS on these strings, and then parses the string using the "b" array, then outputs time taken and string content/length
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
  int** c = new int*[x.length() + 1];
  int** b = new int*[x.length() + 1];
  for(int i = 0; i < x.length() + 1; i++) {
    c[i] = new int[y.length() + 1];
    b[i] = new int[y.length() + 1];
  }

  for(int i = 0; i < x.length() + 1; i++) {
    for(int j = 0; j < y.length() + 1; j++) {
      c[i][j] = 0;
      b[i][j] = 0;
    }
  }

  t1=clock();
  int result = LCS(c, b, x, y, x.length() + 1, y.length() + 1);
  t2=clock();


  // Write output to file
  // Cannot use writeOutput method in common.h due to difference in specifications for program1
  std::ofstream output(argv[3]);
  if(!output.is_open()) {
    std::cout << "Error creating output file" << std::endl;
    exit(-1);
  }
  // If less than 10, output matrix and longest common subsequence
  if(x.length() < 10 && y.length() < 10) {
    // Matrix
    for(int i = 0; i < x.length() + 1; i++) {
      for(int j = 0; j < y.length() + 1; j++) {
	output << c[i][j] << " ";
      }
      output << std::endl;
    }

    //Subsequence
    int m = x.length(); int n = y.length();
    std::string subsequence = "";
    while(m > 0 && n > 0) {
      if(b[m][n] == DIAG) {
	subsequence = x[m-1] + subsequence;
	m--; n--;
      }
      else if(b[m][n] == UP) {
	m--;
      }
      else if(b[m][n] == LEFT) {
	n--;
      }
    }
    output << subsequence << std::endl;
  }



  // If greater than 10, just output length
  else {
    output << result << std::endl;
  }
  output << float((float)t2 - (float)t1)/CLOCKS_PER_SEC << " seconds" << std::endl;
  output.close();


  // Avoid memory leaks
  for(int i = 0; i < x.length() + 1; i++) {
    delete[] c[i];
    delete[] b[i];
  }
  delete[] c;
  delete[] b;
}
