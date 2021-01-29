/*
Movie Theater Seating Challenge
MovieTheater.cpp
*/
#include "Row.h"
#include "Booking.h"
#include "MovieTheater.h"
#include <iostream>
#include <iomanip>
/*
A MovieTheater includes a number of rows.
*/
MovieTheater::MovieTheater(int numRows, int seats, int buffer) {
    numOfRows = numRows;
    seatsPerRow = seats;
    safetyBuffer = buffer;
    for (int i=0; i<numOfRows; i++)
        rows.push_back(Row(i, seatsPerRow, safetyBuffer));
    generateOrder();
}

/*
Generate an order array to store the order for assigning seats.
People usually prefer to sit at the center of the theater.)
10-row-order(in row number): 5, 4, 6, 3, 7, 2, 8, 1, 9, 0
Time Complexity: O(n/2), where n is the number of rows.
*/
void MovieTheater::generateOrder() {
    int mid = numOfRows/2;
    order.push_back(mid);
    for (int i=1; i<mid+1; i++) {
        order.push_back(mid-i);
        if (mid+i < numOfRows)
            order.push_back(mid+i);
    }
}
/*
Assign the booking to a whole row as one contiguous block recursively.
Time Complexity: O(n), where n is the number of rows.
*/
bool MovieTheater::assignFullRow(int orderIdx, Booking& b) {
    if (orderIdx >= numOfRows) return false;
    int rowIdx = order[orderIdx];
    rows[rowIdx].setMaxContiguousSeats();
    if (rows[rowIdx].getRemainingSeats()>0 && b.numOfUnbookedSeats() <= rows[rowIdx].getMaxContiguousSeats()) {
        rows[rowIdx].assignBooking(b);
        return true;
    }
    return assignFullRow(orderIdx+1, b);
}
/*
Assign as many seats as possible recursively.
Try to make seats in the same booking are close across rows.
Time Complexity: O(n), where n is the number of rows.
*/
bool MovieTheater::assignPartialRow(int orderIdx, Booking& b) {
    if (orderIdx >= numOfRows) return false;
    int rowIdx = order[orderIdx];
    if (rows[rowIdx].getRemainingSeats() > 0) {
        rows[rowIdx].assignRightSide(b);
        if (b.isFinished()) return true;
        if (assignPartialRow(orderIdx+1, b)) return true;
        rows[rowIdx].assignLeftSide(b);
        if (b.isFinished()) return true;
    }
    return assignPartialRow(orderIdx+1, b);
}

/*
First assign the best positions, the center of the theater.
After no contiguous block of seats can be assigned, assign the booking across rows.
Time Complexity: O(m*n)
m->number of bookings
n->number of rows
*/
void MovieTheater::seatsAssignments(vector<Booking>& bookings) {
    for (auto& b : bookings) {
        if (getTotalRemainingSeats() < b.getNumSeats())
            continue;
        if (!assignFullRow(0, b)) {
            assignPartialRow(0, b);
        }
        checkBuffer();
    }
}

/*
Get the number total remaining seats in the theater.
Time Complexity: O(n), where n is the number of rows.
*/
int MovieTheater::getTotalRemainingSeats() {
    int total = 0;
    for (int i=0; i<rows.size(); i++)
        total += rows[i].getRemainingSeats();
    return total;
}

/*
Print out the seat assignment in the theater.
Time Complexity: O(n), where n is the number of rows.
*/
void MovieTheater::printTheater() {
    for (int i=0; i<rows.size(); i++)
        rows[i].printRow();
}

/*
Add buffer seats for safety.
Time Complexity: O(n), where n is the number of rows.
*/
void MovieTheater::checkBuffer() {
    for (int i=0; i<numOfRows; i++) {
        if (rows[i].getRemainingSeats() != seatsPerRow) rows[i].safetyBuffer();
    }
}