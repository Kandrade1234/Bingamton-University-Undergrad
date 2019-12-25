#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Ant.h"
#include <iostream>
#include <cstdlib>
class Node{
	private:
		Ant * data;
		Node * next;

	public:
		Node (Ant * new_Ant){this->data = new_Ant; this->next = NULL;}
		Node(Ant * new_Ant, Node * n){this->data =  new_Ant; this->next = n;}
		~Node();
		Node * nlink( ) { return next; }
		void set_nlink(Node * new_link){next = new_link;}
		Ant * getData(){return data;}
};
class List{

	private:
		Node * head;
		//int size; //maybe this is useful to not have to traverse all the time to tell the size
        	int size;
	public:
		List();//DONE->TESTED
		List(const List & o );//DONE ->TESTED
		~List();//DONE
		//void reset();//DONE-> TESTED
		//bool next();//confused->not working-> neccesary?????
		void insert_head (Ant*);//DONE->tested
		void append (Ant * );//DONE->tested
        	void remove(Ant *);//HAVING ISSUES
		void remove_at_pos(Ant * ); //not implemented, not sure if even nencesary
		//Ant * find(Ant *); //DONE->tested
        	bool find(Ant *); //DONE->tested
        	bool is_item( ) const {Node * current = head; return (current != NULL); } //DONE->tested
	//	void modify(int old, int n_int);
		void print(); //DONE ->tested
		   Ant * get(Ant* in); //DONE ->tested
       		int getSize(){return size;}
		void operator <<(Ant * b);
};

#endif
