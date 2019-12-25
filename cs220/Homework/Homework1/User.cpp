#include "User.h"
#include <iostream>
#include <string>



using namespace std;

User::User(){

}
User::User(std::string pname) {
  name = pname;
}

string User:: getName(){
  return name;
}
User::~User(){
  cout<<"Destroyed"<< endl;
}
