#ifndef MENU
#define MENU
#include <string>
#include <vector>

class Menu{
	bool tail(std::string const& , size_t const);
	std::vector <std::string> splitString(std::string, char );
	void NOptions(std::vector <std::string>);
	int NConvertToOption(std::string val);
	int ConvertToOption(std::string val);
	bool isFileValid(std::string);
public:
	Menu();
	~Menu();
	void printMenu();
	void parse(std::string);
};

#endif
