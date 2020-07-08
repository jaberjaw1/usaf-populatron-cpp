//
//  testIt.cpp
//  populatron
//
//  Created by Kyle Griffin on 6/16/20.
//  Copyright © 2020 Kyle Griffin. All rights reserved.
//



#include <stdio.h>
#include <streambuf>
#include <sstream>
#include <iostream>
#include <ostream>
#include <string>
#include <memory>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "processPop.h" 
#include "AbstractFile.hpp"
#include "SystemFile.hpp"

using namespace std;

class MockFile : public AbstractFile {
public:
  MOCK_METHOD(bool, openFile, (std::string), (override));
  MOCK_METHOD(std::vector<std::string>, getLineItems, (), (override));
};

class MockParser : public AbstractParser {
public:
  MOCK_METHOD(std::vector<std::string>, parseLine, (std::string), (override));
};

using ::testing::Return;

TEST(processPopulation, outputTest) {
    //setup
    string expected = "World population is: 1347982728.\n";
    std::string filename = "../data/worldcitiespop.csv";
    std::vector<std::string> fileOutput = {
      "Country,City,AccentCity,Region,Population,Latitude,Longitude",
      "ad,aixas,Aix�s,06,1347982728,42.4833333,1.4666667"
    };
    std::vector<std::string> parsedLine = {
      "ad", "aixas", "Aix�s", "06", "1347982728", "42.4833333", "1.4666667"
    };

    //redirect standard out
    ostringstream strCout;
    streambuf* oldCout = cout.rdbuf( strCout.rdbuf());

    auto file = make_unique<MockFile>();
    auto parser = make_unique<MockParser>();

    EXPECT_CALL(*file, openFile(filename))
        .Times(1)
        .WillOnce(Return(true));

    EXPECT_CALL(*file, getLineItems())
        .Times(1)
        .WillOnce(Return(fileOutput));

    EXPECT_CALL(*parser, parseLine(fileOutput.at(1)))
        .Times(1)
        .WillOnce(Return(parsedLine));

    ProcessPop pp;
    pp.setFile(std::move(file));
    pp.setParser(std::move(parser));

    pp.openFile(filename);

    pp.processPopulationFile();

    string actual = strCout.str();
    EXPECT_EQ(actual, expected);

    cout.rdbuf(oldCout);
}

int main(int argc, char **argv) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
