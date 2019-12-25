#include "Dog.h"
#include <iostream>
#include <cstdlib>
//initialize outside of class for any static variables.
int DogShelter::next_id =1;
using namespace std;
Dog::Dog(string breed){
  this->breed = breed;
}
DogShelter::DogShelter(int num){


dogs = new Dog*[num];
current_dogs = num;
memset(dogs,0,sizeof(Dog *) * num);

}
DogShelter::~DogShelter(){
  for(int i =0; i < current_dogs; i++){
    delete dogs[i];
  }
  delete [] dogs;
}
