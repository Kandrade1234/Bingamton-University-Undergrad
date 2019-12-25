//doubly linked list
void List::removeZeros(){
  Node lag = head;
  for(Node p = lag.next;p!=NULL && p!=tail; p = p.next;){
    if(p.data == 0){
      lag.next = p.next;
      delete p;
    }
    else{
      lag = p;
    }
  }
}
