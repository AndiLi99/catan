#ifndef ROAD_H
#define ROAD_H
#include <vector>
class Road{
        int playerID;
    public:
        Road(int playerID);
        int ownedBy() const;
        static const std::vector<int> cost;
};
#endif