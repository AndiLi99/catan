#ifndef PLAYER
#define PLAYER
#include <vector>
#include <string>
#include "developmentDeck.h"
#include "devCard/devCard.h"
#include "hexagonGrid/edge.h"
#include "hexagonGrid/vertex.h"
#include "hexagonGrid/hexagon.h"


class Player{
	int victoryPoints;//to keep track of how many victory points there are
	std::vector <int> resources;//count to keep track of wood, sheep, stone, brick, wheat
	std::string username;
	int id;
	int purchasedRoads;
	int purchasedSettlements;
	int purchasedCities;
public:
	Player(std::string);
	int getVictoryPoints();
	void addVictoryPoints(int);
	void subtractVictoryPoints(int);

	void addRoad();
	void addSettlement();
	void addCity();
	void subtractRoad();
	void subtractSettlement();
	void subtractCity();

	void addResources(std::vector<int>);
	void subtractResources(std::vector<int>);
	bool hasAtLeast(std::vector<int>);
	std::vector<int> getResources();

	int handSize();
	std::string getUsername();
	~Player();
};
#endif