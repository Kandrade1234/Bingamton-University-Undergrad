#ifndef ANTHILL_H
#define ANTHILL_H
#include "Ant.h"


class AntHill{
private:
    int current_ants;
    Ant ** ants;
    int next_id; //[Optional] A mechanism for keeping track of the next ID to 					assign an ant. There are many way to accomplish this. You are 					free to come up with your own solution as long as the ID’s are 					unique and integers.
public:
    AntHill();
    ~AntHill();
    int addAnt();
    bool removeAnt(int);
    Ant * getAnt(int);
    void move();
    bool changeMax(int);
    void printHillInfo();
    int getCurrentNumAnts(){
        return this->current_ants;
    }
    
};

#endif
