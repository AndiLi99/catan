#ifndef SETTLEMENT_H
#define SETTLEMENT_H
#include <vector>
class Settlement{
        int playerID;
        int productionRate;
    public:
        Settlement(int playerID);
        int ownedBy() const;
        void upgradeToCity();
        int getProductionRate() const;
        bool isCity() const;
        static const std::vector<int> cost;
        static const std::vector<int> upgradeCost;
};
#endif