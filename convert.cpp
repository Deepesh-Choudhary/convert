#include <iostream>
#include <string>

#include "ArgParseException.h"
#include "ArgParser.h"
#include "conversions.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void printUsage() {
    cout <<
    "Usage: convert --<base1>2<base2> data\n"
    "Convert data from one base to another.\n\n"
    "<base> is one of the following:\n"
    "    bin    binary; base 2 (digits: 0-1)\n"
    "    dec    decimal; base 10 (digits: 0-9)\n"
    "    hex    hexadecimal; base 16 (digits: 0-9,A-F)\n"
    "NOTE: octal is not supported natively, but can be mimicked by converting to/from base 8.\n\n"
    "e.g. convert --hex2bin E2F4\n"
    "       converts E2F4 to binary"
    << endl;
}

void earlyExit(string msg, int returnCode) {
    std::cerr << "Error(" << returnCode << "): " << msg << endl;
    exit(returnCode);
}

int main(int argc, char *argv[]) {
    using namespace BaseConversions;

    if(argc < 3) {
        printUsage();
        return 1;
    }

    ArgParser ap(argc, argv, "P", "ft");
    try {
        ap.parse();
    } catch(ArgParseException ape) {
        earlyExit("APException: " + string(ape.what()), 2);
    }

    if(ap.getOperands().size() == 0)
        earlyExit("No data provided", 5);
    if(ap.getOperands().size() > 1)
        earlyExit("Only one string of data expected", 3);

    string data = ap.getOperands().at(0), output;
    
    //padding option
    bool padOutput = true;
    if(ap.isSwitchSet("P") || ap.isSwitchSet("no-pad"))
        padOutput = false;

    //pre-defined bases
    if(ap.isSwitchSet("bin2hex"))
        output = bin2hex(data, padOutput);
    else if(ap.isSwitchSet("bin2dec"))
        output = bin2dec(data);
    else if(ap.isSwitchSet("dec2bin"))
        output = dec2bin(data, padOutput);
    else if(ap.isSwitchSet("dec2hex"))
        output = dec2hex(data, padOutput);
    else if(ap.isSwitchSet("hex2bin"))
        output = hex2bin(data, padOutput);
    else if(ap.isSwitchSet("hex2dec"))
        output = hex2dec(data);
    else if(ap.isDataOptSet("f") || ap.isDataOptSet("from") ||
            ap.isDataOptSet("t") || ap.isDataOptSet("to")) {
        int fromBase;
        if(ap.isDataOptSet("f"))
            fromBase = stoi(ap.getDataForOpt("f"));
        else if(ap.isDataOptSet("from"))
            fromBase = stoi(ap.getDataForOpt("from"));
        else
            fromBase = 10;

        int toBase;
        if(ap.isDataOptSet("t"))
            toBase = stoi(ap.getDataForOpt("t"));
        else if(ap.isDataOptSet("to"))
            toBase = stoi(ap.getDataForOpt("to"));
        else
            toBase = 10;

        output = changeBase(data, fromBase, toBase, padOutput);
    } else {
        earlyExit("No bases specified", 4);
    }

    cout << output << endl;
    return 0;
}
