#include "player.h"
using namespace std;

Player::Player(string username):resources{vector{0,0,0,0,0}}, username{username}{}

//destructor
Player::~Player(){}

void Player::addVictoryPoints(int value){
	victoryPoints += value;
}

void Player::subtractVictoryPoints(int value){
	victoryPoints -= value;
}

int Player::getVictoryPoints(){
	return victoryPoints;
}

void Player::addResources(vector<int> add){
	resources[0]+=add[0];
	resources[1]+=add[1];
	resources[2]+=add[2];
	resources[3]+=add[3];
	resources[4]+=add[4];
}
void Player::subtractResources(vector<int> add){
	resources[0]+=add[0];
	resources[1]+=add[1];
	resources[2]+=add[2];
	resources[3]+=add[3];
	resources[4]+=add[4];
}
bool Player::hasAtLeast(vector<int> least){
	return 
	resources[0]>=least[0]&&
	resources[1]>=least[1]&&
	resources[2]>=least[2]&&
	resources[3]>=least[3]&&
	resources[4]>=least[4];
}

int Player::handSize(){
	int sum = 0;
	for (int i: resources){
		sum += i;
	}
	return sum;
}

vector<int> Player::getResources(){
	return resources;
}

string Player::getUsername(){
	return username;
}

void Player::addRoad(){
	++purchasedRoads;
}

void Player::addSettlement(){
	++purchasedSettlements;
}

void Player::addCity(){
	++purchasedCities;
}
void Player::subtractRoad(){
	--purchasedRoads;
}

void Player::subtractSettlement(){
	--purchasedSettlements;
}

void Player::subtractCity(){
	--purchasedCities;
}
// void Player::showResources(){
// 	cout << username << " has:" <<endl;
// 	cout << "===================" <<endl;
// 	cout << resources[0] << " wood"<<endl;
// 	cout << resources[1] << " sheep"<<endl;
// 	cout << resources[2] << " stone"<<endl;
// 	cout << resources[3] << " brick"<<endl;
// 	cout << resources[4] << " wheat"<<endl;
// 	cout << "===================" <<endl;
// }

// void Player::showVictoryPoints(){
// 	cout << username << " has " << victoryPoints <<" victory points." << endl;
// }