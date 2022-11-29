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
 * Reads the airlines.csv file and stores airline name, IATA code, and active status.
 * @throw: FileIOException
 */
void Flights::airlinesFile() throw(class FileIOException) {
    try {
        string line;
        vector<vector<string>> data;
        ifstream file("airlines.csv");

        // Get all the data from the file
        while (getline (file, line)) {
            data.push_back(split(line, ","));
        }

        // Getting the airline name, IATA code, and active status from the imported data
        // and add to the airlines vector
        for (auto & airline : data) {
            vector<string> loc_data;
            loc_data.push_back(airline[1]); // airline name
            loc_data.push_back(airline[3]); // airline code
            loc_data.push_back(airline[7]); // active status - Y / N
            airlines.push_back(loc_data);
        }
        file.close();
    } catch (FileIOException) {
        cout << "File does not exist!";
    }
}
