#pragma once

#include <string>
#include <vector>

#include "AbstractParser.hpp"

class Parser : public AbstractParser {
public:
    std::vector<std::string> parseLine(std::string line) override;
};