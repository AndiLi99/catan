
#ifndef DEVCARD
#define DEVCARD
#include <string>
#include <vector>
#include "../player.h"

class DevCard{
	//pure virtual to be overridden by derived classes (for unique usage)
	//virtual void useCard(Player&, std::vector<Player&>) = 0;
	std::string name;//name of development card, knight, progress of vicPoint

public:
	DevCard();
	void playCard();
	std::string getName() const;
	virtual ~DevCard();

};

#endif
