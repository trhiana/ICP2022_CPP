//
// Created by trhiana on 28/11/22.
//

#ifndef ICP2022_CPP_MAIN_H
#define ICP2022_CPP_MAIN_H

#include "map"
#include "list"
using namespace std;

class Flights {
public:
    // userData.cpp
    void readFile();
    void userInput();
    void arrivalAirportCode();
    void departureAirportCode();

    // airports.cpp
    void airportFile();
    list<string> split(string, string);

private:
    map<list<string>, string> airports;
    string deptAirportCode, arrAirportCode;
    list<string[]> inputFile;
};

#endif //ICP2022_CPP_MAIN_H
