// Y5624889T ANJA RAPHAELA ALUM MILLARES
#ifndef FIGHTER_H
#define FIGHTER_H

#include <iostream>
#include <string>
#include "Coordinate.h"

int getRandomNumber(); // Declaración para evitar errores de linker (suponiendo que esté definida en otro lugar)

class Fighter {
private:
    std::string type;
    std::string aircraftCarrier;
    int speed;
    int attack;
    int shield;
    int id;
    Coordinate position;

    static int nextId;

public:
    Fighter(std::string type, std::string aircraftCarrier);

    static void resetNextId();
    void setPosition(Coordinate p);
    void resetPosition();
    bool isDestroyed() const;
    int getDamage(int n) const;
    int fight(Fighter* enemy);

    // Getters
    std::string getType() const;
    std::string getAircraftCarrier() const;
    int getSpeed() const;
    int getAttack() const;
    int getShield() const;
    int getId() const;
    Coordinate getPosition() const;

    // Adders
    void addAttack(int value);
    void addSpeed(int value);
    void addShield(int value);

    friend std::ostream& operator<<(std::ostream& os, const Fighter& f);
};

#endif
