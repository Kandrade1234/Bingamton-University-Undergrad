#ifndef
#define
class Node{
  private:
    int data;
    Node * next;
  public:
    Node (int x) { data = x; next = NULL;}
    Node(int x, Node * n){
      data = x; next = n;
    }
};

class List{
  private:
      Node * head,;
      //to save where we are at in the lsit VVV
      Node * current;
  public:
      List();
    //Making a direct copy const will say taht it cannot be changed. DEEP COPY. COPY CONSTRUCTOR
    //dont forget to set things to null it is still a constructor
    List(const List & o){
        head = tail = current = NULL;
        if(head!=NULL){
            Node * current = o.head;
            while(current != NULL){
                insert(current->data);
            }
        }
    }
      ~List();
      int * find();
      void print();
};
#endif

/*IN MAIN WE WOULD WRITE FOR THE COPY CONSTRUCTOR AS
 
 
 List sllist()
 
 //ALL 3 WAYS COPY CONSTRUCTOR GETS CALLED
 List sllist2(sllist);
 list sllist2 = sllist;
 foo(sllist); <------ this is being passed by value to some function so it actually calls the copy constructor because it is making a copy!
