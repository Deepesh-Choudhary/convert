#include "conversions.h"
#include "split.h"
#include "conversionsCore.h"

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

//1. Split the given string into constituent literals
//2. Use core function on each literal
//3. Join the resultant literals(seperated by space) and return the result
string BaseConversions::toBase10(const string &str, const int fromBase) {
    if(fromBase < 2) {
        std::cerr << "Invalid base" << std::endl;
        std::exit(101);
    } else if(fromBase == 10) {
        return str;
    }

    bool firstResult = false;   //helps in seperating output literals by spaces
    string result;
    vector<string> words = split(str);
    
    for(string word : words) {
        if(firstResult)
            firstResult = false;
        else     //if this is not the first result, add a space before it
            result += " ";

        result += toBase10Core(word, fromBase);
    }

    return result;
}

//1. Split the given string into constituent literals
//2. Use core function on each literal
//3. Join the resultant literals(seperated by space) and return the result
string BaseConversions::fromBase10(const string &str, const int toBase, bool padOutput) {
    if(toBase < 2) {
        std::cerr << "Invalid base" << std::endl;
        std::exit(0);
    } else if(toBase == 10) {
        return str;
    }

    bool firstResult = false;    //helps in seperating output literals by spaces
    string result;
    vector<string> words = split(str);
    
    for(string word : words) {
        if(firstResult)
            firstResult = false;
        else     //if this is not the first result, add a space before it
            result += " ";
        
        result += fromBase10Core(word, toBase, padOutput);
    }

    return result;
}

string BaseConversions::
    changeBase(const string &str, const int fromBase, const int toBase, bool padOutput) {
    //convert the string from given base to base 10,
    //then convert that string from base 10 to given base
    return fromBase10(toBase10(str, fromBase), toBase, padOutput);
}

//use dictionary instead?
string BaseConversions::bin2hex(const string &bin, bool padOutput) {
    return BaseConversions::changeBase(bin, 2, 16, padOutput);
}

string BaseConversions::bin2dec(const string &bin) {
    return BaseConversions::changeBase(bin, 2, 10);
}

string BaseConversions::dec2bin(const string &dec, bool padOutput) {
    return BaseConversions::changeBase(dec, 10, 2, padOutput);
}

string BaseConversions::dec2hex(const string &dec, bool padOutput) {
    return BaseConversions::changeBase(dec, 10, 16, padOutput);
}

//use dictionary instead?
string BaseConversions::hex2bin(const string &hex, bool padOutput) {
    return BaseConversions::changeBase(hex, 16, 2, padOutput);
}

string BaseConversions::hex2dec(const string &hex) {
    return BaseConversions::changeBase(hex, 16, 10);
}
