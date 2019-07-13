#ifndef CORNER_H
#define CORNER_H
#include <iosfwd>
enum class Corner{L, R};

std::ostream& operator<<(std::ostream& out, Corner corner);
#endif