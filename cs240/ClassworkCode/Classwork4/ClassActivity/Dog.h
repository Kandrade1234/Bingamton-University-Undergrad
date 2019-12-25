
#ifndef DOG_H
#define  DOG_H
#include <string>


Class Dog{
protected:
  std::string breed;
  std::string name;

public:
  Dog(){};
  Dog(std::string in);

  ~Dog();
  void bark();


};

Class Lab :: public Dog{
Lab(std::string);



};

#endif
