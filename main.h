/**
 * @author trhiana
 */

#ifndef ICP2022_CPP_MAIN_H
#define ICP2022_CPP_MAIN_H

#include <vector>
#include "map"
#include "exceptions.h"
using namespace std;

class Flights {
public:
    // userData.cpp
    void readFile() throw(FileIOException);
    void arrivalAirportCode() throw(IndexOutOfRangeException);
    void departureAirportCode() throw(IndexOutOfRangeException);

    // airports.cpp
    void airportFile();

private:
    vector<vector<string>> airports;
    string deptAirportCode, arrAirportCode;
    vector<vector<string>> location;

    /**
     * Function that splits strings and saves the result into a vector.
     * @param line: The string to be split.
     * @param del: The delimiter.
     * @return lines, a vector of the split string.
     *
     * Methods retrieved from geeksforgeeks.com
     */
    static vector<string> split(string line, string del = " ") {
        vector<string> lines;
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
