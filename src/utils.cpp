#include "utils.h"

extern std::string wallsTypeToStr(WallsType type) {
    switch(type) {
        default:
        case WallsType::N:    return "tile_N";
        case WallsType::E:    return "tile_E";
        case WallsType::NE:   return "tile_NE";
        case WallsType::S:    return "tile_S";
        case WallsType::NS:   return "tile_NS";
        case WallsType::ES:   return "tile_ES";
        case WallsType::NES:  return "tile_NES";
        case WallsType::W:    return "tile_W";
        case WallsType::NW:   return "tile_NW";
        case WallsType::EW:   return "tile_EW";
        case WallsType::NEW:  return "tile_NEW";
        case WallsType::SW:   return "tile_SW";
        case WallsType::NSW:  return "tile_NSW";
        case WallsType::ESW:  return "tile_ESW";
    }
}
