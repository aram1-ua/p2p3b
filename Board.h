// DNI 12345678X GARCIA GARCIA, JUAN MANUEL
#ifndef BOARD_H
#define BOARD_H

#include "Fighter.h"
#include "AircraftCarrier.h"

const int NUM_FIGHTERS = 5;
const int NUM_AIRCRAFT_CARRIERS = 3;

class Board {
private:
    Fighter fighters[NUM_FIGHTERS];
    AircraftCarrier aircraftCarriers[NUM_AIRCRAFT_CARRIERS];

public:
    Board();

    bool addFighter(const Fighter& f);
    bool addAircraftCarrier(const AircraftCarrier& a);

    bool moveFighter(int id, const Coordinate& newPosition);
    bool bomb(int fighterId);

    int getFighterIndex(int id) const;
    int getAircraftCarrierIndex(const Coordinate& c) const;

    void reset();

    void printFighters() const;
    void printAircraftCarriers() const;
};

#endif
