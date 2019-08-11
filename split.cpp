#include "split.h"

#include <cctype>
#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::vector;

static inline bool isSpace(const char c) {
    return std::isspace(c);
}

static inline bool notSpace(const char c) {
    return !std::isspace(c);
}

vector<string> split(const string &str) {
    vector<string> words;

    string::const_iterator start = str.begin(), end = str.begin();

    while(end != str.end()) {
        start = std::find_if(end, str.end(), notSpace);
        end = std::find_if(start, str.end(), isSpace);

        if(start == str.end())
            break;

        words.push_back(string(start, end));
    }

    return words;
}