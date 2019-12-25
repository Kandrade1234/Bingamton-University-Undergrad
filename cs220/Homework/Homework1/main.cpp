using namesapce std;



int main(){

  User u;
  User * u2 = new User("Bob");
  cout << u.getName() << endl;
  cout << u2->getName() <<endl;
  delete u2;


}
