#ifndef SETTLEMENT_H
#define SETTLEMENT_H

class Settlement{
        int playerID;
        int productionRate;
        static const int MAX_UPGRADES = 1;
    public:
        Settlement(int playerID);
        int ownedBy();
        void upgradeToCity();
        int getProductionRate();
        bool isCity();
};
#endif