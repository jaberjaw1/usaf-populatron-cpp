#include "Parser.hpp"

#include <sstream>

std::vector<std::string> Parser::parseLine(std::string line) {
    std::vector<std::string> lineItems;
    std::string substring;
    std::stringstream token(line);

    // Get items in line
    while(token.good()) {
        getline(token, substring, ',');
        lineItems.push_back(substring);
    }

    return lineItems;
}