#ifndef TEXTDISPLAYOBSERVER
#define TEXTDISPLAYOBSERVER
#include "observer.h"

class GameState;

class TextDisplay: public Observer {
	GameState *subject;

	void printPlayers();
	void printBoard();
	void printResources();
	void printVictoryPoints();
	void printWin();
public:
	TextDisplay(GameState *);
	void notify() override;
	~TextDisplay();
};

#endif
