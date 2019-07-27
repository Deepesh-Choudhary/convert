#ifndef CONVERSIONS_CORE_H
#define CONVERSIONS_CORE_H

#include <string>

std::string toBase10Core(const std::string &str, const int fromBase);
std::string fromBase10Core(const std::string &str, const int toBase);

#endif