// DNI 12345678X GARCIA GARCIA, JUAN MANUEL
#ifndef FIGHTER_H
#define FIGHTER_H

#include <string>
#include <iostream>
#include "Coordinate.h"

class Fighter {
private:
    std::string name;
    int id;
    int score;
    Coordinate position;

public:
    Fighter();
    Fighter(const std::string& name, int id);

    std::string getName() const;
    int getId() const;
    int getScore() const;
    Coordinate getPosition() const;

    void setName(const std::string& name);
    void setId(int id);
    void setScore(int score);
    void setPosition(const Coordinate& position);

    void increaseScore();
    void reset();

    friend std::ostream& operator<<(std::ostream& os, const Fighter& f);
};

#endif
