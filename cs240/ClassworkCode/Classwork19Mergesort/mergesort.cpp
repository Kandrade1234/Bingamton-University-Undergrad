#include <cstdlib>
#include <iostream>
#include <ctime>

//psudocode
void merge(left, right){
  int SortedArray[left->size+right->size];

  int i,j,k = 0;
  while(i !=left->size && i!= right->size){
    if(left[i]>right[i]){
      SortedArray[k] = right[j];
      k++;
      j++;
    }
    else{
      SortedArray[k] = right[i];
      k++;
      i++;
    }
  }

  while(left or right has elements){
    SortedArray[k] = left[i]/right[j]
    i/j++, k++
  }
  return SortedArray;



}

int array[] mergesort(array){
  if(array->size == 1)
    return array;
    else{
      arrayLeft, aRight = split(array); //where left and right get assigned their respective part of the array. (i.e arrL = leftsplit(array) ....arrR(rightsplit(array)))
      arrLeft = mergesort(aleft);
      arrRight = mergesort(aRight);
      sorted = merge (arrLeft,arrRight );
    }
}
