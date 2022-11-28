#ifndef ICP2022_CPP_MAIN_H
#define ICP2022_CPP_MAIN_H

#include "map"
#include "list"
using namespace std;

class Flights {
public:
    // userData.cpp
    void readFile();
    static void userInput();
    string arrivalAirportCode();
    string departureAirportCode();

    // airports.cpp
    void airportFile();
    list<string> split(string, string);

private:
    map<list<string>, string> airports;
    string deptAirportCode, arrAirportCode;
    list<string[]> inputFile;
};

#endif //ICP2022_CPP_MAIN_H
