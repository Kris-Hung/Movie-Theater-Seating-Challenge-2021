/*
Movie Theater Seating Challenge
Booking.cpp
*/
#include "Booking.h"
#include <string>
#include <iostream>
using namespace std;
/*
Contains the information of the booking.
*/
Booking::Booking(string id, int num) {
    bookID = id;
    assignedSeats.reserve(num);
    numOfSeats = num;
    numOfBookedSeats = 0;
}
bool Booking::isFinished() {
    return numOfBookedSeats == numOfSeats;
}
string Booking::getBookID() {
    return bookID;
}
void Booking::setBookID(string id) {
    bookID = id;
}
int Booking::getNumSeats() {
    return numOfSeats;
}
void Booking::setNumSeats(int num) {
    numOfSeats = num;
}
void Booking::assign(Seat& s) {
    int stateNum = stoi(getBookID());
    s.bookSeat(stateNum);
    assignedSeats.push_back(s);
    numOfBookedSeats++;
}
int Booking::numOfUnbookedSeats() {
    return numOfSeats - numOfBookedSeats;
}
vector<Seat> Booking::getSeats() {
    return assignedSeats;
}