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


string Flights::departureAirportCode() {
    
}