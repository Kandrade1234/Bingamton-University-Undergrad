#ifndef ANT_H
#define ANT_H


class Ant{
	private:
		int id;
		int x;
		int y;
		int exp;
	public:
		//Ant(){id=-1;};
		Ant(int);
		int getID(){return this->id;}
		//write any additional functions on your own.
		void move();
		int getY(){return this->y;}
		int getX(){return this->x;}
		Ant* fight (Ant*);
};

#endif
