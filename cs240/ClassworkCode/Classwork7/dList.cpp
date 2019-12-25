#include "List.h"
#include <ctdlib>
#include <iostream>


List::List(){
  this->head = NULL;
  this->current = NULL;
}

//returning the ptr to the data that you found that matches parameters. efficiency is N
//using current lets you save where you were so you dont have to keep traversing through list
//Harder to code and controll (i.e wrap arround the list) but more efficient
int * List::find(int num){
  current = head;
  while(current != NULL)
  {
      if(num == current->data) return &current->data;
      current = current->next;
  }
  return NULL;
}



//Returns data that is pointing to currently *MORE EFFICIENT WAY*
int * List::get(){
  if(head == NULL) return NULL;
  if (current == NULL)
  {//This is how you wrap arround list
    current = head;
    return NULL;
  }
  return &current->data;
}

bool List::next(){
  if(current != NULL) current ->next;
  (current== NULL) ? return false: return true;
}                  //study this? if true else?


//RESETS ITERATOR
void List::reset(){
  if(head == NULL)return;
  else current = head;
}



//PRINTS ELEMENTS
List::print(){
//traversing make sure you make temp ptr. Efficiency is N
  Node * ptr = head;
  while(ptr !=NULL){
    cout << head->data << endl;
    ptr = ptr->next;
  }
}
