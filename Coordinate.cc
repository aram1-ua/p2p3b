// Y5624889T ANJA RAPHAELA ALUM MILLARES
#include "Coordinate.h"
using namespace std;

Coordinate::Coordinate() : row(-1), column(-1) {}

Coordinate::Coordinate(int row, int column) : row(row), column(column) {}

int Coordinate::getRow() const {
    return row;
}

int Coordinate::getColumn() const {
    return column;
}

void Coordinate::setRow(int r) {
    this->row = r;
}

void Coordinate::setColumn(int c) {
    this->column = c;
}

bool Coordinate::isValid() const {
    return row >= 0 && column >= 0;
}

void Coordinate::reset() {
    row = -1;
    column = -1;
}

ostream& operator<<(ostream& os, const Coordinate& c) {
    if (c.isValid()) {
        os << "[" << c.row << "," << c.column << "]";
    } else {
        os << "[-,-]";
    }
    return os;
}
