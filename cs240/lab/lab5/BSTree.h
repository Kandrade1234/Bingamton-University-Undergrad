#ifndef BSTREE_H
#define BSTREE_H
#include <iostream>
#include <cstdlib>
#include <vector>

class BSTree{
        private:
        	class Node{
                    public:
			int data;
			Node * left;
			Node * right;
			Node * parent;
			Node( Node * parent, Node * left, Node * right, int data){ //Constructor
			this->parent = parent, this-> left = left; this-> right = right; this->data = data;}


		};
		Node * root;


	public:
		bool insertTree(Node * root, int val);	//helper function
		bool findVal(Node * root, int val); //helper function
		BSTree();
		//NEW FUNCTIONS
		BSTree(const BSTree &old_tree);
		~BSTree();
		void sortedArray(std::vector<int> &list);
		bool insert(int val);
		bool find(int val);
		bool remove(int num);
		bool empty();
		Node * readNode(int, Node *);
		void removeLeaf(Node *);
		void promotion (Node *);
		Node * getMinMax(Node * n);
		void shortcircuit(Node * del);

	private:
		void preorder(Node * n);
		void postorder(Node * n);
		void inorder(Node * n, std::vector<int> &list);







};
#endif
