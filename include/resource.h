#ifndef RESOURCE_H
#define RESOURCE_H
#include <iosfwd>
enum class Resource{Wood, Brick, Wheat, Sheep, Stone};

std::ostream& operator<<(std::ostream& out, Resource resource);
#endif