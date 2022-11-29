/**
 * @author trhiana
 */

#include "iostream"
#include "fstream"
#include "vector"
#include "main.h"
#include "exceptions.h"

using namespace std;

/**
 * Reads the airlines.csv file and stores IATA code,
 * source airport, destination airport and number of stops for each route.
 * @throw: FileIOException
 */
void Flights::routesFile() throw(class FileIOException) {
    try {
        string line;
        vector<vector<string>> data;
        ifstream file("routes.csv");

        // Get all the data from the file
        while (getline (file, line)) {
            data.push_back(split(line, ","));
        }

        // Getting the IATA code, departure and arrival airports, and number of stops
        // and add to the airlines vector
        for (auto & route : data) {
            vector<string> loc_data;
            loc_data.push_back(route[0]); // IATA code
            loc_data.push_back(route[2]); // departure airport
            loc_data.push_back(route[4]); // arrival airport
            loc_data.push_back(route[7]); // number of stops
            routes.push_back(loc_data);
        }
        file.close();
    } catch (FileIOException) {
        cout << "File does not exist!";
    }
}

/**
 * Calculating the flights needed based on the passenger departure and destination details
 */
void Flights::passenger() {
    vector<vector<string>> airports_with_departure_code, airports_with_arrival_code;
    for (auto & route : routes) {
        if (deptAirportCode == route[1] && arrAirportCode == route[2]) {
            passenger_route.push_back(route);
            break;
        } else if (deptAirportCode == route[1]) {
            airports_with_departure_code.push_back(route);
        } else if (arrAirportCode == route[2]) {
            airports_with_arrival_code.push_back(route);
        }
    }

    for (auto & departure : airports_with_departure_code) {
        for (auto & destination : airports_with_arrival_code) {
            if (departure[2] == destination[1]) {
                passenger_route.push_back(departure);
                passenger_route.push_back(destination);
            }
        }
    }
    
}
