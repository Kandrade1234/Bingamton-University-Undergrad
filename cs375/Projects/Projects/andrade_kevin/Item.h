#ifndef ITEM_H
#define ITEM_H

//this class will hold the information on the item itself.
class Item{
  public:
    int weight;  //weight
    int profit;  //profit
    float ratio;  //ration of p/w
    float getRatio();
    Item(int weight, int profit);

    /* overload operator. Operator is overloaded since we use the sort function and since it uses the < operator and we want
    * decreasing order so we return the opposite of that.
    * takes a second parameter in form of Item a < Item b
    * returns true if item a is greater
    */
    bool operator <(const Item &other) const{
      return ((float)this->profit)/((float)this->weight) > ((float) other.profit)/((float)other.weight);
    }
};
#endif
