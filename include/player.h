#ifndef PLAYER
#define PLAYER
#include <vector>
#include <string>
#include "developmentDeck.h"
#include "devCard/devCard.h"
#include "hexagonGrid/edge.h"
#include "hexagonGrid/vertex.h"
#include "hexagonGrid/hexagon.h"
#include "resource.h"

class Player{
	int victoryPoints;//to keep track of how many victory points there are
	std::vector <int> resources;//count to keep track of wood, sheep, stone, brick, wheat
	std::string username;
	int purchasedRoads;
	int purchasedSettlements;
	int purchasedCities;
	int roadsLeft;
	int settlementsLeft;
	int citiesLeft;
public:
	Player(std::string);
	int getVictoryPoints();
	void addVictoryPoints(int);
	void subtractVictoryPoints(int);

	bool canPurchaseRoad();
	bool canPurchaseSettlement();
	bool canPurchaseCity();
	bool canBuildRoad();
	bool canBuildSettlement();
	bool canBuildCity();
	void addRoad();
	void addSettlement();
	void addCity();
	void subtractRoad();
	void subtractSettlement();
	void subtractCity();
	std::vector<int> getUnbuilt();

	void subResource(Resource resource);
	void addResource(Resource resource);
	void addResources(std::vector<int>);
	void subtractResources(std::vector<int>);
	bool hasAtLeast(std::vector<int>);
	std::vector<int> getResources();

	Resource stealResource();
	int handSize();
	std::string getUsername();
	~Player();
};
#endif