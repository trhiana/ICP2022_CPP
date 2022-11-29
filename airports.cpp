#include "iostream"
#include "fstream"
#include "main.h"
#include "vector"

using namespace std;

void Flights:: airportFile() {
    try {
        string line;
        vector<string> loc_data;
        vector<vector<string>> data;
        ifstream file("airport.csv");

        // Get all the data from the file
        while (getline (file, line)) {
            data.push_back(split(line, ","));
        }

        // Getting the city, country, and airport codes from the imported data
        // and add to the airports vector
        for (auto & i : data) {
            loc_data.push_back(i[2]); // city
            loc_data.push_back(i[3]); // country
            loc_data.push_back(i[4]); // airport code
            airports.push_back(loc_data);
        }
        file.close();
    } catch (...) {
        cout << "File does not exist!";
    }
}

