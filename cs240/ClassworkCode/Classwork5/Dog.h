#ifndef DOG_H
#define  DOG_H

class Dog{
  public:
    std::string breed;
    int id;
  public:
    Dog(){id = -1};
    Dog(std::string id);
    string getID(){
      return id;
    }

}

class DogShelter{
  private:
    int current_dogs;
    //every instance of shelter share this unique next_id
    static int next_id;
    Dog ** shelter;

  public:
    DogShelter();
    DogShelter(int max);

}


#endif
