/*
Movie Theater Seating Challenge
MovieTheater.h
*/

#include "Seat.h"
#include "Booking.h"
#include "Row.h"
#include <vector>
using namespace std;

class MovieTheater {
private:
    vector<Row> rows;
    vector<int> order;
    int numOfRows;
    int seatsPerRow;
    int safetyBuffer;

public:
    MovieTheater(int rows, int seats, int buffer);
    void generateOrder();
    void safetyRow(Row& row);
    void dfsHelper(int i, int j, int count);
    bool assignFullRow(int orderIdx, Booking& b);
    bool assignPartialRow(int orderIdx, Booking& b);
    void seatsAssignments(vector<Booking>& bookings);
    int getTotalRemainingSeats();
    void printTheater();
    void checkBuffer();
};
