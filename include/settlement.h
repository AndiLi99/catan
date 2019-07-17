#ifndef SETTLEMENT_H
#define SETTLEMENT_H

class Settlement{
        int playerID;
        int productionRate;
    public:
        Settlement(int playerID);
        int ownedBy() const;
        void upgradeToCity();
        int getProductionRate();
        bool isCity() const;
};
#endif