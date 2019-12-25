#include "Item.h"
#include "BestFirstTreeSearch.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

//the driver takes inputs from cmd line.
int main (int argc, char* argv[])
{
  if(argc < 3 || argc > 3)
  {
    cerr << "must be in the format of ./BestFirstSearch <input.txt> <output.txt> " << endl;
    return -1;
  }
  int n,c;
  vector<Item> items = vector<Item> (); //will be used to store all the input items from the file
  //Fetching the first passed in argument from cmd
  string input = "";
  std::ifstream file(argv[1]);
  getline(file, input);

  //parsing the number of items and bag capacity
  string str = input.substr(0, input.find(",")); //will get n (items)
  string cap = input.substr(input.find(",") + 1);  //will get c (capacity);

  n = stoi(str);
  c = stoi(cap);

  for(int i = 0; i < n; i++){
    getline(file, input);
    int w = stoi(input.substr(0, input.find(",")));
    int p = stoi(input.substr(input.find(",") + 1));
    items.push_back(Item(w,p));
  }
  //sorting the vector in decreasing order
  std::sort(items.begin(), items.end());

  BestFirstSearch start = BestFirstSearch(argv[2], c, n, items);
  start.output();

}
