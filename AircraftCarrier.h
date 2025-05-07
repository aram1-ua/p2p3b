// Y5624889T ANJA RAPHAELA ALUM MILLARES
#ifndef AIRCRAFTCARRIER_H
#define AIRCRAFTCARRIER_H

#include <iostream>
#include <string>
#include <vector>
#include "Fighter.h"

class AircraftCarrier {
private:
    std::string name;
    int wins;
    int losses;
    std::vector<Fighter*> fleet;

public:
    AircraftCarrier(std::string name);

    std::string getName() const;
    int getWins() const;
    int getLosses() const;
    std::vector<Fighter*> getFleet() const;

    void addFighters(std::string fd);
    void updateResults(int r);
    Fighter* getFirstAvailableFighter(std::string type) const;
    int purgeFleet();
    void showFleet() const;
    std::string myFleet() const;

    friend std::ostream& operator<<(std::ostream& os, const AircraftCarrier& a);
};

#endif
