#include "Dog.h"
#include <iostream>
using namespace std;

Dog::Dog(string input){
  this->breed = "Mutt";
  name = input;
}
Dog::~Dog(){
  cout<< "Goodbye Cruel World!"<< endl;
}


void Dog:: bark(){
  cout<< "Bark!!!" << endl;
}


Lab::Lab(string name){
  Breed = "lab";
  this->name = name;clear
  
}
