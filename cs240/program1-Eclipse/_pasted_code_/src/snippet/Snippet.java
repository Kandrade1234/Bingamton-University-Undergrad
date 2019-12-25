package snippet;

public class Snippet {
	
	//Default constructor
	LinkedList::List(){
		this->head = NULL;
		this->current = NULL;
	}
	
	
	
	
	void LinkedList :: list_insert(Ant input){
		if(head == NULL){
			this->head = new Node(input);
			current = head;
		}
		else {
	
	
		}
	}
	
	//Function will keep going next until it hits nulls. Remember that it picks 
	//up from wherever current was last. 
	bool LinkedList::next(){
	  if(current != NULL) current ->next;
	  (current == NULL) ? return false: return true;
	} 
	
	
	//Looks to see if its in the list and returns the Ant if not then returns NULL
	Ant LinkedList::find(Ant num){
		this->reset();	// resets pointer
	  while(current != NULL)
	  {
	      if(num == current->data) return current->data;
	      current = current->next;
	  }
	  return NULL;
	}
	
	
	void LinkedList::print(){
	
	Node * ptr = head;
	while(ptr !=NULL){
		cout << head->data << endl;
		ptr = ptr->next;
	}
	}
	
	
	//resets current pointer to head.
	void LinkedList::reset(){
		if(head == NULL) return;
		else current = head
	}
	
	
	}
	
}

