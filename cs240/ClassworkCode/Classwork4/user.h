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



};



//inheritance   vv you can change to public, private, protected. By changing public to other
//names(protected, private, etc) you are saying that you will inherit USERS public function(not private) and make those functions
//whatever you specefied below into the new class.
class Admin : public User{



}
#endif
