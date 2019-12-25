#ifndef Cat_H
#define Cat_H
//^^^^^^^ Has to be the first lines of code in your headers.
//NEVER PUT USING NAMESPACE STD IN HEADER CODE BECAUSE SOMEONE ELSE MIGHT END UP USING YOUR HEADER
#include "test.h"
#include <string>

class Cat{
  //By default everything is private unless you specify labels.
private:
  std:: string name;
public:
  int bark (int x, int y);

//you can use multiple privates/labels(recomended to keep only one label of each)
private:
  int x;

  //protected: only current class and any subclasses can use methods.
};

#endif
