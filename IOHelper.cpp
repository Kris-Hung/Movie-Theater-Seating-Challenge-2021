/*
Movie Theater Seating Challenge
IOHelper.cpp
*/
#include "IOHelper.h"
#include "Seat.h"
#include "Booking.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

/*
Read file function.
Use bookingID array to record the bookingID.
*/
vector<Booking> IOHelper::readInput(string fileName) {
    vector<Booking> bookings;
    ifstream myfile(fileName);
    string line;
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            vector<string> tmp;
            stringstream ss(line);
            while (ss.good()) {
                string substr;
                getline(ss, substr, ' ');
                tmp.push_back(substr);
            }
            bookingID.push_back(tmp[0]);
            string id = tmp[0].substr(1);
            int num = stoi(tmp[1]);
            bookings.push_back(Booking(id, num));
        }
        myfile.close();
    }
    else {
        cout << "File doesn't exist.\n";
    }
    return bookings;
}
/*
Write the result to the output file.
*/
void IOHelper::outputResult(string fileName, vector<Booking>& bookings) {
    fstream myfile;
    myfile.open (fileName, fstream::in | fstream::out | fstream::trunc);
    for (int i=0; i<bookingID.size(); i++) {
        vector<Seat> curSeats(bookings[i].getSeats());
        myfile << bookingID[i] << " ";
        if (curSeats.size() == 0) myfile << "The number of seats required exceeds the capacity.";
        for (int j=0; j<bookings[i].getSeats().size(); j++) {
            if (curSeats.size() == 0) continue;
            else {
                myfile << curSeats[j].getRowName() << curSeats[j].getColName();
                if (j != bookings[i].getSeats().size()-1) myfile << ", ";
            }
        }
        myfile << endl;
    }
    myfile.close();
}