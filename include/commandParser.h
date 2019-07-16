#ifndef COMMANDPARSER 
#define COMMANDPARSER
#include <vector>
#include <string>
#include "gameState.h"

class CommandParser{
	//GameState g;
	std::vector <std::string> splitString(std::string,char);
	int commandOptions(std::string commandWord);
	void commandP(std::vector <std::string>);
	int commandPtoOptions(std::string commandWord);
	bool isValidCoord(int);
	int convertToInt(std::string);
	int commandBOptions(std::string);
	void commandB(std::vector<std::string>);
	int ConvertToDirections(std::string);
	void commandDirections(std::vector <std::string> input);
	std::string printInput(std::vector <std::string> input);
	void commandLR(std::vector <std::string> input, std::string);
public: 
	CommandParser(/*GameState &*/);
	~CommandParser();
	void parse(std::string);
};

#endif