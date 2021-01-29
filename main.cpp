/*
Movie Theater Seating Challenge
main.cpp
Time Complexity: O(m*n)
m->number of bookings
n->number of total seats in the theater
*/
#include "IOHelper.h"
#include "Booking.h"
#include "MovieTheater.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
using namespace std;

int main(int argc, char* argv[]) {
    // check if command line includes input file's path.
    if (argc == 1) {
        cout << "usage: SeatAssigner <path to input file>\n";
        return 0;
    }
    static int numRows = 10;
    static int numSeats = 20;
    static int buffer = 3;
    // Open input file and read it into the booking list.
    IOHelper ioHelper;
    vector<Booking> bookings;
    bookings = ioHelper.readInput(argv[1]);
    if (bookings.size() == 0) {
        cout << "The input list is empty.\n";
        return 0;
    }

    // Declare the movieTheater and start to assign seats.
    MovieTheater movieTheater(numRows, numSeats, buffer);
    movieTheater.seatsAssignments(bookings);

    // Printing the entire theater.
    if (argc == 3 && *argv[2] == '1')
        movieTheater.printTheater();
    
    // Write the result to the output file "output.txt".
    ioHelper.outputResult("output.txt", bookings);
    
    // Return the full path to the output file.
    char pathBuffer[PATH_MAX];
    if (getcwd(pathBuffer, sizeof(pathBuffer)) != NULL)
        cout << "output file path:" << pathBuffer << "/output.txt\n";

    return 0;
}