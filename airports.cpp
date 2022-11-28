#include "iostream"
#include "fstream"
#include "main.h"
//#include "string"

void Flights:: airportFile() {
    try {
        int index = 0;
        string line, data[1000];
//        list<list<string>> data;
        ifstream file("airport.csv");
        while (getline (file, line)) {
            data[index] = split(line, ",");

        }
    } catch (...) {
        cout << "File does not exist!";
    }
}

list<string> Flights::split(string line, string del = " ") {
    list<string> lines;
    string text;
    int start, end = -1*del.size();
    do {
        start = end + del.size();
        end = line.find(del, start);
        text = line.substr(start, end - start);
        lines.push_back(text);
        return lines;
    } while (end != -1);
}