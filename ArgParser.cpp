#include "ArgParser.h"
#include "ArgParseException.h"

#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

ArgParser::ArgParser() : finalized(false) {
}

ArgParser::ArgParser(const int argc, char *argv[],
    const string switches, const string dataOptions)
    : allSwitches(switches), allDataOpts(dataOptions) {

    for(int i = 0; i < argc; ++i)
        args.push_back(string(argv[i]));

    commonIter = args.begin();
    finalized = true;
}

void ArgParser::operator()(const int argc, char *argv[],
    const string switches, const string dataOptions) {
        if(!finalized) {
            for(int i = 0; i < argc; ++i)
                args.push_back(string(argv[i]));

            allSwitches = switches;
            allDataOpts = dataOptions;

            commonIter = args.begin();
            finalized = true;
        }
    }

void ArgParser::parse() {
    ++commonIter;       //first arg is the program name, skip it
    string arg;

    while(commonIter != args.end()) {
        arg = *commonIter;
        if(arg[0] != '-')               //matches 'op', 'f.txt' etc.
            processOperand();
        else if(arg.length() == 1)      //matches (only) '-'
            processOperand();
        else if(arg[1] != '-')          //mathes '-c', '-dRe' etc.
            processSingleDash();
        else if(arg.length() == 2)      //matches (only) '--'
            processOperand();
        else                            //matches '--reedirect', '--file=name' etc
            processDoubleDash();
    }
}

inline bool ArgParser::isSwitchSet(string svitch) const {
    return std::find(switchesSet.begin(), switchesSet.end(), svitch) != switchesSet.end();
}

bool ArgParser::isDataOptSet(string dataOption) const {
    for(std::pair<string, string> p : dataOptsSet)
        if(p.first == dataOption)
            return true;
        
    return false;
}

inline bool ArgParser::isSet(string option) const {
    return isSwitchSet(option) || isDataOptSet(option);
}

string ArgParser::getDataForOpt(string option) const {
    for(std::pair<string, string> p : dataOptsSet)
        if(p.first == option)
            return p.second;

    return "";
    //TODO:throw exception - no such option set
}

vector<string> ArgParser::getSwitches() const {
    return switchesSet;
}

vector<string> ArgParser::getDataOptions() const {
    vector<string> dataOpts(dataOptsSet.size(), "");
    int n = 0;

    for(std::pair<string, string> p : dataOptsSet)
        dataOpts[n++] = p.first;

    return dataOpts;
}

vector<string> ArgParser::getAllOptions() const {
    vector<string> options;

    std::copy(switchesSet.begin(), switchesSet.end(), std::back_inserter(options));
    for(std::pair<string, string> p : dataOptsSet)
        options.push_back(p.first);

    return options;
}

vector<string> ArgParser::getOperands() const {
    return operands;
}