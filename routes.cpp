/**
 * @author trhiana
 */

#include "iostream"
#include "fstream"
#include "vector"
#include "main.h"
#include "exceptions.h"

using namespace std;

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

void Flights::passenger() {

}
