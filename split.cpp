#include "split.h"

#include <cctype>
#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::vector;

static inline bool isSpace(char c) {
    return isspace(c);
}

static inline bool notSpace(char c) {
    return !isspace(c);
}

vector<string> split(string str) {
    vector<string> words;

    string::iterator start, end;
    start = end = str.begin();

    while(end != str.end()) {
        start = find_if(end, str.end(), notSpace);
        end = find_if(start, str.end(), isSpace);

        if(start == str.end())
            break;

        words.push_back(string(start, end));
    }

    return words;
}