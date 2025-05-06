// DNI 12345678X GARCIA GARCIA, JUAN MANUEL
#include "Fighter.h"

Fighter::Fighter() : name(""), id(-1), score(0), position() {}

Fighter::Fighter(const std::string& name, int id)
    : name(name), id(id), score(0), position() {}

std::string Fighter::getName() const {
    return name;
}

int Fighter::getId() const {
    return id;
}

int Fighter::getScore() const {
    return score;
}

Coordinate Fighter::getPosition() const {
    return position;
}

void Fighter::setName(const std::string& n) {
    name = n;
}

void Fighter::setId(int i) {
    id = i;
}

void Fighter::setScore(int s) {
    score = s;
}

void Fighter::setPosition(const Coordinate& pos) {
    position = pos;
}

void Fighter::increaseScore() {
    score++;
}

void Fighter::reset() {
    name = "";
    id = -1;
    score = 0;
    position.reset();
}

std::ostream& operator<<(std::ostream& os, const Fighter& f) {
    os << f.id << " " << f.name << " " << f.score << " " << f.position;
    return os;
}
