#ifndef CITY_H
#define CITY_H

#include "harvester.h"
class City: Harvester{
    public:
        int productionRate() override{
            return 2;
        }
};
#endif