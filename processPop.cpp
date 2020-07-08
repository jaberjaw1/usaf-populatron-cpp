//
//  main.cpp
//  populatron
//
//  Created by Kyle Griffin on 6/16/20.
//  Copyright © 2020 Kyle Griffin. All rights reserved.
//

#include "processPop.h"

#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>

#include "Parser.hpp"

using namespace std;


void ProcessPop::setFile(std::unique_ptr<AbstractFile> file) {
    this->file = std::move(file);
}

void ProcessPop::setParser(std::unique_ptr<AbstractParser> parser) {
    this->parser = std::move(parser);
}

bool ProcessPop::openFile(std::string filename) {
    return file->openFile(filename);
}

bool ProcessPop::processPopulationFile() {
    long sum = 0;
    vector<string> lines;

    lines = file->getLineItems();

    // For each line
    for (int i=1; i<lines.size(); i++) {
        std::vector<std::string> lineItems = parser->parseLine(lines[i]);

        // Grab 5th item in list
        std::string substring = lineItems[4];
        
        // If size of string > 0, add to population
        if (substring.length() > 0) {
            sum += stoi(substring);
        }
    }

    string num = toLocalString(sum);

    cout << "World population is: " << num << "." << endl;
    return 0;
}

std::string ProcessPop::toLocalString(long input) {
    stringstream ss;
    ss.imbue(std::locale(""));
    ss << std::fixed << input;
    return ss.str();
}