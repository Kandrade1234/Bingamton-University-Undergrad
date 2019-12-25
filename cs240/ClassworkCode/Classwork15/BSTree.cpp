
//For DEEP copy you gotta use

void preorder(Node *n){
  if(n == NULL) return;

}


void postorder(Node * n){
  if(n == NULL) return;
  postorder(n->left);
  postorder(n->right);
  .
  .
  .
  .
  .
  





}

void inorder(Node *n){
  if( n ==NULL) return;
  inorder(n->left);
  std::cout << n->data << std::endl;
  inOrder(n->right);
}


/*REMOVING LEAF NODE*/
void removeLeaf(Node * del){


  /*if this == root, then becareful (i.e make special case first)*/


  if(del->parent->left == del){ //does not consider root

    del->parent->left = NULL;

  }
  else del->parent->right = NULL;

  delete del;//if destructor is set up properly, this should work.

}
void shortcircuit(Node * del){ //meaning we have a 1 child node?
  if(del->parent->left == del){ //does not consider root
    if(del->left != NULL)
    {
      del->parent->left = del->left;
      del->left->parent = del->parent;
    }
    else
    {
      del->parent->left = del->right;
      del->right->parent = del->parent;

    }
  }
  else{
//same algorithm over here from the one abocve.
    if(del->right!= NULL){
      del->parent ->right = del->right;
    }
  }

  delete del;
}

void promotion(Node * del){
//if first way
Node * promote = getMinMax(del);
if(promote->left == NULL && promote->right)
  removeLeaf(promote);
  else {
    shortcircuit(promote);
  }

  //if second way
  Node * del = getMinMax(del->right);
}
Node * getMinMax(Node * n){
/*1st way
n=n->right;
while(n->left != NULL){
  n= n->left;

}
return n;
*/
//second way
  if(n->left == NULL){
    return n;
  }
  else {
    return getMinMax(n->left);


  }




}
void remove(T data){
  Node * del = readNode(T data, root);
  if(del->left == NULL && del -> right == NULL)
  removeLeaf(del);
  else if(del->left ==NULL || del->right ==)
  shortcircuit(del)
  else
  promotion(del);




}
