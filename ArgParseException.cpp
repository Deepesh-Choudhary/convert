#include "ArgParseException.h"
#include <string>

using std::string;

ArgParseException::ArgParseException(string msg) {
    this->msg = msg;
}

const char* ArgParseException::what() const throw() {
    return msg.c_str();
}