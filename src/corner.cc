#include<iostream>
#include "hexagonGrid/corner.h"

std::ostream& operator<<(std::ostream& out, Corner corner){
    switch(corner){
        case Corner::L: return out << 'L';
        case Corner::R: return out << 'R';
    }
}