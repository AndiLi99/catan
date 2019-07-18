#include "player.h"
#include "road.h"
#include "settlement.h"
#include <random>
using namespace std;

Player::Player(string username):resources{vector{0,0,0,0,0}}, username{username}{
	purchasedCities = 0;
	purchasedSettlements = 0;
	purchasedRoads = 0;
	victoryPoints = 0;
}

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

Resource Player::stealResource(){
	srand(time(0));
	int random = rand() % handSize();
	int sum = 0;
	for (int res = 0; res < 5; ++res){
		sum += resources[res];
		if (random < sum) return static_cast<Resource>(res);
	}
}
void Player::addResource(Resource resource){
	++resources[resource];
}
void Player::addResources(vector<int> add){
	resources[0]+=add[0];
	resources[1]+=add[1];
	resources[2]+=add[2];
	resources[3]+=add[3];
	resources[4]+=add[4];
}
void Player::subtractResources(vector<int> add){
	resources[0]-=add[0];
	resources[1]-=add[1];
	resources[2]-=add[2];
	resources[3]-=add[3];
	resources[4]-=add[4];
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

bool Player::canPurchaseRoad(){
	return hasAtLeast(Road::cost);
}
bool Player::canPurchaseSettlement(){
	return hasAtLeast(Settlement::cost);
}
bool Player::canPurchaseCity(){
	return hasAtLeast(Settlement::upgradeCost);
}
bool Player::canBuildRoad(){
	return purchasedRoads > 0;
}
bool Player::canBuildSettlement(){
	return purchasedSettlements > 0;
}
bool Player::canBuildCity(){
	return purchasedCities > 0;
}
std::vector<int> Player::getUnbuilt(){
	return std::vector<int>{purchasedRoads, purchasedSettlements, purchasedCities};
}
