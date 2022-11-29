/**
 * @author trhiana
 */

#include "iostream"
#include "main.h"

using namespace std;

int main() {
    Flights flights;
    flights.readFile();
    flights.airportFile();
    flights.airlinesFile();
    flights.routesFile();
    flights.departureAirportCode();
    flights.arrivalAirportCode();
    flights.passenger();
    flights.toString();

    return 0;
}