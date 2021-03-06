#include "commandParser.h"
#include "gameState.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

//takes in a string sentence to tokenizes into individual words
vector <string> CommandParser::splitString(string str, char delim){
	vector<string> cont;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delim)) {
        cont.push_back(token);
    }

    return cont;

}

//constructor
CommandParser::CommandParser(GameState* gameState):gameState{gameState}{
	gameState->notifyObservers();
}

//destructor
CommandParser::~CommandParser(){}

//conversion of string command to corresponding integer
//needed because switch statements only take integers
int CommandParser::commandOptions(string commandWord){
	if(commandWord == "b"){return 1;}
	if(commandWord == "p"){return 2;}
	if(commandWord == "m"){return 3;}
	if(commandWord == "r"){return 4;}
	if(commandWord == "e"){return 5;}
	if(commandWord == "t"){return 6;}
	if(commandWord == "s"){return 7;}
	return -1;
}

//for options related to p
int CommandParser::commandPtoOptions(string commandWord){
	if(commandWord == "r"){return 1;}
	if(commandWord == "s"){return 2;}
	if(commandWord == "c"){return 3;}
	if(commandWord == "d"){return 4;}

	return -1;
}

//switch statment relating to the second command in p (p r/s/c/d)
void CommandParser::commandP(vector <string> input){
	enum Options {r = 1, s = 2, c = 3, d = 4};
	//p has already been validated, need to validate second character in command
	switch(commandPtoOptions(input[1])){
		case r:	cout<<printInput(input)<<endl;
				gameState->purchaseRoad();
				break;
		case s:	cout<<printInput(input)<<endl;
				gameState->purchaseSettlement();
				break;
		case c:	cout<<printInput(input)<<endl;
				gameState->purchaseCity();
				break;
		case d:	cout<<printInput(input)<<endl;
				break;
		default:
				cout << "p * command not valid" << endl;
				break;
	}
}

//check to see if coordinate is within the range of valid coordinates for each hexagon
bool CommandParser::isValidCoord(int val){
	if (val == -2 || val == -1 || val == 0 || val == 1 || val == 2){
		return true;
	}
	return false;
}

//converts a string value to an integer value
int CommandParser::convertToInt(string val){
	//might need to throw if not valid int conversion
	stringstream converter(val);
	int temp = 0;
	converter >> temp;

	if(converter.fail()){
		//if the value is not convertable
		return -10;
	}

	return temp;
}

//conversion of string command to a corresponding integer needed for enumeration and switch statements
int CommandParser::commandBOptions(string val){
	if(val == "r"){return 1;}
	if(val == "s"){return 2;}
	if(val == "c"){return 3;}
	return -1;
}

//conversion of string command to a corresponding integer needed for enumeration and switch statements
int CommandParser::ConvertToDirections(string val){
	if(val == "W"){return 1;}
	if(val == "N"){return 2;}
	if(val == "E"){return 3;}
	if(val == "L"){return 4;}
	if(val == "R"){return 5;}
	return -1;
}

//prints the input that was given
string CommandParser::printInput(vector <string> input){
	string sentence;
	for(auto it = input.begin(); it !=input.end(); ++it){
		sentence=sentence+*it+" ";
	}

	return sentence;
}

//final call commands to Gamestate object for command b r
void CommandParser::commandDirections(vector <string> input){
	int a = convertToInt(input[2]);
	int b = convertToInt(input[3]);
	cout << "a: " << a << " b: " << b << endl;
	enum Options{W = 1, N = 2, E = 3, L = 4, R = 5};
	switch(ConvertToDirections(input[4])){
		case W:cout<<printInput(input)<<endl;
				if (!gameState->validRoad(Edge{a, b, Side::W})){
					cout <<"Error: b r coordinate values not valid"<<endl;
					break;
				}
		 		gameState->buildRoad(Edge{a, b, Side::W});
				break;
		case N:cout<<printInput(input)<<endl;
				if (!gameState->validRoad(Edge{a, b, Side::N})){
					cout <<"Error: b r coordinate values not valid"<<endl;
					break;
				}
		 		gameState->buildRoad(Edge{a, b, Side::N});
			   break;
		case E:cout<<printInput(input)<<endl;
				if (!gameState->validRoad(Edge{a, b, Side::E})){
					cout <<"Error: b r coordinate values not valid"<<endl;
					break;
				}
		 		gameState->buildRoad(Edge{a, b, Side::E});
			   break;
		default:
				cout << "Error: b r Command, Direction not Valid"<<endl;
				break;

	}
}

