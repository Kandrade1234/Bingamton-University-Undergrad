#include "Item.h"


/*takes the weight and profit.
* assumes its being passed a weight and profit correctly
* also stores the p/w ratio of the item for easier accessing
*/
Item::Item(int weight, int profit)
{
  this->weight = weight;
  this->profit = profit;
  ratio = 0;
}

float Item :: getRatio()
{
  return (float) profit / (float) weight;
}
