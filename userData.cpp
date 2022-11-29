#include "iostream"
#include "fstream"
#include "main.h"
#include "vector"
#include "exceptions.h"

using namespace std;

/**
 * Reading the user / traveller information from travel_input.txt
 */
void Flights::readFile() throw(FileIOException) {
    string line;
    try {
        ifstream file("travel_input.txt");
        while (getline(file, line)) {
            location.push_back(split(line, ","));
        }

        if (location.empty()) {
            cout << "File is empty";
        }
        file.close();
    } catch (FileIOException) {
        cout << "'travel_input.txt' does not exist.";
    }
}

/**
 * Provides the departure airport code from the airports vector.
 */
void Flights::departureAirportCode() {
    for (int i = 0; i < airports.size(); ++i) {
        if (location[0][0] == airports[i][0])
    }
}