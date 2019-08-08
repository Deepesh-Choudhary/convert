#include "ArgParser.h"
#include "ArgParseException.h"

#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

void ArgParser::processOperand() {
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
        switchesSet.push_back(string(opt));
    } else {
        ++sIter;    //skip the '='

        while(sIter != arg.end())
            data += *sIter++;

        addDataOptPair(opt, data);
    }

    ++commonIter;
}

inline bool ArgParser::isSwitch(const char option) {
    return std::find(allSwitches.begin(), allSwitches.end(), option) != allSwitches.end();
}

inline bool ArgParser::isDataOpt(const char option) {
    return std::find(allDataOpts.begin(), allDataOpts.end(), option) != allDataOpts.end();
}

void ArgParser::addDataOptPair(string opt, string data) {
    //if option already exists, throw exception
    for(std::pair<string, string> p : dataOptsSet)
        if(p.first == opt)
            throw ArgParseException("Re-occurence of data option");

    //otherwise add the pair
    dataOptsSet.push_back(std::make_pair(opt, data));
}
