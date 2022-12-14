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
    void airportFile() throw(FileIOException);

    //airlines.cpp
    void airlinesFile() throw(FileIOException);

    //routes.cpp
    void routesFile() throw(FileIOException);
    void passenger();

    string toString() {
        int stops_ = 0;
        for (auto & route : passenger_route) {
            cout << route[0] + " from " + route[1] + " to " + route[2] + " " +
            route[3] + " stops.\n";
            int s = stoi(route[3]);
            stops_+= s;
        }
        cout << "Total flights: " + to_string(passenger_route.size()) +
        "\nTotal additional stops: " + to_string(stops_) << endl;
    }

    /**
     * Function that splits strings and saves the result into a vector.
     * @param line: The string to be split.
     * @param del:
    int stops, flights; The delimiter.
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

private:
    vector<vector<string>> airports, location, airlines, routes, passenger_route;
    string deptAirportCode, arrAirportCode;
};

#endif //ICP2022_CPP_MAIN_H
