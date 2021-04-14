
#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <string>
#include <iostream>


enum class WallsType {UNKNOWN = 0, N, E, NE, S, NS, ES, NES, W, NW, EW, NEW, SW, NSW, ESW};

extern std::string wallsTypeToStr(WallsType type);

std::ostream &operator << (std::ostream &os, const WallsType &wall_type);

extern std::string wallIntToStr(WallsType type);

enum class Direction {N = 0, E, S, W};

std::ostream &operator << (std::ostream &os, const Direction &direction);

enum class GuiType{NONE = 0, TEXT, START, STOP, SENSORS, PATH_ALGORITHMS, SAVE, LOAD};

std::ostream &operator << (std::ostream &os, const GuiType &gui_type);

extern std::string guiTypeToStr(GuiType type);


#endif // DATA_STRUCTURES_H
