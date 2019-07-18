#ifndef MENU_CONTROLLER_H
#define MENU_CONTROLLER_H

#include <vector>
#include <string>

class MenuController{
    public:
        void saveGame();
        void loadGame();
        void randomNew(std::vector<std::string> usernames);
        void defaultNew(std::vector<std::string> usernames);
        void customNew(std::vector<std::string> usernames);
};
#endif