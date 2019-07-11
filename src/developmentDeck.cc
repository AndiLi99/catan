#include "../include/developmentDeck.h"
#include "../include/devCard/devCard.h"
#include "../include/devCard/knight.h"
#include "../include/devCard/yearOfPlenty.h"
#include "../include/devCard/monopoly.h"
#include "../include/devCard/buildRoad.h"
#include "../include/devCard/victoryPoint.h"

#include <stdlib.h>
#include <time.h>

//generate a number from 1-3 to a corresponding development card
int developmentDeck::cardGenerator(){
	srand(time(0));//initialize a random sequence
	return (rand()%5+1);
}


//constructor, takes in integer values to keep track of how many knight, progress and victory point cards there are
developmentDeck::developmentDeck(int k, int p, int m, int r, int v):knight{k}, yearOfPlenty{p}, monopoly{m}, roadBuilding{r}, vicPoint{v}{}

//destructor
developmentDeck::~developmentDeck(){}

//given a cardNum, checks to see that the card is still in the deck
bool developmentDeck::isCardInDeck(int cardNum){
	switch (cardNum)
	{
		case 1: if(knight > 0){return true;}
				else{return false;}
				break;
		case 2: if(yearOfPlenty > 0){return true;}
				else{return false;}
				break;
		case 3: if(monopoly > 0){return true;}
				else{return false;}
				break;
		case 4: if(roadBuilding > 0){return true;}
				else{return false;}
				break;
		case 5: if(vicPoint > 0){return true;}
				else{return false;}
				break;
		default: break;
	}

	return false;
}

//returns to the player, a development card
void developmentDeck::drawCard(){

	if (knight <= 0 && yearOfPlenty <= 0 && monopoly <= 0 && roadBuilding <= 0 && vicPoint <= 0){
		//throw an exception where there are no more cards
		throw "no more cards in deck";
	}

	int cardNum = cardGenerator();//generate a card value from 1-3

	//check if the value is valid
	while(!isCardInDeck(cardNum)){
		cardNum = cardGenerator();
	}
	
	switch (cardNum)
	{
		case 1:	knight--;
				//return knightCard;
				break;
		case 2: yearOfPlenty--;
				//return progressCard
				break;
		case 3: monopoly--;
				//return progressCard
				break;
		case 4: roadBuilding--;
				//return progressCard
				break;
		case 5: vicPoint--;
				//return victoryCard;
		default://return empty card 
				break;
	}

}