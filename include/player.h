<<<<<<< HEAD
=======

>>>>>>> 0111750f3e132fe30703a2ca1f5df022fb9be1f0
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
	//std::vector <DevCard> developmentCards;
	
	std::vector <Edge> roads;
	std::vector <Vertex> settlements;
	std::vector <Vertex> cities;

	int knightsUsed;

	std::string username;
	int id;
	bool isEnough(int);


public:
	Player(std::string);
	void showVictoryPoints();
	void addVictoryPoint(int);
	void subtractVictoryPoint(int);

	void showResources();
	void buildRoad(Edge, bool);
	void buildSettlement(Vertex);
	void upgradeToCity(Vertex);
	//void buyDevCard(developmentDeck&);

	//void showDevCard();
	//void useDevCard(int i);

	void addResource(int,int,int,int,int);
	void subtractResource(int,int,int,int,int);
	~Player();
};
#endif