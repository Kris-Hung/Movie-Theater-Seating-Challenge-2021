/*
Movie Theater Seating Challenge
Booking.h
*/

#include "Seat.h"
#include <vector>
#include <string>
using namespace std;
#pragma once

class Booking {
private:
    string bookID;
    vector<Seat> assignedSeats;
    int numOfSeats;
    int numOfBookedSeats;

public:
    Booking(string id, int num);
    bool isFinished();
    string getBookID();
    void setBookID(string id);
    int getNumSeats();
    void setNumSeats(int num);
    void assign(Seat& s);
    int numOfUnbookedSeats();
    vector<Seat> getSeats();
};