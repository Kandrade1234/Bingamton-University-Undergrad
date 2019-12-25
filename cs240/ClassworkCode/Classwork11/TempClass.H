//If writing template class then all declarations must go to header.  no cpp,  everything goes into header file.

template<class T>
Class Foo{
  T data;

public:
  Foo();

//Must specify the type to return.
Foo <T> clone();
T bar(T);



};
//Think of this t as a different scope, not the same
template <class T>
Foo<T> Foo<T> :: clone(){
  #implemented
}
//can be T but just to show for clarification we wrote J. Can be whatever you choose
template <class J>
J Foo<J>::bar(J){
  //implemented
}




/////THis goes in sperate file VVV/////
#include <iostream>
#include "TempClass.h"
using namespace std;
int main (){
  Foo <int> obj;
}
