#ifndef
#define
class Node{
  private:
    int data;
    Node * next;
    Node * prev;
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
      Node * tail;
  public:
      List();
      ~List();
      int * find();
      void print();
};
#endif
