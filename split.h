#ifndef SPLIT_H
#define SPLIT_H

#include <vector>
#include <string>

/**
 * Splits the given sentence into its constituent words.
 * Words are seperated by space(s).
 * 
 * @param str Sentence to split
 * @return vector<string> containing words
 */
std::vector<std::string> split(const std::string &str);

#endif