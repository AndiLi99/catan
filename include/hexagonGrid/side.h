#ifndef SIDE_H
#define SIDE_H
#include <iosfwd>
enum class Side{W, N, E};

std::ostream& operator<<(std::ostream& out, Side side);
#endif