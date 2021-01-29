# Movie-Theater-Seating-Challenge-2021

## Overview
Fulfill booking requests given from an input file, and assign seats in a 10 rows x 20 seats movie theater.
Maximize both customer satisfication and safety (three buffer seats is required).

## Assumptions
1. Booking process is on a first come first served basis.
2. Middle positions in middle rows are considered the best for customer experience. Customers always want the better seats.
3. Customers can not choose if they want to split up or sit together.
4. For the purpose of public safety, there will be three buffer seats between different group of people.
(For balancing both customers' safety and maxmizing the theater's profit, one buffer row is not required.)
5. For each booking, if the number of requested seats exceeds the theater's capacity, 
there won't be any seats assigned to this reservation and it will inform the customer(in the output file).
6. The booking ID (R###) will be in sequential order in the input file.
7. Every row in the input file is in correct format. (R001 3)
(Each line in the file will be comprised of a reservation identifier, followed by a space, and then the number of seats requested.)

## Rules
1. Fullfill as many booking requests as possible.
2. First, make sure that the best seats are assigned to early customers.
3. Then, try to assign the seats in the same booking together.
4. If all the rows are not able to assigned contiguous seats to a group,
then split up the group and try to allocate seats across the rows.
5. If the theater is not able to allocate any consecutive seats, assign them to wherever is empty.

## Instructions
1. Open the command prompt.
2. Go to the directory path where the files are located.
3. Type `make` in the command line.
4. Type `./output {the complete path to the input file}`. 
Type `./output {the complete path to the input file} 1` for printing out.
5. The output file **output.txt** will be generated under the same directory.


## Test Cases
* TestInput1.txt: An empty list.
* TestInput2.txt: The number of requested  seats exceeds the theater's capacity.
* TestInput3.txt: Assign to wherever is empty if there are no available blocks for the booking.
* TestInput4.txt: Best seats assigned to the early reservation.
* TestInput5.txt: A booking for all the seats.
* TestInput6.txt: Normal test case.
