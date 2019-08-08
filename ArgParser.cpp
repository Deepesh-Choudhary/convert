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

//private member functions
inline void ArgParser::processOperand() {
    operands.push_back(*commonIter++);
}

void ArgParser::processSingleDash() {
    string arg = *commonIter;
    string::const_iterator sIter = arg.begin() + 1;    //skip the '-'
    bool theEnd = false;

    //e.g. in '-gfwa', loop through all the switches until 'a',
    //'a' it might be a data option!
    while(sIter + 1 != arg.end()) {
        if(!isSwitch(*sIter))
            throw ArgParseException("Invalid switch: " + string(1, *sIter));

        switchesSet.push_back(string(1, *sIter));
        ++sIter;
    }

    if(isSwitch(*sIter))
        switchesSet.push_back(string(1, *sIter));
    else if(isDataOpt(*sIter)) {
        ++commonIter;
        string data;
        bool comeback = false;

        if(commonIter != args.end()) {
            data = *commonIter;

            //if next argument is an option, set data to empty string
            if(data[0] == '-') {
                data = "";
                comeback = true;    //and we need to come back to process this option
            }
        } else {
            data = "";  //no data provided with option
            theEnd = true;  //and we have reached the end of args
        }

        addDataOptPair(string(1, *sIter), data);
        if(comeback)
            --commonIter;   //now process that option  
    } else
        throw ArgParseException("Invalid option: " + string(1, *sIter));

    if(!theEnd)
        ++commonIter;   //if it's not the end, move on to next arg
}

void ArgParser::processDoubleDash() {
    string arg = *commonIter;
    string::const_iterator sIter = arg.begin() + 2;     //skip the '--'
    string data, opt;

    while(sIter != arg.end() && *sIter != '=')
        opt += *sIter++;

    if(sIter == arg.end()) {
        switchesSet.push_back(opt);
    } else {
        ++sIter;    //skip the '='

        while(sIter != arg.end())
            data += *sIter++;

        addDataOptPair(opt, data);
        ++commonIter;
    }
}

inline bool ArgParser::isSwitch(const char option) {
    return find(allSwitches.begin(), allSwitches.end(), option) != allSwitches.end();
}

inline bool ArgParser::isDataOpt(const char option) {
    return find(allDataOpts.begin(), allDataOpts.end(), option) != allDataOpts.end();
}

void ArgParser::addDataOptPair(string opt, string data) {
    //if option already exists, throw exception
    for(std::pair<string, string> p : dataOptsSet)
        if(p.first == opt)
            throw ArgParseException("Re-occurence of data option");

    //otherwise add the pair
    dataOptsSet.push_back(std::make_pair(opt, data));
}