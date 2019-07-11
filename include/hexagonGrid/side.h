#ifndef SIDE_H
#define SIDE_H
#include <iostream>
enum class Side{W, N, E};

std::ostream& operator<<(std::ostream& out, Side side){
    switch(side){
        case Side::W: return out << 'W';
        case Side::N: return out << 'N';
        case Side::E: return out << 'E';
    }
}
#endif