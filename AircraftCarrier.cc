// DNI 12345678X GARCIA GARCIA, JUAN MANUEL
#include "AircraftCarrier.h"

AircraftCarrier::AircraftCarrier() : id(-1), position(), damaged(false) {}

AircraftCarrier::AircraftCarrier(int id, const Coordinate& position)
    : id(id), position(position), damaged(false) {}

int AircraftCarrier::getId() const {
    return id;
}

Coordinate AircraftCarrier::getPosition() const {
    return position;
}

bool AircraftCarrier::isDamaged() const {
    return damaged;
}

void AircraftCarrier::setId(int i) {
    id = i;
}

void AircraftCarrier::setPosition(const Coordinate& pos) {
    position = pos;
}

void AircraftCarrier::setDamaged(bool d) {
    damaged = d;
}

void AircraftCarrier::reset() {
    id = -1;
    position.reset();
    damaged = false;
}

std::ostream& operator<<(std::ostream& os, const AircraftCarrier& a) {
    os << a.id << " " << a.position << " " << (a.damaged ? "damaged" : "not_damaged");
    return os;
}
