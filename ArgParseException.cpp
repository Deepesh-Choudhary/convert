#include "ArgParseException.h"

#include <string>

ArgParseException::ArgParseException(std::string msg) {
    this->msg = msg;
}

const char* ArgParseException::what() const throw() {
    return msg.c_str();
}