#ifndef CORNER_H
#define CORNER_H
#include <iostream>
enum class Corner{L, R};

std::ostream& operator<<(std::ostream& out, Corner corner){
    switch(corner){
        case Corner::L: return out << 'L';
        case Corner::R: return out << 'R';
    }
}
#endif