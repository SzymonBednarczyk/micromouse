#include "labyrinth.h"

Labyrinth::Labyrinth() {
    ;
}
Labyrinth::~Labyrinth(){
    ;
}

const TileWalls& Labyrinth::getSpecificWallOfLabirynth(int row, int col) {
    if (row >= LABYRINTH_SIZE || col >= LABYRINTH_SIZE)
        throw std::out_of_range("indexe for labyrinth is out of range");
    return tile_walls_of_labirynth_[row][col];

}

const TileWalls* Labyrinth::getLabirynthWalls() {
    return &tile_walls_of_labirynth_[0][0];
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
    std::vector<std::string> labyrinth_strings;

    for (size_t i = 0; i < LABYRINTH_SIZE; i++)
    {
        std::string bottom_row, middle_row, top_row;

        for (size_t j = 0; j < LABYRINTH_SIZE; j++)
        {
            TileWalls walls = tile_walls_of_labirynth_[i][j];
            if (i == 0 && j == 0) {
                // print all sides (first tile)
                // bottom
                if (walls.southWall()) {
                    bottom_row += "XXX";
                } else {
                    bottom_row += "   ";
                }

                // sides
                if (walls.eastWall() && walls.westWall()) {
                    middle_row += "X?X";
                } else if (walls.eastWall()) {
                    middle_row += " *X";
                } else if (walls.westWall()) {
                    middle_row += "X? ";
                } else {
                    middle_row += " ? ";
                }

                // top
                if (walls.northWall()){
                    top_row += "XXX";
                } else {
                    if (walls.eastWall() && walls.westWall()) {
                        top_row += "X X";
                    } else if (walls.eastWall()) {
                        top_row += "  X";
                    } else if (walls.westWall()) {
                        top_row += "X  ";
                    } else {
                        top_row += "   ";
                    }
                }
            } else if (i == 0) {
                if (walls.northWall()){
                    top_row += "XX";
                } else {
                    if (walls.eastWall()) {
                        top_row += " X";
                    } else {
                        top_row += "  ";
                    }
                }

                // bottom
                if (walls.southWall()) {
                    bottom_row += "XX";
                } else {
                    bottom_row += "  ";
                }

                // right
                if (walls.eastWall()) {
                    middle_row += "?X";
                } else {
                    middle_row += "* ";
                }
            } else if (j == 0) {
                // print left, top, right (n-th row first tile)
                // top
                if (walls.northWall()){
                    top_row += "XXX";
                } else {
                    if (walls.eastWall() && walls.westWall()) {
                        top_row += "X X";
                    } else if (walls.eastWall()) {
                        top_row += "  X";
                    } else if (walls.westWall()) {
                        top_row += "X  ";
                    } else {
                        top_row += "   ";
                    }
                }

                // sides
                if (walls.eastWall() && walls.westWall()) {
                    middle_row += "X?X";
                } else if (walls.eastWall()) {
                    middle_row += " ?X";
                } else if (walls.westWall()) {
                    middle_row += "X? ";
                } else {
                    middle_row += " > ";
                }
            } else  {
                // print top, right (all other tiles)
                // top
                if (walls.northWall()){
                    top_row += "XX";
                } else {
                    if (walls.eastWall()) {
                        top_row += " X";
                    } else {
                        top_row += "  ";
                    }
                }

                // right
                if (walls.eastWall()) {
                    middle_row += "?X";
                } else {
                    middle_row += "? ";
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