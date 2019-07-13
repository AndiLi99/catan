#ifndef QUEST
#define QUEST
#include <string>

class Quest{
	std::string player;
public:
	Quest();
	~Quest();
	std::string getPlayer();
	void checkCondition(/*gameState & game*/);

};

#endif