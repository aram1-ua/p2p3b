// Y5624889T ANJA RAPHAELA ALUM MILLARES
#include "Fighter.h"
#include <stdexcept>
#include <cstdlib> // Para rand()
using namespace std;

// Devuelve un número aleatorio entre 0 y maxrnd-1
int getRandomNumber(unsigned int maxrnd) {
    return rand() % maxrnd;
}

int Fighter::nextId = 1;

Fighter::Fighter(string type, string aircraftCarrier)
    : type(type), aircraftCarrier(aircraftCarrier), speed(100), attack(80), shield(80), position() {
    if (type.empty()) {
        throw invalid_argument("Wrong type");
    }
    id = nextId++;
}

void Fighter::resetNextId() {
    nextId = 1;
}

void Fighter::setPosition(Coordinate p){
    position = p;
}

void Fighter::resetPosition() {
    position.reset();
}

bool Fighter::isDestroyed() const {
    return shield <= 0;
}

int Fighter::getDamage(int n) const {
    return (n * attack) / 300;
}

int Fighter::fight(Fighter* enemy) {
    if (this->isDestroyed() || enemy->isDestroyed()) {
        return 0;
    }

    while (!this->isDestroyed() && !enemy->isDestroyed()) {
        int n = getRandomNumber(100);
        int v1 = this->speed;
        int v2 = enemy->speed;
        int u = (100 * v1) / (v1 + v2);

        if (u >= n) {
            enemy->shield -= this->getDamage(n);
        } else {
            this->shield -= enemy->getDamage(100 - n);
        }
    }

    if (this->isDestroyed()) {
        return -1;
    }
    if (enemy->isDestroyed()) {
        return 1;
    }
    return 0;
}

string Fighter::getType() const {
    return type;
}

string Fighter::getAircraftCarrier() const {
    return aircraftCarrier;
}

int Fighter::getSpeed() const {
    return speed;
}

int Fighter::getAttack() const {
    return attack;
}

int Fighter::getShield() const {
    return shield;
}

int Fighter::getId() const {
    return id;
}

Coordinate Fighter::getPosition() const {
    return position;
}


void Fighter::addAttack(int value) {
    attack += value;
    if (attack < 0) {
        attack = 0;
    }
}

void Fighter::addSpeed(int value) {
    speed += value;
    if (speed < 0) {
        speed = 0;
    }
}

void Fighter::addShield(int value) {
    shield += value;
}

ostream& operator<<(ostream& os, const Fighter& f) {
    os << "(" << f.type << " " << f.id << " " << f.position
       << " {" << f.speed << "," << f.attack << "," << f.shield << "})";
    return os;
}
