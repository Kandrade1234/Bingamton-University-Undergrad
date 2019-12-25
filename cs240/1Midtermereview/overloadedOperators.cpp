
//Okay to use global variable for something that will never change
int PI = 3.14; //exists in entire program, not just this file.
class Foo{
public:
    int num;
    char * string;

    Foo(){
      memset(array, 0, sizeof(int)*5);//initializing the array with a bunch of zeros.
      string = new char[10];
      num = 0;
    }

    ~Foo{
      delete[] string;

    }
    //make sure to put it as reference
    boolean operator == (const Foo &o){
      return this->num == o->num;
    }

//if we do not have a copy constructpor, then this will use the default copy constructpor
//and it will make a shallow copy and not a deep copy resulting in false calculations
    boolean operator == (const Foo o){
      o->num = 6;
      //(*o).num = 6 //same thing.
      return this->num == o->num;
    }




}


int main (int argc, char const *argv[]){
  //Stack memory is automatically allocated and deallocated after function call
  int x;
  int * y = new int;
  delete y

  Foo fstack, fstack2;

  //operating overloading
if(fstack == fstack2){


}


  Foo() fstack;
  Foo * fheap = new Foo();
//correct
  delete fheap;

//incorrect. memory leak dont do what is coded on the next line.
  fheap->~Foo();

  return 0;
}
