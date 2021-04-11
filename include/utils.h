#ifndef UTILS_H
#define UTILS_H

#include <string>


enum class WallsType {N = 1, E, NE, S, NS, ES, NES, W, NW, EW, NEW, SW, NSW, ESW};

extern std::string wallsTypeToStr(WallsType type);

#endif // UTILS_H
