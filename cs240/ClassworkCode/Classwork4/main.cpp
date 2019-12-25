using namesapce std;



int main(){

  User u;
  User * u2 = new User("Bob");
  cout << u.getName() << endl;
  cout << u2->getName() <<endl;

  //More on pointers
  User * u2;
  u2 =0 ;

  
  cout << *u2 << endl;

}
