#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#include <string>

namespace BaseConversions {
    /**
     * Converts the given string from given base to base 10.
     * Multiple literals may be seperated by space in input, the output will
     * then contain converted literals seperated by space.
     * 
     * @param str Input literals
     * @param fromBase Base to convert from; base the input is in
     */
    std::string toBase10(const std::string &str, const int fromBase);

    /**
     * Converts the given string from base 10 to given base.
     * Multiple literals may be seperated by space in input, the output will
     * then contain converted literals seperated by space.
     * 
     * @param str Input literals
     * @param toBase Base to convert to; base the input should be in
     */
    std::string fromBase10(const std::string &str, const int toBase);

    /**
     * Change the given string from given base to another base.
     * Multiple literals may be seperated by space in input, the output will
     * then contain converted literals seperated by space.
     * 
     * @param str Input literals
     * @param fromBase Base to convert from; base the input is in
     * @param toBase Base to convert to; base the output should be in
     */
    std::string changeBase(const std::string &str, const int fromBase, const int toBase);

    /**
     * Converts given binary string to a hexadecimal string.
     * Multiple literals may be seperatd by space in input, the output will
     * then contain converted literals seperated by space.
     * e.g. bin2hex("1010 1111") = "A F"
     * 
     * @param bin Binary literals
     * @return Converted hexadecimal literals
     */
    std::string bin2hex(const std::string &bin);

    /**
     * Converts given binary string to a decimal string.
     * Multiple literals may be seperatd by space in input, the output will
     * then contain converted literals seperated by space.
     * e.g. bin2dec("1010 1111") = "10 15"
     * 
     * @param bin Binary literals
     * @return Converted decimal literals
     */
    std::string bin2dec(const std::string &bin);

    /**
     * Converts given decimal string to a binary string.
     * Multiple literals may be seperatd by space in input, the output will
     * then contain converted literals seperated by space.
     * e.g. dec2bin("15 7") = "1111 0111"
     * 
     * @param dec Decimal literals
     * @return Converted decimal literals
     */
    std::string dec2bin(const std::string &dec);

    /**
     * Converts given decimal string to a hexadecimal string.
     * Multiple literals may be seperatd by space in input, the output will
     * then contain converted literals seperated by space.
     * e.g. dec2hex("65 255") = "41 FF"
     * 
     * @param dec Decimal literals
     * @return Converted hexadecimal literals
     */
    std::string dec2hex(const std::string &dec);

    /**
     * Converts given hexadecimal string to a binary string.
     * Multiple literals may be seperatd by space in input, the output will
     * then contain converted literals seperated by space.
     * e.g. hex2bin("F 41") = "1111 01000001"
     * 
     * @param hex Hexadecimal literals
     * @return Converted binary literals
     */
    std::string hex2bin(const std::string &hex);

    /**
     * Converts given hexadecimal string to a decimal string.
     * Multiple literals may be seperatd by space in input, the output will
     * then contain converted literals seperated by space.
     * e.g. hex2dec("F 41") = "15 65"
     * 
     * @param hex Hexadecimal literals
     * @return Converted decimal literals
     */
    std::string hex2dec(const std::string &hex);
}

#endif