#pragma once

#include <string>
#include <vector>

class AbstractParser {
public:
    virtual ~AbstractParser() = default;

    virtual std::vector<std::string> parseLine(std::string line) = 0;
};