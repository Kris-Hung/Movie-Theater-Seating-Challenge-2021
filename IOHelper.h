/*
Movie Theater Seating Challenge
IOHelper.h
*/

#include "Booking.h"
#include <vector>
#include <string>
using namespace std;

class IOHelper {
private:
    vector<string> bookingID;
public:
    vector<Booking> readInput(string fileName);
    void outputResult(string fileName, vector<Booking>& bookings);
};
