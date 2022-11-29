#include "iostream"
#include "fstream"
#include "main.h"
#include "vector"

using namespace std;

vector<vector<string>> Flights::readFile() {
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
    } catch (...) {
        cout << "'travel_inputs.txt' does not exist.";
    }

    return location;
}

string Flights::departureAirportCode() {
    
}