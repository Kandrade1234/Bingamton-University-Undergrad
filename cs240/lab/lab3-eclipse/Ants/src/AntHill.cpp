#include "AntHill.h"
#include <iostream>
#include <cstdlib>

#define BUFFER_MAX 100

using namespace std;



AntHill::AntHill(){
    ants = NULL;
    this->current_ants = 0;
    this->next_id = 0;
}
AntHill::~AntHill(){
    for(int i =0; i < current_ants; i++){
        delete ants[i];
    }
    delete [] ants;
}

int AntHill::addAnt(){
    
    if(ants == NULL)
    {
        ants = new Ant * [1];
        Ant * obj = new Ant (next_id);
        ants [0] = obj;
        this->current_ants+=1;
        this->next_id+=1;
        return ants[0]->getID();
    }
    else{
        Ant ** nArr = new  Ant * [current_ants+1];
        
        for(int i =0; i < current_ants; i++){
            nArr[i] = ants[i];
        }
        Ant * obj = new Ant (next_id);
        current_ants+=1;
        next_id+=1;
        delete [] ants;
        ants = nArr;
        nArr = NULL;
        ants[current_ants-1] = obj;
        /*
         nArr[size_growth] = obj;
         delete [] ants;
         ants = nArr;
         nArr = NULL;
         this->current_ants+=1;
         this->next_id +=1;*/
    }
    return ants[current_ants-1]->getID();
    
    
}
bool AntHill::removeAnt(int id){
    
    for (int i = 0; i < current_ants; i++)
    {
        if (ants[i]->getID() == id)
        {
            Ant ** newArray = new Ant * [current_ants-1];
            std::copy(ants, ants+i, newArray);
            std::copy(ants+i+1, ants+current_ants, newArray+i);
            delete[] ants;
            ants = newArray;
            --current_ants;
            return true;
        }
    }
    return false;
}

Ant * AntHill:: getAnt(int id){
    for (int i =0; i < current_ants; i++){
        if(ants[i]->getID() == id){
            return ants[i];
        }
    }
    return NULL;
}
void AntHill::move(){
    for(int i =0; i <current_ants; i++){
        ants[i]->move();
    }
}



void AntHill::printHillInfo(){
    for(int i =0; i < current_ants; i++){
        cout <<"Ant #" << ants[i]->getID() << " [" <<ants[i]->getX()<<"," <<ants[i]->getY() << "]\n";
    }
}
