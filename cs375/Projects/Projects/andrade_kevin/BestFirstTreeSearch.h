#ifndef BESTFIRSTSEARCH_H
#define BESTFIRSTSEARCH_H
#include "Item.h"
#include "Node.h"
#include <queue>
#include <vector>
#include <string>
using namespace std;

//branch and bound algorithm class. This class is used to compute the branch and bound algorithm
class BestFirstSearch{

  public:
    /* Takes the output name of the file, number of items, capacity and a vector containing the items from the input*/
    BestFirstSearch(string, int, int, vector<Item>);
    void output();

  private:
    //does the computation for "normal" and fractional
    int fraction(int, int, int);
    int totNodes; //total nodes
    int capacity; //total capacity
    int bestValue;  //best value
    int leafNodes;  //amount of leafnodes
    int totItems; //entries
    std::vector<Item> items;  //items from file
    std::vector<bool> includes; //includes bool vector to keep track of which ones to include when writing to output
    std::priority_queue<Node> solutions;  //data structure that holds everything
    string outputFile;  //output file name
};
#endif
