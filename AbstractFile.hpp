#pragma once

#include <string>
#include <vector>

class AbstractFile {
public:
    virtual ~AbstractFile() = default;

    /**
     * @return false on failure to open file
     */
    virtual bool openFile(std::string filename) = 0;

    /**
     * @return list of all lines in a file
     */
    virtual std::vector<std::string> getLineItems() = 0;
};