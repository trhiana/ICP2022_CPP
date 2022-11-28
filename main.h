#ifndef ICP2022_CPP_MAIN_H
#define ICP2022_CPP_MAIN_H

#include "map"
#include "list"
using namespace std;

class Flights {
public:
    // userData.cpp
    list<string[]> readFile();
    static void userInput();
    string arrivalAirportCode();
    string departureAirportCode();

    // airports.cpp
    map<list<string>, string> airportFile();
//    list<string> split(string, string);

private:
    map<list<string>, string> airports;
    string deptAirportCode, arrAirportCode;
    list<string[]> inputFile;

    static list<string> split(string line, string del = " ") {
        list<string> lines;
        string text;
        int start, end = -1*del.size();
        do {
            start = end + del.size();
            end = line.find(del, start);
            text = line.substr(start, end - start);
            lines.push_back(text);
            return lines;
        } while (end != -1);
    }
};

#endif //ICP2022_CPP_MAIN_H
