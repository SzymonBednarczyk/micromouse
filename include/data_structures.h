
#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <string>


enum class WallsType {UNKNOWN = 0, N, E, NE, S, NS, ES, NES, W, NW, EW, NEW, SW, NSW, ESW};

extern std::string wallsTypeToStr(WallsType type);

enum class Direction {N = 0, E, S, W};


#endif // DATA_STRUCTURES_H
