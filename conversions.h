#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include <string>

class BaseConversions {
public:
    static std::string toBase10(std::string str, int fromBase);
    static std::string fromBase10(std::string str, int toBase);
    static std::string changeBase(std::string str, int fromBase, int toBase);

    static std::string bin2hex(std::string bin);
    static std::string bin2dec(std::string bin);

    static std::string dec2bin(std::string dec);
    static std::string dec2hex(std::string dec);

    static std::string hex2bin(std::string hex);
    static std::string hex2dec(std::string hex);
};

#endif