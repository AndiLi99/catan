#ifndef MENU
#define MENU
#include <string>
#include <vector>

class MenuController;

class Menu{
	MenuController* controller;
	bool tail(std::string const& , size_t const);
	std::vector <std::string> splitString(std::string, char );
	void NOptions(std::vector <std::string>);
	int NConvertToOption(std::string val);
	int ConvertToOption(std::string val);
	bool isFileValid(std::string);
	void saveGameHook();
	void loadGameHook();
	void randomNewHook(std::vector<std::string> usernames);
	void defaultNewHook(std::vector<std::string> usernames);
	void customNewHook(std::vector<std::string> usernames);
public:
	Menu(MenuController* controller);
	~Menu();
	void printMenu();
	void parse(std::string);
};

#endif
