#include "mapping.h"

#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using std::string;

/**
 * Algorithm: Raise the base to successive powers and multiply
 * the result by numbers starting sequentially from right side.
 */
string toBase10Core(const string &str, const int fromBase) {
    int power = 0, result = 0;
    for(auto iter = str.rbegin(); iter != str.rend(); ++iter)
        result += valueOf(*iter) * std::pow(fromBase, power++);

    return std::to_string(result);
}

/**
 * Algorithm: Divide the number by base and store the remainders
 * in reverse order. Remainders are represented by digits and
 * alphabets.
 */
string fromBase10Core(const string &str, const int toBase, bool padOutput) {
    string result;
    int num = std::stoi(str);

    while(num != 0) {
        result += letterFor(num % toBase);
        num /= toBase;
    }

    if(result == "")
        result = "0";
    
    std::reverse(result.begin(), result.end());

    if(!padOutput)
        return result;

    //pad the output
    string temp;
    if(toBase == 2)                             //binary; chunks of 8 digits
        temp = string(8 - (result.size() % 8), '0');
    else if(toBase == 8 && result.size() < 3)   //octal; at least 3 digits
        temp = string(3 - result.size(), '0');
    else if(toBase == 16)                       //hexadecimal; chunks of 2 digits
        temp = string(result.size() % 2, '0');

    return temp+result;
}