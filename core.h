#ifndef CORE_H
#define CORE_H

#include <string>
#include <vector>

class BaseConversionsCore {
    friend class BaseConversions;

    std::vector<std::string> split(std::string str);

    std::string toBase10Core(std::string str, int fromBase);
    std::string fromBase10Core(std::string str, int toBase);
    std::string changeBaseCore(std::string str, int fromBase, int toBase);

    std::string bin2hexCore(std::string bin);
    std::string bin2decCore(std::string bin);

    std::string dec2binCore(std::string dec);
    std::string dec2hexCore(std::string dec);

    std::string hex2binCore(std::string hex);
    std::string hex2decCore(std::string hex);
};

#endif