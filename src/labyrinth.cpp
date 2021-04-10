#include "labyrinth.h"

Labyrinth::Labyrinth() {
    ;
}
Labyrinth::~Labyrinth(){
    ;
}

const int* const Labyrinth::getSpecificWallOfLabirynth(int row, int col) {
    try{
        return walls_of_labirynth_[col, row];
    } catch(...){
        std::cout << "Can't get specific field, indexes out of boundres: [" << row << ", " <<col <<"]\n\r";
    }
}

const int* Labyrinth::getLabirynthWalls() {
    return walls_of_labirynth_[0, 0];
}

bool Labyrinth::isKthBitSet(int n, int k)
{
    if (n & (1 << (k - 1))){
        // std::cout << "Number: " << n << "bit " << k << " SET" << std::endl;
        return true;
    }
    else {
        // std::cout << "Number: " << n << "bit " << k << " NOT SET" << std::endl;
        return false;
    }
}

void Labyrinth::printLabyrinth() {
    int rows = sizeof walls_of_labirynth_ / sizeof walls_of_labirynth_[0];
    int cols = sizeof walls_of_labirynth_[0] / sizeof(int);
    std::vector<std::string> labyrinth_strings;
    for (size_t i = 0; i < cols; i++)
    {
        std::string bottom_row, middle_row, top_row;

        for (size_t j = 0; j < rows; j++)
        {
            int walls = walls_of_labirynth_[i][j];
            if (i == 0 && j == 0) {
                // print all sides (first tile)
                // bottom
                if (isKthBitSet(walls, 3)) {
                    bottom_row += "XXX";
                } else {
                    bottom_row += "   ";
                }

                // sides
                if (isKthBitSet(walls, 2) && isKthBitSet(walls, 4)) {
                    middle_row += "X*X";
                } else if (isKthBitSet(walls, 2)) {
                    middle_row += " *X";
                } else if (isKthBitSet(walls, 4)) {
                    middle_row += "X* ";
                } else {
                    middle_row += " * ";
                }

                // top
                if (isKthBitSet(walls, 1)){
                    top_row += "XXX";
                } else {
                    if (isKthBitSet(walls, 2) && isKthBitSet(walls, 4)) {
                        top_row += "X X";
                    } else if (isKthBitSet(walls, 2)) {
                        top_row += "  X";
                    } else if (isKthBitSet(walls, 4)) {
                        top_row += "X  ";
                    } else {
                        top_row += "   ";
                    }
                }
            } else if (i == 0) {
                if (isKthBitSet(walls, 1)){
                    top_row += "XX";
                } else {
                    if (isKthBitSet(walls, 2)) {
                        top_row += " X";
                    } else {
                        top_row += "  ";
                    }
                }

                // bottom
                if (isKthBitSet(walls, 3)) {
                    bottom_row += "XX";
                } else {
                    bottom_row += "  ";
                }

                // right
                if (isKthBitSet(walls, 2)) {
                    middle_row += "*X";
                } else {
                    middle_row += "* ";
                }
            } else if (j == 0) {
                // print left, top, right (n-th row first tile)
                // top
                if (isKthBitSet(walls, 1)){
                    top_row += "XXX";
                } else {
                    if (isKthBitSet(walls, 2) && isKthBitSet(walls, 4)) {
                        top_row += "X X";
                    } else if (isKthBitSet(walls, 2)) {
                        top_row += "  X";
                    } else if (isKthBitSet(walls, 4)) {
                        top_row += "X  ";
                    } else {
                        top_row += "   ";
                    }
                }

                // sides
                if (isKthBitSet(walls, 2) && isKthBitSet(walls, 4)) {
                    middle_row += "X*X";
                } else if (isKthBitSet(walls, 2)) {
                    middle_row += " *X";
                } else if (isKthBitSet(walls, 4)) {
                    middle_row += "X* ";
                } else {
                    middle_row += " * ";
                }
            } else  {
                // print top, right (all other tiles)
                // top
                if (isKthBitSet(walls, 1)){
                    top_row += "XX";
                } else {
                    if (isKthBitSet(walls, 2)) {
                        top_row += " X";
                    } else {
                        top_row += "  ";
                    }
                }

                // right
                if (isKthBitSet(walls, 2)) {
                    middle_row += "*X";
                } else {
                    middle_row += "* ";
                }
            }
        }
        if (i == 0)
            labyrinth_strings.push_back(bottom_row);
        labyrinth_strings.push_back(middle_row);
        labyrinth_strings.push_back(top_row);
    }
    for (auto it = labyrinth_strings.rbegin(); it != labyrinth_strings.rend(); it++) {
        std::cout << *it << std::endl;
    }

}