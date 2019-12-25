#include "Table.h"
#include <vector>
using namespace std;

Table::Table (int num_seats, int ante){
  this->ante = ante;
  this->numSeats = num_seats;
  this->deck = Deck();
//  winner = Player();
}
vector<Player> Table::playRound(){
  deck = Deck();  //reinitialize the deck
  deck.shuffle(); //shuffled deck
ls

  for(std::vector<Player>::iterator i = seats.begin(); i != seats.end();i++){
      if((*i).bet(ante)) (*i).hand = deck.draw();
  }
  Player winner = evaluateCards();  //Determines winner
  eliminated(winner);
  int size = seats.size(); //5
  winner.collectWinnings(ante * size);

  for(int  i = 0; i < size;i++)
    seats.pop_back();	//CLEAR OUT THE SEATS

  seats.push_back(winner);  //REINSERT THE WINNER

  return losers;
  //return a vector of the loosers (make temp one)
  //winner stays at table while loosers leave(pop)
}
bool Table::emptySeat(){
  return (int)seats.size() < numSeats;
}

void Table::addPlayer(Player p){
  if(emptySeat()){
    if(p.getBudget() > ante){
      seats.push_back(p);
      }
    }
}
//Returns a copy of the winning player
Player Table::evaluateCards(){
Player winner = Player(seats[0].getName(), seats[0].getBudget());
  for(std::vector<Player>::iterator i = seats.begin(); i != seats.end();i++)
  {
    if(winner.hand < (*i).hand){
      winner = Player((*i).getName(), (*i).getBudget());
      winner.setHand((*i).hand.getSuit(), (*i).hand.getValue());
    }
  }
  return winner;
//  cout<< winner.getName() <<" THIS IS THE WINNER \n";
}

//Returns a vector with all the loosers in the vector with the winner as a parameter
void Table :: eliminated(Player winner){
  losers.clear();
  for(std::vector<Player>::iterator  i = seats.begin(); i != seats.end();i++)
  {
    if(!((*i).getName() == winner.getName())) //If NOT the winner then add to loser vector
    {
      losers.push_back(*i);
    }
  }
}

void Table :: printWinner(){
  cout << seats[0].getName() << " WON! with : " << seats[0].getBudget() << endl;
}
