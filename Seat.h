/*
Movie Theater Seating Challenge
Seat.h
*/

#pragma once
class Seat {
private:
    char rowName;
    int colName;
    int state;

public:
    Seat(char row, int col);
    bool isBooked();
    void bookSeat(int bookNum);
    char getRowName();
    int getColName();
    int getState();
    void setBuffer();
};