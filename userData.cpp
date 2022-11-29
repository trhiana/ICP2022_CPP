/**
 * @author trhiana
 */

#include "iostream"
#include "fstream"
#include "main.h"
#include "vector"
#include "exceptions.h"

using namespace std;

/**
 * Reading the user/traveller information from travel_input.txt
 * @throw: FileIOException
 */
void Flights::readFile() throw(FileIOException) {
    string line;
    try {
        ifstream file("travel_input.txt");
        while (getline(file, line)) {
            location.push_back(split(line, ","));
        }

        if (location.empty()) {
            cout << "File is empty\n";
        }
        file.close();
    } catch (FileIOException) {
        cout << "'travel_input.txt' does not exist.\n";
    }
}

/**
 * Provides the departure airport code from the airports vector.
 * @throw: IndexOutOfRangeException
 */
void Flights::departureAirportCode() throw(IndexOutOfRangeException){
    try {
        for (auto & airport : airports) {
            // location[0][] is always departure location
            if (location[0][0] == airport[0] && location[0][1] == airport[1]) {
                deptAirportCode = airport[2];
            } else {
                cout << "The location you provided is not in our files.\n";
            }
        }
    } catch (IndexOutOfRangeException) {
        cout << "The index is out of range\n";
    }
}

