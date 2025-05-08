OPTS=-g -Wall -std=c++11
OBJS=prac3.o Board.o AircraftCarrier.o Fighter.o Coordinate.o
CC=g++

prac3: $(OBJS)
	$(CC) $(OPTS) $(OBJS) -o prac3

prac3.o: prac3.cc Board.h AircraftCarrier.h Fighter.h Coordinate.h
	$(CC) $(OPTS) -c prac3.cc

Board.o: Board.cc Board.h AircraftCarrier.h Fighter.h Coordinate.h
	$(CC) $(OPTS) -c Board.cc

AircraftCarrier.o: AircraftCarrier.cc AircraftCarrier.h Fighter.h Coordinate.h
	$(CC) $(OPTS) -c AircraftCarrier.cc

Coordinate.o: Coordinate.cc Coordinate.h
	$(CC) $(OPTS) -c Coordinate.cc

Fighter.o: Fighter.cc Fighter.h Coordinate.h
	$(CC) $(OPTS) -c Fighter.cc

clean:
	rm $(OBJS)