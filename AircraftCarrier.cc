// Y5624889T ANJA RAPHAELA ALUM MILLARES
#include "AircraftCarrier.h"
#include <sstream>
#include <map>
#include <algorithm>
#include <stdexcept>

AircraftCarrier::AircraftCarrier(std::string name) : name(name), wins(0), losses(0) {
    if (name.empty()) throw std::invalid_argument("Wrong name");
}

std::string AircraftCarrier::getName() const {
    return name;
}

int AircraftCarrier::getWins() const {
    return wins;
}

int AircraftCarrier::getLosses() const {
    return losses;
}

std::vector<Fighter*> AircraftCarrier::getFleet() const {
    return fleet;
}

void AircraftCarrier::addFighters(std::string fd) {
    if (fd.empty()) return;

    std::stringstream ss(fd);
    std::string segment;

    while (std::getline(ss, segment, ':')) {
        std::stringstream pairStream(segment);
        std::string countStr, type;

        std::getline(pairStream, countStr, '/');
        std::getline(pairStream, type);

        int count = std::stoi(countStr);
        for (int i = 0; i < count; ++i) {
            Fighter* f = new Fighter(type, name);
            fleet.push_back(f);
        }
    }
}

void AircraftCarrier::updateResults(int r) {
    if (r == 1) wins++;
    else if (r == -1) losses++;
}

Fighter* AircraftCarrier::getFirstAvailableFighter(std::string type) const {
    for (Fighter* f : fleet) {
        if (!f->isDestroyed() && !f->getPosition().isValid()) {
            if (type.empty() || f->getType() == type) {
                return f;
            }
        }
    }
    return nullptr;
}

int AircraftCarrier::purgeFleet() {
    int count = 0;
    auto it = fleet.begin();
    while (it != fleet.end()) {
        if ((*it)->isDestroyed()) {
            delete *it;
            it = fleet.erase(it);
            ++count;
        } else {
            ++it;
        }
    }
    return count;
}

void AircraftCarrier::showFleet() const {
    for (Fighter* f : fleet) {
        std::cout << *f;
        if (f->isDestroyed()) std::cout << " (X)";
        std::cout << std::endl;
    }
}

std::string AircraftCarrier::myFleet() const {
    if (fleet.empty()) return "";

    std::map<std::string, int> typeCount;
    std::vector<std::string> order;

    for (Fighter* f : fleet) {
        std::string type = f->getType();
        if (typeCount.find(type) == typeCount.end()) {
            order.push_back(type);
        }
        typeCount[type]++;
    }

    std::stringstream result;
    for (size_t i = 0; i < order.size(); ++i) {
        if (i > 0) result << ":";
        result << typeCount[order[i]] << "/" << order[i];
    }

    return result.str();
}

std::ostream& operator<<(std::ostream& os, const AircraftCarrier& a) {
    os << "Aircraft Carrier [" << a.name << " " << a.wins << "/" << a.losses << "] ";
    os << a.myFleet();
    return os;
}
