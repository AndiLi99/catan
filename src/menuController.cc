#include "menuController.h"
#include "commandParser.h"
#include "gameState.h"
#include "defaultGridBuilder.h"
#include "randomGridBuilder.h"
#include "textDisplayObserver.h"
void MenuController::saveGame(){
    std::cout << "Not yet implemented" << std::endl;
}
void MenuController::loadGame(){
    std::cout << "Not yet implemented" << std::endl;
    
}
void MenuController::randomNew(std::vector<std::string> usernames){
    RandomGridBuilder randomBuilder;
    HexagonGrid hexGrid = randomBuilder.build();
    Board board{hexGrid};
    std::vector<Player> players;
    for (std::string username: usernames){
        players.push_back(Player{username});
    }
    DiceRoll dice;
    GameState gameState{board, players, dice};
    TextDisplay textDisplay{&gameState};
    CommandParser commandParser{&gameState};

    std::string input;
    while (std::getline(std::cin,input)){
        if (input == "q"){
            break;
        }
        commandParser.parse(input);
    }
}
void MenuController::defaultNew(std::vector<std::string> usernames){
    DefaultGridBuilder defBuilder;
    HexagonGrid hexGrid = defBuilder.build();
    Board board{hexGrid};

    std::vector<Player> players;
    for (std::string username: usernames){
        players.push_back(Player{username});
    }
    DiceRoll dice;
    GameState gameState{board, players, dice};
    TextDisplay textDisplay{&gameState};
    CommandParser commandParser{&gameState};

    std::string input;
    while (std::getline(std::cin,input)){
        if (input == "q"){
            break;
        }
        commandParser.parse(input);
    }
}
void MenuController::customNew(std::vector<std::string> usernames){
    std::cout << "Not yet implemented" << std::endl;
    
}