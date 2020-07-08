#pragma once

#include <AbstractFile.hpp>

#include <fstream>

class SystemFile : public AbstractFile {
public:
    
    bool openFile(std::string filename) override;

    std::vector<std::string> getLineItems() override;

private:
    std::ifstream cityFile;
};