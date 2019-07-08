#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include <string>

class BaseConversions {
public:
    std::string toBase10(std::string str, int fromBase);
    std::string fromBase10(std::string str, int toBase);
    std::string changeBase(std::string str, int fromBase, int toBase);

    std::string bin2hex(std::string bin);
    std::string bin2dec(std::string bin);

    std::string dec2bin(std::string dec);
    std::string dec2hex(std::string dec);

    std::string hex2bin(std::string hex);
    std::string hex2dec(std::string hex);
};

#endif