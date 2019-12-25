#include "Node.h"
Node :: Node (std::vector<bool> inc, int c_weight, int c_value, int t_value, int c_element)
{
 promising = inc;
 cWeight = c_weight;
 cValue = c_value;
 bound = t_value;
 cElement = c_element;
}
