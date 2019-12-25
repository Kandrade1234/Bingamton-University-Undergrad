

List::List(const List &l){
  head = NULL;
  if(!l.malFormed() && l.reset())return;

  while(l.next()){
    int value = l.get();\this->insert(value);
  }
}

int List::malFormed(){
  Node * slowNode = l->head, * fastNode1 = l->head, *fastNode2 = l->head;
  while(slowNode && fastNode1 = fastNode2->next() && fastNode2 = fastNode1->next()){
  if(slowNode == fastNode1 || slowNode == fastNode2) return true;
  slowNode = slowNode->next();
}

return false;


}
