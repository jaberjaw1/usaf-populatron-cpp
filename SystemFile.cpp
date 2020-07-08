#include "SystemFile.hpp"

#include <iostream>
#include <fstream>
#include <string>

bool SystemFile::openFile(std::string filename) {
    cityFile.open(filename);

    if (!cityFile) //Always test the file open.
    {
        std::cout << "Error opening output file" << std::endl;

        return false;
    }

    return true;
}

std::vector<std::string> SystemFile::getLineItems() {
    std::vector<std::string> allLines;

    std::string line;
    while (std::getline(cityFile, line)) {
        allLines.push_back(line);
    }

    return allLines;
}