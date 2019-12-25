#include "Card.h"
Card :: Card(){
	suit = 1;
	value =2;
}
Card::Card(int suit, int value){
	if(value >=2 && value <=14 && suit >=1 && suit <=4){

		this-> value = value;
		this->suit = suit;
	}
	else{
		//setting defaults
		this->suit = 1;
		this->value = 2;
	}
}

int Card:: getValue(){
	return value;
}

int Card :: getSuit(){
	return suit;
}

bool Card :: operator == (const Card &other)
{
	return  this->value == other.value;
}

bool Card :: operator < (const Card &other){
	if(this->value < other.value) return true;
	else if(this->value == other.value){	//this is false
		if(this->value < other.value)
			return true;
		else return false;
	}
	else return false;

}
