
#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <iostream>
#include <vector>

class Labyrinth {
public:
    Labyrinth();
    virtual ~Labyrinth();
    const int* getLabirynthWalls();
    const int* const getSpecificWallOfLabirynth(int row, int col);
    void printLabyrinth();
private:
    int walls_of_labirynth_ [3][3] = {{14, 14, 14}, // 0
                                      {10, 8 , 3},  // 1
                                      {9 , 1 , 7}}; // 2
    //  _______
    //2 |   __|
    //1 | |   |
    //0 |R| | |
    //  ^^^^^^^
    //   0 1 2

    bool isKthBitSet(int n, int k);
};

#endif // LABYRINTH_H
