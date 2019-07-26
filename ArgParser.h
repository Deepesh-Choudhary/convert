#ifndef ARG_PARSER_H
#define ARG_PARSER_H

#include <string>
#include <vector>
#include <utility>  //for std::pair

class ArgParser {
public:
    ArgParser();
    ArgParser(const int argc, const char *argv[],
        const std::string switches, const std::string dataOptions = "");
    void operator()(const int argc, const char *argv[],
        const std::string switches, const std::string dataOptions = "");

    void parse();

    bool isSwitchSet(std::string svitch) const;
    bool isDataOptSet(std::string dataOption) const;
    bool isSet(std::string option) const;

    std::string getDataForOpt(std::string option) const;
    
    std::vector<std::string> getSwitches() const;
    std::vector<std::string> getDataOptions() const;
    std::vector<std::string> getAllOptions() const;
    std::vector<std::string> getOperands() const;

private:
    std::vector<std::string>::const_iterator commonIter;
    std::string allSwitches, allDataOpts;
    std::vector<std::string> args, operands, switchesSet;
    std::vector<std::pair<std::string, std::string> > dataOptsSet;
    bool finalized;

    void processOperand();
    void processSingleDash();
    void processDoubleDash();
};

#endif