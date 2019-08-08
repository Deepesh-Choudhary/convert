#include <iostream>
#include <string>
#include <vector>

#include "ArgParseException.h"
#include "ArgParser.h"
#include "conversions.h"
#include "test.h"

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::vector;

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
    std::cerr << "Error: " << msg << endl;
    exit(returnCode);
}

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printUsage();
        return 1;
    }

    ArgParser ap(argc, argv, "", "");
    try {
        ap.parse();
    } catch(ArgParseException ape) {
        earlyExit("APException: " + string(ape.what()), 2);
    }

    if(ap.getOperands().size() > 1)
        earlyExit("Only one string of data expected", 3);

    string data = ap.getOperands().at(0);
    if(ap.isSwitchSet("bin2hex")) {

    }

    return 0;
}
