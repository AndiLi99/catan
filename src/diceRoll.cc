#include "../include/diceRoll.h"
#include <stdlib.h>
#include <time.h>

//constructor
DiceRoll::DiceRoll(){}

//destructor
DiceRoll::~DiceRoll(){}

//generates and returns the sum of two dice rolls
int DiceRoll::rollDice() const{

	srand(time(0));//initialize random sequence
	int diceVal1 = rand()%6+1;
	int diceVal2 = rand()%6+1;

	return diceVal1+diceVal2;
}