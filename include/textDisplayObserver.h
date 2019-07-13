#ifndef TEXTDISPLAYOBSERVER
#define TEXTDISPLAYOBSERVER
#include "observer.h"

class TextDisplay: public Observer {
	gameState *subject;

	void printPlayers();
	void printBoard();
	void printResources();
	void printVictoryPoints();
	void printWin();
public:
	TextDisplay(gameState *);
	void notify() override;
	~TextDisplay();
};

#endif
