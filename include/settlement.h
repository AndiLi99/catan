#ifndef SETTLEMENT_H
#define SETTLEMENT_H

#include "harvester.h"
class Settlement: Harvester{
    public:
        int productionRate() override{
            return 1;
        }
};
#endif