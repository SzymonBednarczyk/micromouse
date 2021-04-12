
#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <string>


enum class WallsType {N = 1, E, NE, S, NS, ES, NES, W, NW, EW, NEW, SW, NSW, ESW};

extern std::string wallsTypeToStr(WallsType type);

enum class RobotDirection {N = 0, E, S, W};


#endif // DATA_STRUCTURES_H
