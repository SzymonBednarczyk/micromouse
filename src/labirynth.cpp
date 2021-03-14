#include "labirynth.h"

Labirynth::Labirynth() {
    ;
}
Labirynth::~Labirynth(){
    ;
}

const int* Labirynth::getSpecificWallOfLabirynth(int &row, int &col) {
    try{
        return walls_of_labirynth_[row, col];
    } catch(...){
        std::cout << "Cant get specific field, indexes out of boundres: [" << row << ", " <<col <<"]\n\r";
    }
}

const int* Labirynth::getLabirynthWalls() {
    return walls_of_labirynth_[0, 0];
}
