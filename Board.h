// Y5624889T ANJA RAPHAELA ALUM MILLARES
#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Fighter.h"

class Board {
private:
    int size;
    std::vector<std::vector<Fighter*>> board;

public:
    Board(int size);

    Fighter* getFighter(Coordinate c) const;
    bool inside(Coordinate c) const;
    int launch(Coordinate c, Fighter* f);
    int getSize() const;
};

#endif
