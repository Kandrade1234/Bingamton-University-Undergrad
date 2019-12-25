///making node private and a friend of linked listso only linked list can access it. 


class Node{
private:
  Node * next;
  Node(Ant a);
  friend class LinkedList;
}



class LinkedList{

}
