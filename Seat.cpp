/*
Movie Theater Seating Challenge
Seat.cpp
*/
#include <iostream>
#include "Seat.h"
using namespace std;
/*
Contains the information of the seat.
Each seat can only be booked once.
state: 0->empty, -1->buffer seat, other numbers->the booking ID of this seat
*/
Seat::Seat(char row, int col) : rowName(row), colName(col), state(0) {}
bool Seat::isBooked() {
    return state != 0;
}
void Seat::bookSeat(int bookNum) {
    state = bookNum;
}
char Seat::getRowName() {
    return rowName;
}
int Seat::getColName() {
    return colName;
}
int Seat::getState() {
    return state;
}
void Seat::setBuffer() {
    state = -1;
}