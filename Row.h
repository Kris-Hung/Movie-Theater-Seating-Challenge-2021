/*
Movie Theater Seating Challenge
Row.h
*/

#include "Seat.h"
#include "Booking.h"
#include <vector>
using namespace std;
#pragma once

class Row {
private:
    vector<Seat> seats;
    char rowName;
    int remainingSeats;
    int maxContiguousSeats;
    int rangeStart; // the start position of a contiguous-seat block
    int rangeEnd; // the end position of a contiguous-seat block
    int bufferCount;

public:
    Row(int row, int numSeats, int buffer);
    int getRemainingSeats();
    char getRowName();
    int getRangeStart();
    int getRangeEnd();
    int getLeftRemaining();
    int getRightRemaining();
    void setMaxContiguousSeats();
    int getMaxContiguousSeats();
    int getSeatsPos(int requiredSeats);
    void safetyBuffer();
    void assignBooking(Booking& b);
    void assignLeftSide(Booking& b);
    void assignRightSide(Booking& b);
    void printRow();
};
