// DNI 12345678X GARCIA GARCIA, JUAN MANUEL
#include "Coordinate.h"

Coordinate::Coordinate() : row(-1), column(-1) {}

Coordinate::Coordinate(int row, int column) : row(row), column(column) {}

int Coordinate::getRow() const {
    return row;
}

int Coordinate::getColumn() const {
    return column;
}

void Coordinate::setRow(int r) {
    row = r;
}

void Coordinate::setColumn(int c) {
    column = c;
}

bool Coordinate::isValid() const {
    return row >= 0 && column >= 0;
}

void Coordinate::reset() {
    row = -1;
    column = -1;
}

std::ostream& operator<<(std::ostream& os, const Coordinate& c) {
    if (c.isValid()) {
        os << "[" << c.row << "," << c.column << "]";
    } else {
        os << "[-,-]";
    }
    return os;
}
