/*
Movie Theater Seating Challenge
Row.cpp
*/
#include "Row.h"
#include "Booking.h"
#include <iostream>
#include <iomanip>
using namespace std;
/*
A row contains a number of seats.
*/
Row::Row(int row, int numSeats, int buffer) {
    bufferCount = buffer;
    remainingSeats = maxContiguousSeats = numSeats;
    rangeStart = rangeEnd = numSeats/2;
    rowName = row + 'A';
    for (int i=0; i<numSeats; i++)
        seats.push_back(Seat(rowName, i+1));
}
int Row::getRemainingSeats() {
    return remainingSeats;
}
char Row::getRowName() {
    return rowName;
}
int Row::getRangeStart() {
    return rangeStart;
}
int Row::getRangeEnd() {
    return rangeEnd;
}
int Row::getLeftRemaining() {
    return rangeStart;
}
int Row::getRightRemaining() {
    return seats.size() - rangeEnd - 1;
}
void Row::setMaxContiguousSeats() {
    if (remainingSeats == seats.size()) return;
    maxContiguousSeats = max(getLeftRemaining(), getRightRemaining());
}
int Row::getMaxContiguousSeats() {
    return maxContiguousSeats;
}
/*
Return the index of the start position of a contiguous block.
*/
int Row::getSeatsPos(int requiredSeats) {
    int pos = 0;
    // first assignment of this row
    if (remainingSeats == seats.size()) {
        rangeStart = seats.size()/2 - (requiredSeats/2);
        rangeEnd = rangeStart + requiredSeats;
        pos = rangeStart;
    }
    else if (getRightRemaining() >= getLeftRemaining()) {
        pos = rangeEnd;
        rangeEnd += requiredSeats;
    }
    else {
        rangeStart -= requiredSeats;
        pos = rangeStart;
    }
    maxContiguousSeats = max(getLeftRemaining(), getRightRemaining());
    remainingSeats -= requiredSeats;
    return pos;
}
/*
Add buffer seats for safety.
*/
void Row::safetyBuffer() {
    if (seats[rangeStart].getState() != -1) {
        for (int i=0; i<bufferCount; i++) {
            if (rangeStart-1 >= 0 && seats[rangeStart-1].getState() == 0) {
                seats[--rangeStart].setBuffer();
                remainingSeats--;
            }
        }
    }
    if (seats[rangeEnd-1].getState() != -1) {
        for (int i=0; i<bufferCount; i++) {
            if (rangeEnd < seats.size() && seats[rangeEnd].getState() == 0) {
                seats[rangeEnd++].setBuffer();
                remainingSeats--;
            }
        }
    }
}
/*
When the number of requested seats in not greater than the available seats,
assign all the seats in the same booking in a contiguous block.
Time Complexity: O(n), where n is the number of seats in one row.
*/
void Row::assignBooking(Booking& b) {
    int numSeats = b.getNumSeats();
    int startPos = getSeatsPos(numSeats);
    for (int i=startPos; i<startPos+numSeats; i++)
        b.assign(seats[i]);
}
/*
Assign as many seats on the left side as possible.
Time Complexity: O(n), where n is the number of seats in one row.
*/
void Row::assignLeftSide(Booking& b) {
    if (rangeStart <= 0) return;
    int startPos = getRangeStart()-1;
    for (int i=startPos; i>=0 && !b.isFinished(); i--) {
        b.assign(seats[i]);
        rangeStart--;
        remainingSeats--;
        maxContiguousSeats = max(getLeftRemaining(), getRightRemaining());
    }
}
/*
Assign as many seats on the right side as possible.
Time Complexity: O(n), where n is the number of seats in one row.
*/
void Row::assignRightSide(Booking& b) {
    if (rangeEnd >= seats.size()) return;
    // first assignment of this row
    if (remainingSeats == seats.size()) {
        int requiredSeats = (b.numOfUnbookedSeats() >= seats.size()) ? seats.size() : b.numOfUnbookedSeats();
        rangeStart = seats.size()/2 - (requiredSeats/2);
        rangeEnd = rangeStart + requiredSeats;
        for (int i=rangeStart; i<rangeEnd; i++) {
            b.assign(seats[i]);
            remainingSeats--;
        }
        maxContiguousSeats = max(getLeftRemaining(), getRightRemaining());
        return;
    }
    // not the first assignment of this row
    int startPos = getRangeEnd();
    for (int i=startPos; i<seats.size() && !b.isFinished(); i++) {
        b.assign(seats[i]);
        rangeEnd++;
        remainingSeats--;
        maxContiguousSeats = max(getLeftRemaining(), getRightRemaining());
    }
}
void Row::printRow() {
    for (int i=0; i<seats.size(); i++) {
        cout << seats[i].getState();
        if (i != seats.size()-1) cout << setw(6);
    }
    cout << endl;
}