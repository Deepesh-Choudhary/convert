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
string fromBase10Core(const string &str, const int toBase) {
    string result;
    int num = std::stoi(str);

    while(num != 0) {
        result += letterFor(num % toBase);
        num /= toBase;
    }

    if(result == "")
        result = "0";
    
    std::reverse(result.begin(), result.end());
    return result;
}