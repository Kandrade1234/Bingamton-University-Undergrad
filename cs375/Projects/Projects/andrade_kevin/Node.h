#ifndef NODE_H
#define NODE_H
#include <vector>
#include "Item.h"

/*
  This class will be the node that will be stored inside the queue. The node contains a vector of promising nodes (answers)
*/

class Node{
  public:
    std::vector<bool> promising; //answers
    int cWeight;
    int cValue;
    int bound; //bound
    int cElement;
    Node (std::vector<bool> inc, int c_weight, int c_value, int t_value, int c_element);  //constructor
    bool operator <(const Node &other) const{ //overriding for easier sorting. 
        return this->bound < other.bound;
      }
};
#endif
