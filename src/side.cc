#include <iostream>
#include "hexagonGrid/side.h"

std::ostream& operator<<(std::ostream& out, Side side){
    switch(side){
        case Side::W: return out << 'W';
        case Side::N: return out << 'N';
        case Side::E: return out << 'E';
    }
}