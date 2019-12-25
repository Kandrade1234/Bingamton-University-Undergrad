#include <iostream>
#include <cstdlib>


using namespace std;
//Replace every type with template class T. if you have int a = b; -> now you get T a = b;

//This is a delcaration (not prototype)
template <class T>
T maximum(T a, T b, T c){
  T max = a;
  if(b > max) max = b;
  else if(c > max) max = c;
  return max ;
}
int main(){
  std::cout << maximum(1,2,3) << std::endl;
  std::cout << maximum(1.0,2.0,3.0) << std::endl;

  std::cout << maximum('a','b','c') << std::endl;


}
