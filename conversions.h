#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include <string>

namespace BaseConversions {
    std::string toBase10(const std::string &str, const int fromBase);
    std::string fromBase10(const std::string &str, const int toBase);
    std::string changeBase(const std::string &str, const int fromBase, const int toBase);

    std::string bin2hex(const std::string &bin);
    std::string bin2dec(const std::string &bin);

    std::string dec2bin(const std::string &dec);
    std::string dec2hex(const std::string &dec);

    std::string hex2bin(const std::string &hex);
    std::string hex2dec(const std::string &hex);
}

#endif