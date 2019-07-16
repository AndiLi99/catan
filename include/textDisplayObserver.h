#ifndef TEXTDISPLAYOBSERVER
#define TEXTDISPLAYOBSERVER
#include "observer.h"

class GameState;

class TextDisplay: public Observer {
	GameState *subject;

	void printPlayers();
	void printBoard();
	void printCoordBoard();
	void printResources();
	void printVictoryPoints();
	void printWin();
	void printGame();
public:
	TextDisplay(GameState *);
	void notify() override;
	~TextDisplay();
};

#endif
