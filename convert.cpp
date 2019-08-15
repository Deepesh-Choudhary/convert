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
    "Usage: convert [baseOptions] [-P|--no-pad] data\n"
    "Convert data from one base to another.\n\n"
    "baseOptions:\n"
    "  -f <base>, --from=<base>  convert the data from given base to base 10\n"
    "  -t <base>, --to=<base>    convert the data from base 10 to given base\n"
    "  --<base1>to<base2>        convert data from & to predefined bases\n"
    "NOTE: If --<base1>to<base2> option is not set, -t or -f or both HAVE to be set.\n"
    "      If either is omitted, it is taken to be 10.\n\n"
    "Predefined bases:\n"
    "  bin    binary; base 2 (digits: 0-1)\n"
    "  dec    decimal; base 10 (digits: 0-9)\n"
    "  hex    hexadecimal; base 16 (digits: 0-9,A-F/a-f)\n"
    "  oct    octal; base 8 (digits: 1-8)\n\n"
    "Other options:\n"
    "  -P, --no-pad  do NOT pad the output, default setting pads output\n"
    "  -h, --help    show this help message\n\n"
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

    ArgParser ap(argc, argv, "Ph", "ft");
    try {
        ap.parse();
    } catch(ArgParseException ape) {
        earlyExit("APException: " + string(ape.what()), 2);
    }

    if(ap.isSwitchSet("h") || ap.isSwitchSet("help")) {
        printUsage();
        return 0;
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
    else if(ap.isSwitchSet("bin2oct"))
        output = bin2oct(data, padOutput);
    else if(ap.isSwitchSet("bin2dec"))
        output = bin2dec(data);
    else if(ap.isSwitchSet("oct2bin"))
        output = oct2bin(data, padOutput);
    else if(ap.isSwitchSet("oct2dec"))
        output = oct2dec(data);
    else if(ap.isSwitchSet("oct2hex"))
        output = oct2hex(data, padOutput);
    else if(ap.isSwitchSet("dec2bin"))
        output = dec2bin(data, padOutput);
    else if(ap.isSwitchSet("dec2oct"))
        output = dec2oct(data, padOutput);
    else if(ap.isSwitchSet("dec2hex"))
        output = dec2hex(data, padOutput);
    else if(ap.isSwitchSet("hex2bin"))
        output = hex2bin(data, padOutput);
    else if(ap.isSwitchSet("hex2oct"))
        output = hex2oct(data, padOutput);
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
