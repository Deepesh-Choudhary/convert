#include "mapping.h"

#include <iostream>
#include <cstdlib>

int valueOf(char letter) {
    if(letter >= '0' && letter <= '9')
        return static_cast<int>(letter) - 48;
    else if(letter >= 'A' && letter <= 'Z')
        return static_cast<int>(letter) - 55;
    else if(letter >= 'a' && letter <= 'z')
        return static_cast<int>(letter) - 87;
    else {
        std::cerr << "Invalid Argument" << std::endl;
        std::exit(0);
    }
}

char letterFor(int value) {
    if(value >= 0 && value <= 9)
        return static_cast<char>(value + 48);
    else if(value <= 35)
        return static_cast<char>(value + 55);
    else {
        std::cerr << "Invalid Argument" << std::endl;
        std::exit(0);
    }
}