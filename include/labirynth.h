#ifndef LABIRYNTH_H
#define LABIRYNTH_H

#include <iostream>

class Labirynth {
public:
    Labirynth();
    virtual ~Labirynth();
    const int* getLabirynthWalls();
    const int* getSpecificWallOfLabirynth(int &row, int &col);
private:
    int walls_of_labirynth_ [3][3] = {{14, 14, 14},
                                      {10, 8 , 3},
                                      {9 , 1 , 7}};
    //  _____
    // |   __|
    // | |   |
    // |R| | |
    // ^^^^^^^
};

#endif