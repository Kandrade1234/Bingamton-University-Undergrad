#include "BSTree.h"
#include <iostream>
#include <cstdlib>

//Performs a deep copy of a BSTree object using preorder traversal


BSTree ::  BSTree(const BSTree &old_tree){
	if(old_tree.root == NULL) this->root = NULL;
	else{
		//insertTree(old_tree.root, old_tree.root->data);
		preorder(old_tree.root);
	}

}

void BSTree :: preorder(Node * n){
	if(n == NULL) return;
	if(insertTree(n, n->data)){
	preorder(n->left);
	preorder(n->right);
	}
}
BSTree :: ~BSTree(){
	postorder(root);
}


void BSTree :: postorder(Node * n){
	if(n == NULL) return;
	postorder(n->left);
	postorder(n->right);
	delete n;


}
void BSTree :: removeLeaf(Node * del){

	if(del == root){
		delete root;
		root = NULL;
	}
	else if(del->parent->left == del){
		del->parent->left = NULL;
		delete del;
	}
	else{
		del->parent->right = NULL;
		delete del;
	}



}
void BSTree :: shortcircuit(Node * del){
	if(del == root) {
		delete root;
		root = NULL;
	}
	if(del->parent->left == del){
		if(del->left != NULL){
			del->parent->left = del->left;
			del->left->parent = del->parent;
		}
		else{
			del->parent->left = del->right;
			del->right->parent = del->parent;
		}
	    del -> parent -> left = NULL;
	}
	else{
		if(del->right!= NULL){
			del -> parent -> right = del -> left;
			del -> left -> parent = del -> parent;
		}
		del -> parent -> right = NULL;
	}
	delete del;


}
bool BSTree :: remove(int num){
	if(root == NULL) return false;
	Node * del = readNode(num, root);
	if(!findVal(del, num)) return false;

	if(del->left ==NULL && del->right == NULL){
		removeLeaf(del);

	}
	else if(del->left == NULL || del -> right == NULL)
		shortcircuit(del);
	else
		promotion(del);

	return true;

}

void BSTree :: promotion (Node * del){

}


BSTree:: Node* BSTree :: getMinMax(Node* n){
if(n->left == NULL)return n;
else return getMinMax(n->left);

}
BSTree::Node* BSTree::  readNode(int val, Node * root){
	if (root == NULL) return NULL;
	if (root->data == val) return root;
	if (val < root->data)
	{
		  return readNode(val, root->left);
	}
	else /*Must be greater than root*/
	{

		return readNode(val, root->right);

	}


}
bool BSTree :: insertTree(Node * root, int val){
	if(root->data == val) return false;	//if its in there, then dont add just return false
	if (val < root->data)
	{
		if (root->left == NULL )
		{
			root->left = new Node(root, NULL, NULL, val);
			return true;
		}
		else insertTree ( root->left, val);
	}
	else /*Must be greater than root*/
	{
		if(root->right == NULL)
		{
			root->right = new Node(root, NULL, NULL, val);
			return true;
		}
		else insertTree(root->right, val);

	}
	return false; /*If it fails all these cases, there must be an error in input*/
}
bool BSTree:: insert (int val) {
	if(root == NULL){
		root = new Node(NULL, NULL, NULL, val);
		return true;
	}

	if (insertTree(root, val)) return true;
	return false;
}



bool BSTree :: findVal(Node * root, int val){
	if (root == NULL) return false;
	if (root->data == val) return true;
	if (val < root->data)
	{
		 return findVal(root->left, val);
	}
	else /*Must be greater than root*/
	{

		return findVal(root->right, val);

	}

}

bool BSTree :: find(int val){

	return findVal(root, val);

}
BSTree :: BSTree(){
	root = NULL;
}

bool BSTree :: empty(){
	if (root==NULL) return true;
	return false;

}
void BSTree :: sortedArray(std::vector<int> &list){
  inorder(root, list);

}
void BSTree :: inorder(Node * n, std::vector<int> &list){
  if(n == NULL) return;
  inorder(n->left, list);
  list.push_back(n->data);
  inorder(n->right, list);

}
