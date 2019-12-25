//DOUBLY LINKED LIST PASSED IN PARAMETER AND make two new dlist alternating order and return an array with the pointers to both lists
//Scarp
Node * alternating(NODE input){
Node * ptr = this-> head;

Node * first = new Node(input->getData_head());
//will advance to the next element and set current pointer to wherever next is
Node * second = new Node(input->next());

while(ptr!=NULL){

ptr->next;
}

}



/*profesors way*/

//the reason why we return double pointer is because we cannot return array in c++ adn we need an array of pointers
DLList ** newLists(DLList * orig){
  DLList * elist = new DLList();
  DLList * olist = new DLList();
orig->reset();

int counter = 0;

while(orig->next()){
  if(counter && 1){//bitmap for even or odd
    olist->insert(orig->get());
  }
  else{
    elist->insert(orig->get());
  }

counter++;
}
DLList ** ret = new DLList * [2];
ret[0] = olist;
ret[1] = elist;
return ret;
}


}
