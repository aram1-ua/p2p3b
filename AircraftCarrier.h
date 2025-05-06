// DNI 12345678X GARCIA GARCIA, JUAN MANUEL
#ifndef AIRCRAFTCARRIER_H
#define AIRCRAFTCARRIER_H

#include <iostream>
#include "Coordinate.h"

class AircraftCarrier {
private:
    int id;
    Coordinate position;
    bool damaged;

public:
    AircraftCarrier();
    AircraftCarrier(int id, const Coordinate& position);

    int getId() const;
    Coordinate getPosition() const;
    bool isDamaged() const;

    void setId(int id);
    void setPosition(const Coordinate& position);
    void setDamaged(bool damaged);

    void reset();

    friend std::ostream& operator<<(std::ostream& os, const AircraftCarrier& a);
};

#endif
