//
//  processPop.h
//  populatron
//
//  Created by Kyle Griffin on 6/16/20.
//  Copyright © 2020 Kyle Griffin. All rights reserved.
//

#ifndef processPop_h
#define processPop_h

#include <memory>
#include <string>

#include "AbstractFile.hpp"
#include "AbstractParser.hpp"

class ProcessPop {
public:
    void setFile(std::unique_ptr<AbstractFile> file);
    void setParser(std::unique_ptr<AbstractParser> parser);

    bool openFile(std::string filename);

    /**
     * @return false on file failure
     */
    bool processPopulationFile();

private:
    std::string toLocalString(long input);

    std::unique_ptr<AbstractFile> file;
    std::unique_ptr<AbstractParser> parser;
};
#endif /* processPop_h */
