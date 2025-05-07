// Y5624889T ANJA RAPHAELA ALUM MILLARES
#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>

class Coordinate {
private:
    int row;
    int column;

public:
    Coordinate();
    Coordinate(int row, int column);

    int getRow() const;
    int getColumn() const;

    void setRow(int row);
    void setColumn(int column);

    bool isValid() const;
    void reset();

    friend std::ostream& operator<<(std::ostream& os, const Coordinate& c);
};

#endif
