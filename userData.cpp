#include "iostream"
#include "fstream"
#include "main.h"

using namespace std;

/**
 * Function gets the users travel destinations and saves the information in
 * travel_input.txt
 */
void Flights::userInput() {
    string departure, arrival;
    try {
        ofstream file("travel_input.txt");
        cout << "Enter departure location (Accra, Ghana): ";
        cin >> departure;
        cout << "Enter arrival location (Kampala, Uganda): ";
        cin >> arrival;
        file << departure;
        file << arrival;
        file.close();

    } catch (...) {
        cout << "Unable to write file!";
    }
}

list<string[]> Flights::readFile() {
    string location;
    list<list<string>> data;
    try {
        ifstream file("travel_input.txt");
        while (getline(file, location)) {
            data.push_back(split(location, ","));
        }

        if (sizeof(inputFile) == 0) {
            cout << "File is empty";
        }
    }
}

string Flights::departureAirportCode() {

}