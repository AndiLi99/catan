#ifndef TEXTDISPLAYOBSERVER
#define TEXTDISPLAYOBSERVER
#include "observer.h"

#include "hexagonGrid/hexagon.h"
#include "hexagonGrid/edge.h"
#include "hexagonGrid/vertex.h"

class GameState;

class TextDisplay: public Observer {
	GameState& gameState;

	vector<Hexagon> hexPrintOrder;
	vector<Edge> edgePrintOrder;
	vector<Vertex> vertexPrintOrder;

	std::string getTileNum(Hexagon hex);
	char getTileType(Hexagon hex);
	char getRoad(Edge road);
	string getSettlement(Vertex vert);

	vector<std::string> getTileNums();
	vector<char> getTileTypes();
	vector<char> getRoads();
	vector<string> getSettlements();
	void printPlayers();
	void printBoard();
	void printCoordBoard();
	void printResources();
	void printVictoryPoints();
	void printWin();
	void printGame();
public:
	TextDisplay(GameState& gameState);
	void notify() override;
	~TextDisplay();
};

#endif
