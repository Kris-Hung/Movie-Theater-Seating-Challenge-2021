output: main.o seat.o row.o booking.o IOHelper.o MovieTheater.o
	g++ -std=c++11 -Wall main.o seat.o row.o booking.o IOHelper.o MovieTheater.o -o output

main.o: main.cpp
	g++ -c -std=c++11 main.cpp

seat.o: Seat.cpp Seat.h
	g++ -c -std=c++11 Seat.cpp

row.o: Row.cpp Row.h
	g++ -c -std=c++11 Row.cpp

booking.o: Booking.cpp Booking.h
	g++ -c -std=c++11 Booking.cpp

IOHelper.o: IOHelper.cpp IOHelper.h
	g++ -c -std=c++11 IOHelper.cpp

MovieTheater.o: MovieTheater.cpp MovieTheater.h
	g++ -c -std=c++11 MovieTheater.cpp

clean:
	rm *.o output