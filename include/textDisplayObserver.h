#ifndef TEXTDISPLAYOBSERVER
#define TEXTDISPLAYOBSERVER
#include "observer.h"

#include "hexagonGrid/hexagon.h"
#include "hexagonGrid/edge.h"
#include "hexagonGrid/vertex.h"

class GameState;

class TextDisplay: public Observer {
	GameState* gameState;

	std::vector<Hexagon> hexPrintOrder;
	std::vector<Edge> edgePrintOrder;
	std::vector<Vertex> vertexPrintOrder;

	std::string getTileNum(Hexagon hex);
	char getTileType(Hexagon hex);
	char getRoad(Edge road);
	std::string getSettlement(Vertex vert);

	std::vector<std::string> getTileNums();
	std::vector<char> getTileTypes();
	std::vector<char> getRoads();
	std::vector<std::string> getSettlements();
	void printPlayers();
	void printCoordBoard();
	void printResources();
	void printVictoryPoints();
	void printWin();
	void printGame();
	void printBoard();
public:
	TextDisplay(GameState* gameState);
	void notify() override;
	~TextDisplay();
};

#endif
