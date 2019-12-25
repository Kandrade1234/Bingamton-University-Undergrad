/* ------------------------------------------------------------------
Pick marbles from a jar that contains a mixture of:
	100 red marbles,
	100 blue marbles, and
	100 green marbles.


How many marbles did you need to pick to get 10 red?

-------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int redMarbles=100;
int greenMarbles=100;
int blueMarbles=100;

char pickMarble() {
	char picked='?';
	int tot = redMarbles + greenMarbles + blueMarbles;
	assert(tot>0);
	int choice = rand()%tot; // Choice is a random number 0 <= choice < tot
	if (choice<redMarbles) {
		redMarbles = redMarbles - 1;
		// printf("Picked a red marble\n");
		picked='r';
	}
	else if (choice<redMarbles+greenMarbles) {
		greenMarbles = greenMarbles - 1;
		// printf("Picked a green marble\n");
		picked='g';
	}
	else {
		blueMarbles = blueMarbles - 1;
		// printf("Picked a blue marble\n");
		picked='b';
	}
	return picked;
}

int pick10Red() {
	/* Reset Jar with initial conditions */
	redMarbles=100;
	greenMarbles=100;
	blueMarbles=100;
	int numPicked=0;
	while(redMarbles>90) {
		pickMarble();
		numPicked=numPicked+1;
	}
	printf("Got 10 red marbles after picking %d marbles.\n",numPicked);
	return numPicked;
}

int main(int argc, char ** argv) {
	if (argc>1) { srand(atoi(argv[1])); } // Seed random number
	int numTries=0;
	int totPicked=0;
	while(numTries<100) {
		totPicked = totPicked + pick10Red();
		numTries=numTries+1;
	}
	float avgPicked = (float)totPicked/numTries;
	printf("Got 10 red marbles after picking and average of %f marbles.\n",avgPicked);
	return 0;
}