//final call commands to Gamestate object for command b s
void CommandParser::commandLR(vector <string> input, string typeOfSettlement){
	int a = convertToInt(input[2]);
	int b = convertToInt(input[3]);
		enum Options{L = 4, R = 5};
	switch(ConvertToDirections(input[4])){
		case R:
				if (!gameState->validSettlement(Vertex{a, b, Corner::R})){
					cout <<"Error: b r coordinate values not valid"<<endl;
					break;
				}
				if(typeOfSettlement == "city"){
					cout<<printInput(input)<<" city"<<endl;
					gameState->buildCity(Vertex{a, b, Corner::R});
					}
				else{
					cout<<printInput(input)<<" settlement"<<endl;
					gameState->buildSettlement(Vertex{a, b, Corner::R});
					}
					break;
		case L:
				if (!gameState->validSettlement(Vertex{a, b, Corner::L})){
					cout <<"Error: b r coordinate values not valid"<<endl;
					break;
				}
				if(typeOfSettlement == "city"){
					cout<<printInput(input)<<" city"<<endl;
					gameState->buildCity(Vertex{a, b, Corner::L});
					}
				else{
					cout<<printInput(input)<<" settlement"<<endl;
					gameState->buildSettlement(Vertex{a, b, Corner::L});
					}
					break;
		default:
				cout << "Error: b s/c Command, Direction not Valid"<<endl;
				break;

	}
}

//second switch statement for options relating to b command (b /r/s/c a b /W/N/E/L/R)
void CommandParser::commandB(vector <string> input){
	enum Options{r = 1, s = 2, c = 3};
	switch(commandBOptions(input[1])){
		case r:
				commandDirections(input);//call specified gamestate function
				break;
		case s: 
				commandLR(input, "settlement");//call specified gamestate function
				break;
		case c:
				commandLR(input, "city");//call specified gamestate function
				break;
		default:cout<<"Error:not valid b * command"<<endl;
				break;
	}
}

//function which takes in the user command and calls the associated gameState object.
void CommandParser::parse(string input){

	vector <string> parsedString;
	//splits the string input into a vector of strings
	parsedString = splitString(input,' ');
	//assigning integer values to first input case
	enum Options {b = 1, p = 2, m = 3, r = 4, e = 5, t = 6, s = 7};

	//switch statement to determine the first value in the command
	switch(commandOptions(parsedString[0])){
		case b: 
				if(parsedString.size() == 5){
					commandB(parsedString);
				}
				else{cout<<"Error:too many b commands"<<endl;}
				break;
		case p:
				if (parsedString.size()==2){commandP(parsedString);}
				else{cout << "Error:not a valid p command"<<endl;}
				break;
		case m:
				if(parsedString.size() == 4){
					if(parsedString[1] == "r"){
						//convert inputs to integers
						int a = convertToInt(parsedString[2]);
						int b = convertToInt(parsedString[3]);

						if (isValidCoord(a) && isValidCoord(b)){
							cout<<printInput(parsedString)<<endl;
							gameState->moveRobber(Hexagon{a, b});
						}
						else{
							cout <<"Error: m r coordinate values not valid"<<endl;
						}

					}
					else{cout<<"Error: m * commnd not valid"<<endl;}
				}
				else{cout<<"Error: too many m commands"<<endl;}
				break;
		case r:
				if(parsedString.size() == 1){
					cout<<printInput(parsedString)<<endl;
					gameState->rollDice();
				}
				else{cout<<"Error: too many r commands"<<endl;}
				break;
		case e:
				if(parsedString.size() == 1){
					cout<<printInput(parsedString)<<endl;
					gameState->endTurn();
					}
				else{cout<<"Error: too many e commands"<<endl;}
				break;
		case t:
				if(parsedString[1] == "p" && parsedString.size() == 2){/*g.tradeLater()*/}
				else{cout<<"Error:t command not valid"<<endl;}
				break;
		case s:
		{
				int playerID = convertToInt(parsedString[1]);
				gameState->stealResource(playerID);
				break;
		}
		default:
				cout <<"Error: invalid first command"<<endl;
				break;
	}
	gameState->notifyObservers();
}

