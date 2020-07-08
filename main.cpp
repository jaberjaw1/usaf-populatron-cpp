//
//  main.cpp
//  populatron
//
//  Created by Kyle Griffin on 6/16/20.
//  Copyright © 2020 Kyle Griffin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <memory>

#include "processPop.h"
#include "AbstractFile.hpp"
#include "SystemFile.hpp"
#include "AbstractParser.hpp"
#include "Parser.hpp"


using namespace std;


int main(int argc, const char * argv[]) {
    if (argc < 2) {
        cout << "usage: must include file to parse" << endl;
    }

    std::unique_ptr<AbstractFile> file = make_unique<SystemFile>();
    std::unique_ptr<AbstractParser> parser = make_unique<Parser>();

    ProcessPop pp;
    pp.setFile(std::move(file));
    pp.setParser(std::move(parser));

    if (!pp.openFile(argv[1])) {
        std::cout << "Cannot open file" << std::endl;

        return -1;
    }

    pp.processPopulationFile();
}