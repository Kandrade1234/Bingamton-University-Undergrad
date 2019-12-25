#include "Dog.h"

#include<iostream>
#include<string>

using namespace std;

int main(){


  Dog * d = new Dog("penut");
  Lab l("Butter");
  l.bark()
  d->bark();

  delete d;


}
