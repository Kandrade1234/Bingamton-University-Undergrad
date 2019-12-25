#ifndef USER_H
#define USER_H
#include <string>

class User{

protected:
  std::string name;

public:
  User(); //we have to add default constructor
  User(std::string pname);
  std::string getName();

  //destructors
  ~User(); // never explicitely call the destructor. it is called automatically



}
#endif
