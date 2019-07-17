#include "settlement.h"

Settlement::Settlement(int playerID): playerID{playerID}, productionRate{1} {}

int Settlement::ownedBy() const{
    return playerID;
}

void Settlement::upgradeToCity(){
    productionRate = 2;
}

int Settlement::getProductionRate(){
    return productionRate;
}

bool Settlement::isCity() const{
    return productionRate == 2;
}
