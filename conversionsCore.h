#ifndef CONVERSIONS_CORE_H
#define CONVERSIONS_CORE_H

#include <string>

/**
 * Core function for BaseConversions::toBase10().
 * CAUTION: This function is not meant to be used directly by the users.
 * Any usage with wrong/unexpected input may cause your code to break.
 * Use BaseConversions::toBase10() instead (see conversions.h).
 */
std::string toBase10Core(const std::string &str, const int fromBase);

/**
 * Core function for BaseConversions::fromBase10().
 * CAUTION: This function is not meant to be used directly by the users.
 * Any usage with wrong/unexpected input may cause your code to break.
 * Use BaseConversions::fromBase10() instead (see conversions.h).
 */
std::string fromBase10Core(const std::string &str, const int toBase);

#endif