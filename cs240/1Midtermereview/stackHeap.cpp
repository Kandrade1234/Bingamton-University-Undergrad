
//Okay to use global variable for something that will never change
int PI = 3.14; //exists in entire program, not just this file.
class Foo{
public:
    int array[5];
    char * string;

    Foo(){
      memset(array, 0, sizeof(int)*5);//initializing the array with a bunch of zeros.
      string = new char[10];
    }

    ~Foo{
      delete[] string;

    }



}


int main (int argc, char const *argv[]){
  //Stack memory is automatically allocated and deallocated after function call
  int x;
  int * y = new int;
  delete y

  Foo() fstack;
  Foo * fheap = new Foo();
//correct
  delete fheap;

//incorrect. memory leak dont do what is coded on the next line.
  fheap->~Foo();

  return 0;
}
