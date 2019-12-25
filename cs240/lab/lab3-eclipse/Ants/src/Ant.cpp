#include "Ant.h"
#include <iostream>
#include <cstdlib>


using namespace std;

Ant::Ant(int id){
    this->id = id;
    this->x = this->y = 0;
    exp = 100;
}

void Ant::move(){
    int random = rand() %4+1;
    if(random == 1) this->x-=1; 	//left cordinate
    else if (random == 2) this->x+=1;	//right cordinate
    else if (random ==3) this->y+=1;	//up cordinate
    else this->y-=1;  			//down cordinate
}

Ant* Ant:: fight (Ant* opponent){
    int random = rand() %4+1;;
    
    
    //50/50 chance to win if both have equal exp
    if(this->exp == opponent->exp)
    {
        if(random <=2){
            this->exp += opponent->exp;
            return opponent;
        }
        else { //if(random > 2) --- opponent wins!
            opponent->exp += this->exp;
            return this;
        }
    }
    
    //This has more exp
    else if (this->exp > opponent->exp)
    {
        //if this ant has more exp then odds are 3 to 1 of winning.
        if(random <=3){
            this->exp += opponent->exp;
            return opponent;
        }
        //only has a chance of 1 to 3
        else {
            opponent->exp += this->exp;
            return this;
        }
    }
    
    //Opponent has more exp
    else
    {
        if(random <=3)
        {
            opponent->exp += this->exp;
            return this;
        }
        //only has a chance of 1 to 3
        else
        {
            this->exp += opponent->exp;
            return opponent;
        }
    }
    
    
    
    
    
}