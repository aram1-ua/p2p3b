// DNI 12345678X GARCIA GARCIA, JUAN MANUEL
#include "Board.h"
#include <iostream>

Board::Board() {
    reset();
}

void Board::reset() {
    for (int i = 0; i < NUM_FIGHTERS; i++)
        fighters[i].reset();
    for (int i = 0; i < NUM_AIRCRAFT_CARRIERS; i++)
        aircraftCarriers[i].reset();
}

int Board::getFighterIndex(int id) const {
    for (int i = 0; i < NUM_FIGHTERS; i++) {
        if (fighters[i].getId() == id)
            return i;
    }
    return -1;
}

int Board::getAircraftCarrierIndex(const Coordinate& c) const {
    for (int i = 0; i < NUM_AIRCRAFT_CARRIERS; i++) {
        if (aircraftCarriers[i].getPosition().getRow() == c.getRow() &&
            aircraftCarriers[i].getPosition().getColumn() == c.getColumn())
            return i;
    }
    return -1;
}

bool Board::addFighter(const Fighter& f) {
    for (int i = 0; i < NUM_FIGHTERS; i++) {
        if (fighters[i].getId() == -1) {
            fighters[i] = f;
            return true;
        }
    }
    return false;
}

bool Board::addAircraftCarrier(const AircraftCarrier& a) {
    for (int i = 0; i < NUM_AIRCRAFT_CARRIERS; i++) {
        if (aircraftCarriers[i].getId() == -1) {
            aircraftCarriers[i] = a;
            return true;
        }
    }
    return false;
}

bool Board::moveFighter(int id, const Coordinate& newPosition) {
    int idx = getFighterIndex(id);
    if (idx == -1 || !newPosition.isValid()) return false;

    fighters[idx].setPosition(newPosition);
    return true;
}

bool Board::bomb(int fighterId) {
    int fighterIdx = getFighterIndex(fighterId);
    if (fighterIdx == -1) return false;

    Coordinate pos = fighters[fighterIdx].getPosition();
    int acIdx = getAircraftCarrierIndex(pos);
    if (acIdx == -1 || aircraftCarriers[acIdx].isDamaged()) return false;

    aircraftCarriers[acIdx].setDamaged(true);
    fighters[fighterIdx].increaseScore();
    return true;
}

void Board::printFighters() const {
    for (int i = 0; i < NUM_FIGHTERS; i++) {
        if (fighters[i].getId() != -1)
            std::cout << fighters[i] << std::endl;
    }
}

void Board::printAircraftCarriers() const {
    for (int i = 0; i < NUM_AIRCRAFT_CARRIERS; i++) {
        if (aircraftCarriers[i].getId() != -1)
            std::cout << aircraftCarriers[i] << std::endl;
    }
}
