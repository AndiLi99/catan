#include "settlement.h"

Settlement::Settlement(int playerID): playerID{playerID}, productionRate{1} {}

int Settlement::ownedBy() const{
    return playerID;
}

void Settlement::upgradeToCity(){
    productionRate = 2;
}

int Settlement::getProductionRate()const{
    return productionRate;
}

bool Settlement::isCity() const{
    return productionRate == 2;
}

const std::vector<int> Settlement::upgradeCost{0,0,2,0,3};
const std::vector<int> Settlement::cost{1,1,1,1,0};