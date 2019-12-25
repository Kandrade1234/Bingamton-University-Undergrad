
//SINGLY lINKED LIST
//fast nodes jump by 2....efficiency n
bool list::malformed(){
  Node * s, *f1, *f2;

  s = head;
  f1 = s->next;
  f2=f1->next;

//ommiting first part of for loop
  for(; f1!=NULL && f2!=NULL; s = s->next){
    if(s==f1||s==f2){
      return true;
    }
    //leap frogging eachother
    f1=f2->next;
    if(f1 == NULL) break;
    f2 = f1->next;
  }
  //false is good
return false;
}


//DOUBLY LINKED listbool list::malformed(){
  Node * s, *f1, *f2;

  s = head;
  f1 = s->next;
  f2=f1->next;

  for(; f1!=head && f2!=head; s = s->next){
    if(s==f1||s==f2){
      return true;
    }
    //leap frogging eachother
    f1=f2->next;
    if(f1 == NULL) break;
    f2 = f1->next;
  }
return false;
}
