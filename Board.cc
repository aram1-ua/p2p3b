// Y5624889T ANJA RAPHAELA ALUM MILLARES
#include "Board.h"
#include <stdexcept>
using namespace std;

Board::Board(int size) : size(size) {
    if (size <= 0) {
        throw invalid_argument("Wrong size");
    }
    board.resize(size, vector<Fighter*>(size, nullptr));
}

Fighter* Board::getFighter(Coordinate c) const {
    if (!inside(c)) {
        return nullptr;
    }
    return board[c.getRow()][c.getColumn()];
}

bool Board::inside(Coordinate c) const {
    return c.getRow() >= 0 && c.getRow() < size && c.getColumn() >= 0 && c.getColumn() < size;
}

int Board::getSize() const {
    return size;
}

int Board::launch(Coordinate c, Fighter* f) {
    if (!f || !inside(c) || f->getPosition().isValid()) {
        return 0;
    }

    Fighter* current = board[c.getRow()][c.getColumn()];
    if (current == nullptr) {
        board[c.getRow()][c.getColumn()] = f;
        f->setPosition(c);
        return 0;
    }

    if (current->getAircraftCarrier() == f->getAircraftCarrier()) {
        return 0;
    }

    // Enemy present, simulate fight
    int result = f->fight(current);
    if (result == 1) {
        // f won: replace enemy
        current->resetPosition();
        board[c.getRow()][c.getColumn()] = f;
        f->setPosition(c);
    }
    // If result == -1 enemy wins: nothing change
    return result;
}
