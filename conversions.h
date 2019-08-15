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
     * @param padOutput If set to true, output is padded to match byte-size
     */
    std::string fromBase10(const std::string &str, const int toBase, bool padOutput = false);

    /**
     * Change the given string from given base to another base.
     * Multiple literals may be seperated by space in input, the output will
     * then contain converted literals seperated by space.
     * 
     * @param str Input literals
     * @param fromBase Base to convert from; base the input is in
     * @param toBase Base to convert to; base the output should be in
     * @param padOutput If set to true, output is padded to match byte-size(only for bases 2, 8 & 16)
     */
    std::string changeBase(const std::string &str, const int fromBase, const int toBase, bool padOutput = false);

    /**
     * Converts given binary string to a hexadecimal string.
     * Multiple literals may be seperatd by space in input, the output will
     * then contain converted literals seperated by space.
     * e.g. bin2hex("1010 1111") = "A F"
     * 
     * @param bin Binary literals
     * @param padOutput If set to true, output is padded to match byte-size
     * @return Converted hexadecimal literals
     */
    std::string bin2hex(const std::string &bin, bool padOutput = false);

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
     * Converts given binary string to an octal string.
     * Multiple literals may be seperatd by space in input, the output will
     * then contain converted literals seperated by space.
     * e.g. bin2oct("1010 1111") = "12 17"
     * 
     * @param bin Binary literals
     * @param padOutput If set to true, output is padded to at least 3 digits
     * @return Converted octal literals
     */
    std::string bin2oct(const std::string &bin, bool padOutput = false);

    /**
     * Converts given octal string to a binary string.
     * Multiple literals may be seperatd by space in input, the output will
     * then contain converted literals seperated by space.
     * e.g. oct2bin("21 34") = "10001 11100"
     * 
     * @param oct Octal literals
     * @param padOutput If set to true, output is padded to match byte-size
     * @return Converted binary literals
     */
    std::string oct2bin(const std::string &oct, bool padOutput = false);

    /**
     * Converts given octal string to a decimal string.
     * Multiple literals may be seperatd by space in input, the output will
     * then contain converted literals seperated by space.
     * e.g. oct2dec("21 34") = "17 28"
     * 
     * @param oct Octal literals
     * @return Converted decimal literals
     */
    std::string oct2dec(const std::string &oct);

    /**
     * Converts given octal string to a hexadecimal string.
     * Multiple literals may be seperatd by space in input, the output will
     * then contain converted literals seperated by space.
     * e.g. oct2hex("21 34") = "11 1C"
     * 
     * @param oct Octal literals
     * @param padOutput If set to true, output is padded to match byte-size
     * @return Converted hexadecimal literals
     */
    std::string oct2hex(const std::string &oct, bool padOutput = false);

    /**
     * Converts given decimal string to a binary string.
     * Multiple literals may be seperatd by space in input, the output will
     * then contain converted literals seperated by space.
     * e.g. dec2bin("15 7") = "1111 111"
     * 
     * @param dec Decimal literals
     * @param padOutput If set to true, output is padded to match byte-size
     * @return Converted decimal literals
     */
    std::string dec2bin(const std::string &dec, bool padOutput = false);

    /**
     * Converts given decimal string to an octal string.
     * Multiple literals may be seperatd by space in input, the output will
     * then contain converted literals seperated by space.
     * e.g. bin2oct("21 34") = "25 42"
     * 
     * @param dec Decimal literals
     * @param padOutput If set to true, output is padded to at least 3 digits
     * @return Converted octal literals
     */
    std::string dec2oct(const std::string &dec, bool padOutput = false);

    /**
     * Converts given decimal string to a hexadecimal string.
     * Multiple literals may be seperatd by space in input, the output will
     * then contain converted literals seperated by space.
     * e.g. dec2hex("65 255") = "41 FF"
     * 
     * @param dec Decimal literals
     * @param padOutput If set to true, output is padded to match byte-size
     * @return Converted hexadecimal literals
     */
    std::string dec2hex(const std::string &dec, bool padOutput = false);

    /**
     * Converts given hexadecimal string to a binary string.
     * Multiple literals may be seperatd by space in input, the output will
     * then contain converted literals seperated by space.
     * e.g. hex2bin("F 41") = "1111 1000001"
     * 
     * @param hex Hexadecimal literals
     * @param padOutput If set to true, output is padded to match byte-size
     * @return Converted binary literals
     */
    std::string hex2bin(const std::string &hex, bool padOutput = false);

    /**
     * Converts given hexadecimal string to an octal string.
     * Multiple literals may be seperatd by space in input, the output will
     * then contain converted literals seperated by space.
     * e.g. bin2oct("21 34") = "41 64"
     * 
     * @param hex Hexadecimal literals
     * @param padOutput If set to true, output is padded to at least 3 digits
     * @return Converted octal literals
     */
    std::string hex2oct(const std::string &hex, bool padOutput = false);

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