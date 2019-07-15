#include "../include/player.h"
#include <iostream>

//need to add development deck and dev cards

using namespace std;

//default constructor
Player::Player(string username):resources{0}, username{username}, knightsUsed{0}{
	//have to initialize victoryPoints to 0, the vector of resources to zero
	for (int i = 0; i < 5; i++){
		resources.emplace_back(0);
	}
}

//destructor
Player::~Player(){}

void Player::showVictoryPoints(){
	cout << username << " has " << victoryPoints <<" victory points." << endl;
}

void Player::addVictoryPoint(int value){
	victoryPoints = victoryPoints+value;
}

void Player::subtractVictoryPoint(int value){
	victoryPoints = victoryPoints-value;
}

void Player::showResources(){
	cout << username << " has:" <<endl;
	cout << "===================" <<endl;
	cout << resources[0] << " wood"<<endl;
	cout << resources[1] << " sheep"<<endl;
	cout << resources[2] << " stone"<<endl;
	cout << resources[3] << " brick"<<endl;
	cout << resources[4] << " wheat"<<endl;
	cout << "===================" <<endl;
}

//make sure the player has enough resources to build/buy
bool Player::isEnough(int i){
	enum PaymentOption {road = 0, settlement = 1, city = 2, developmentCard = 3};
	//mapping each count value stored in resource vector to specific resource variable
	int wood = resources[0];
	int sheep = resources[1];
	int stone = resources[2];
	int brick = resources[3];
	int wheat = resources[4];

	switch(i){
		case road:
			//brick and wood
			if(brick > 0 && wood > 0){return true;}
			else{return false;}
			break;
		case settlement:
			//brick, wood, wheat, sheep
			if(brick > 0 && wood > 0 && wheat > 0 && sheep > 0){return true;}
			else{return false;}
			break;
		case city:
			//2 wheat, 3 stone
			if(wheat >= 2 && stone >= 3){return true;}
			else{return false;}
			break;
		case developmentCard:
			//sheep, wheat, stone
			if(sheep > 0 && wheat > 0 && stone > 0){return true;}
			else{return false;}
			break;
		default:
			return false;
			break;
	}

	return false;
}

void Player::addResource(int wood, int sheep, int stone, int brick, int wheat){
	resources[0]+=wood;
	resources[1]+=sheep;
	resources[2]+=stone;
	resources[3]+=brick;
	resources[4]+=wheat;

}

void Player::subtractResource(int wood, int sheep, int stone, int brick, int wheat){
	//need to check that all resources are not less than zero
	resources[0]-=wood;
	resources[1]-=sheep;
	resources[2]-=stone;
	resources[3]-=brick;
	resources[4]-=wheat;
}


void Player::buildRoad(Edge r, bool isProgressCard){
	//add check to see if player has enough resources
	int road = 0;
	if(isEnough(road)){
		//add function to modify board
		//add function to add an edge co-ordinate to road
		roads.emplace_back(r);
		//subtrack the resources used
		subtractResource(1,0,0,1,0);
	}
	else{
		throw "not enough resources to build new road";
	}
}

void Player::buildSettlement(Vertex s){
	//add check to see if player has enough resources
	int settlement = 1;
	if(isEnough(settlement)){
		//add function to modify board
		//add function to add an edge co-ordinate to road
		settlements.emplace_back(s);
		//subtract the resources used: brick, wood, wheat, sheep
		subtractResource(1,1,0,1,1);
	}	
	else{
		throw "not enough resources to build new settlement";
	}
}

void Player::upgradeToCity(Vertex c){
	//add check to see if player has enough resources
	int city = 2;
	if(isEnough(city)){
		//add function to modify board
		//add function to add an edge co-ordinate to road
		cities.emplace_back(c);
		//subtract the resources used: 3 stone, 2 wheat
		subtractResource(0,0,3,0,2);
	}	
	else{
		throw "not enough resources to upgrade city";
	}
}
/*
void Player::buyDevCard(developmentDeck & cardDeck){
	//add check to see if player has enough resources
	int developmentCard = 3;
	if(isEnough(developmentCard)){
		//draw from development deck: sheep, wheat, stone
		//DevCard card = cardDeck.drawCard();
		//developmentCards.emplace_back(card);
		subtractResource(0,1,1,0,1);
		//cout << card.name << " was drawn"<<endl;
	}
	else{
		throw "not enough resources to buy development card";
	}
<<<<<<< HEAD
}
=======

}

>>>>>>> 0111750f3e132fe30703a2ca1f5df022fb9be1f0
void Player::showDevCard(){
	//must change to iterator in the future
	for (int i = 0; i < developmentCards.size(); i++){
		cout << "Option" << i << ": " << developmentCards[i].getName() << endl;
	}
}
<<<<<<< HEAD
=======

>>>>>>> 0111750f3e132fe30703a2ca1f5df022fb9be1f0
//takes in the
void Player::useDevCard(int i){
	developmentCards.at(i).playCard();//
}
<<<<<<< HEAD
*/