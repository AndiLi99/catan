#ifndef SIDE_H
#define SIDE_H
enum class Side{W, N, E};

std::ostream& operator<<(std::ostream& out, Side side);
#endif