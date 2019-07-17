#include "road.h"

Road::Road(int playerID): playerID{playerID}{}
int Road::ownedBy() const{
    return playerID;
}