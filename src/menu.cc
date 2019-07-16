#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "menu.h"

using namespace std;

//Constructor
Menu::Menu(){}
//Destructor
Menu::~Menu(){}

//takes in a string sentence to tokenizes into individual words
vector <string> Menu::splitString(string str, char delim){
	vector<string> cont;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delim)) {
        cont.push_back(token);
    }

    return cont;

}

int Menu::ConvertToOption(string val){
	if(val == "s"){return 1;}
	if(val == "l"){return 2;}
	if(val == "n"){return 3;}
	return -1;
}

int Menu::NConvertToOption(string val){
	if(val == "d"){return 1;}
	if(val == "r"){return 2;}
	if(val == "c"){return 3;}
	return -1;
}

bool Menu::tail(string const& source, size_t const length) {
	string fileExtension = source.substr(source.size() - length);
	if(fileExtension == ".txt" && length <= source.size()){
		return true;
	}
	return false;
}

bool Menu::isFileValid(string fileName){
	if (tail(fileName,4)){
		return true;
	}
	else{
		return false;
	}
}

void Menu::NOptions(vector <string> input){
	enum Options{d = 1, r = 2, c = 3};
	switch(NConvertToOption(input[1])){
		case d:	cout<<"Success: n d"<<endl;
				//call function();
				break;
		case r:	cout<<"Success: n r"<<endl;
				//call function();
				break;
		case c:	cout<<"Success: n c"<<endl;
				//call function();
				break;
		default:cout<<"Error: not a valid n command"<<endl;
				break;
	}
}

//prints out menu to commandline
void Menu::printMenu(){
	cout <<"==============================================================="<<endl;
	cout <<"Welcome to Catan!"<<endl;
	cout <<"Input one of the following options into the commandline"<<endl;
	cout <<"==============================================================="<<endl;
	cout <<"Option 1: s (insert_file_name).txt - save game progress to file"<<endl;
	cout <<"Option 2: l (insert_file_name).txt - load  saved game"<<endl;
	cout <<"Option 3: n d - create new game, bowl"<<endl;
	cout <<"Option 4: n r - create new game, random legal setup"<<endl;
	cout <<"Option 5: n c - create new game, enter custom board editing"<<endl;
	cout <<"==============================================================="<<endl;
}

//parse user input for menu options
void Menu::parse(string input){

	vector <string> parsedString;
	//splits the string input into a vector of strings
	parsedString = splitString(input,' ');

	enum menuOptions{s = 1, l = 2, n = 3};

	switch(ConvertToOption(parsedString[0])){
		case s:	if(parsedString.size() == 2){
					if(isFileValid(parsedString[1])){
						//call save function();
						cout<<"Success:game saved"<<endl;
					}
					else{cout<<"Error: file name not valid"<<endl;}
				}
				else{cout<<"Error: s command, too many arguments"<<endl;}
				break;
		case l:	if(parsedString.size() == 2){
					if(isFileValid(parsedString[1])){
						//call load function();
						cout<<"Success:game loaded"<<endl;
					}
					else{cout<<"Error: file name not valid"<<endl;}
				}
				else{cout<<"Error: l command, too many argyments"<<endl;}
				break;
		case n:	if(parsedString.size() == 2){
					//call second switch statement
					NOptions(parsedString);
				}
				else{cout<<"Error: n command, too many arguments"<<endl;}
				break;
		default:cout<<"Error:invalid menu command"<<endl;
				break;
	}
}

