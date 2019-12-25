#include "DogShelter.h"
#include <iostream>

using namespace std;

int main(){
  Dog * butter = new Dog ("Alaskan Malamute");
  Dog * peanut = new Dog("Chihuahua");



  DogShelter ds(3);
  ds.addDog(butter);
  ds.addDog(peanut);
  ds.adopt(1);
}
