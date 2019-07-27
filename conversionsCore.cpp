#include "mapping.h"

#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using std::string;

string toBase10Core(const string &str, const int fromBase) {
    int power = 0, result = 0;
    for(string::const_iterator iter = str.begin(); iter != str.end(); ++iter)
        result += valueOf(*iter) * pow(fromBase, power++);

    return std::to_string(result);
}

string fromBase10Core(const string &str, const int toBase) {
    string result;
    int num = std::stoi(str);

    while(num != 0) {
        result += letterFor(num % toBase);
        num /= toBase;
    }

    std::reverse(result.begin(), result.end());
    return result;
}