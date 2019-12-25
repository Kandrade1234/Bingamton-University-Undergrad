#include <vector>


class Heap{
private:
  std::vector<int> heap;

public:
  Heap(std::vector<int> list){
      heapify(&list); //we want to pass by reference since we do not want tomodify a copy
      heap = list;
  }


heapify(std::vector<int> *list){        //pointer to the address from code above(the vector)
  //we want to get the starting pointand remember wewant theindex and we do -2 since our diagram that makes sense (INDEX OF PARENT)
  for(int i = (list.size()-2)/2;i>=0 ;i--)
    siftdown(i, &list);                            //working our way backwards through the tree/array and sift down
}

siftdown(i, std::vector<int> list){
  if(i < 0 || i >=list->size()) return; //return we dont need to do anything. we are done

  //two conditions when we stop. 1. whenboth are lower priority 2. when it is a leaf
while(!isLeaf(i)){    //while it is NOT a leaf/.
  int swapnode = left(i);    //index of left child
  if(swapnode+1 < list->size()-1 && list[swapnode] > list[swapnode+1]){
    // IF WE WANT TO MAXE IT MIN HEADP -> if(swapnode+1 < list->size()-1 && list[swapnode] < list[swapnode+1]){
    swapnode+=1;
  }
  if(list[i] > list[swapnode]){
    return; //its in its right place
  }

  swap(i, swapnode, list);
  i=swapnode;
    }

  }

  //something about removing last element ? popback?
intpriority(){
  int ret = heap[0];
  heap[0] = heap[heap.size()-1];
  siftdown(0, &heap);
  return ret;
}

};
