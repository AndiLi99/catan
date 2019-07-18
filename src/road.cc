#include "road.h"

Road::Road(int playerID): playerID{playerID}{}
int Road::ownedBy() const{
    return playerID;
}

const std::vector<int> Road::cost{1,1,0,0,0};