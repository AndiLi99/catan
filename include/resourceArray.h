#include <vector>
#include "resource.h"

class ResourceArray{
        std::vector<int> resources;
    public:
        ResourceArray(int lumber, int brick, int grain, int sheep, int ore);
        std::vector<int> get();
        void addResource(Resource res, int num);
};