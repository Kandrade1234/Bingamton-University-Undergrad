#include "BestFirstTreeSearch.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <string>
#include <fstream>
using namespace std;

/* Constructor for the algorithm takes in output file name, capacity, size and the items themselves
*  assumes a valid inpput
*/
BestFirstSearch::BestFirstSearch(string output_file, int c, int n, vector<Item> items)
{
  outputFile = output_file;
  capacity = c;
  totItems = n;
  this->items = items;

  bestValue = 0;
  totNodes = 0;
  leafNodes = 0;
  includes = std::vector<bool> ();
  solutions.push(Node(includes, 0, 0, fraction(0,0,0), 0)); //inserts a Node obj with the boolean array, weights and values and bound.

  /* followed algorithm from slides
  * we will keep going through all nodes in queue
  */
  while(!solutions.empty())
  {
    Node current = solutions.top();
    solutions.pop();
    totNodes++;
    if(current.cElement < totItems)
    {
      if(current.bound >= bestValue && current.cWeight < capacity)
      {
        std::vector<bool> addPath = current.promising;
        std::vector<bool> dontAddPath = current.promising;

        addPath.push_back(true);
        dontAddPath.push_back(false);
        Item temp = items.at(current.cElement);
        //for function which will be the yes and no child
        int combinedWeight = current.cWeight + temp.weight;
        int combineProfit = current.cValue + temp.profit;

        int add = fraction(current.cElement+1, combinedWeight, combineProfit);
        int dontAdd = fraction(current.cElement+1, current.cWeight, current.cValue);

        if (add >= bestValue) //if bound(v) is better than best
        {
          solutions.push(Node(addPath, combinedWeight, combineProfit, add, current.cElement+1));
          if(combineProfit > bestValue && combinedWeight <= capacity) bestValue = combineProfit; //if value u is better than best
        }
        solutions.push(Node(dontAddPath, current.cWeight, current.cValue, dontAdd, current.cElement+1));
      }
      else leafNodes++;
    }
    else leafNodes++;
    if(current.cValue == bestValue){
      includes = current.promising;
    }
  }

}

//this computes the fractional knapsack problem. It computes a fraction weather the weight + the items weight is more or equal to the capacity.
//function assumes that the user passes in correct values.
//bound function.
//i = start point
int BestFirstSearch :: fraction(int i, int pWeight, int pProfit)
{

  while(pWeight != capacity && i < totItems)
  {
    if((pWeight + items.at(i).weight) < capacity)
    { //this is the yes
      pWeight += items.at(i).weight;
      pProfit += items.at(i).profit;
    }
    else
    { //this is the no
      float remain = (capacity - pWeight);
      pWeight = capacity;
      //(float) profit / (float) (weight) --> the profit and weight ratio
      pProfit += (int) (items.at(i).getRatio() * remain);
    }
    i++;
  }
  return pProfit;
}

/* This function writes the output onto a file
* style is specified within project specifications
*/
void BestFirstSearch :: output()
{

  int inSolutionNodes = 0;
  std::ofstream output;
  output.open(outputFile, std::ios::out);
  if(!output.is_open())
  {
    std::cerr << "Cannot output!" << endl;
    exit(0);
  }
if(output.is_open()){
    int i = 0;
    for(int i = 0; i < totItems; i++)
      if(includes.at(i)) inSolutionNodes++;

    /*Line 1: The size of the problem (i.e., the total number of items),the optimal value (i.e., the maximum
     *profit),the size (k) of the first optimal solution found (i.e., the size of the first optimal subset of items
     *found to produce the maximum profit)
     */
     output << totItems << "," << bestValue << "," << inSolutionNodes << endl;
    /*Line 2: the total number of nodes visited (by the algorithm from the start to the end of the search
     *including the root and the last node visited in the binary search space tree), the total number of leaf nodes
     *visited
     */
     output << totNodes << "," << leafNodes << endl;
    /* Lines 3 to 3+(k-1): each line contains the weight and profit of an item selected in order for the first
     * optimal solution found.
     */
     for(int i = 0; i < totItems; i++)
       if (includes.at(i)) output << items.at(i).weight << "," << items.at(i).profit << endl;

}
   output.close();
}
