#include "data_structures.h"

extern std::string wallsTypeToStr(WallsType type) {
    switch(type) {
        default:              return "None";
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
        case WallsType::NESW: return "tile_NESW";
        case WallsType::NONE: return "tile_NONE";
    }
}

std::ostream &operator << (std::ostream &os, const WallsType &wall_type) {
    switch(wall_type)
	{
        case WallsType::N:    os << "N"; break;
        case WallsType::E:    os << "E"; break;
        case WallsType::NE:   os << "NE"; break;
        case WallsType::S:    os << "S"; break;
        case WallsType::NS:   os << "NS"; break;
        case WallsType::ES:   os << "ES"; break;
        case WallsType::NES:  os << "NES"; break;
        case WallsType::W:    os << "W"; break;
        case WallsType::NW:   os << "NW"; break;
        case WallsType::EW:   os << "EW"; break;
        case WallsType::NEW:  os << "NEW"; break;
        case WallsType::SW:   os << "SW"; break;
        case WallsType::NSW:  os << "NSW"; break;
        case WallsType::ESW:  os << "ESW"; break;
        case WallsType::NESW: os << "NESW"; break;
        case WallsType::NONE: os << "NONE"; break;
    }

	return os;
}

extern std::string wallIntToStr(WallsType type) {
    int wall_int = static_cast<int>(type);
    return std::to_string(wall_int);
}

std::ostream &operator << (std::ostream &os, const Direction &direction) {
    switch(direction)
	{
        case Direction::N:    os << "N"; break;
        case Direction::E:    os << "E"; break;
        case Direction::S:    os << "S"; break;
        case Direction::W:    os << "W"; break;
    }

	return os;
}

std::ostream &operator << (std::ostream &os, const GuiType &gui_type) {
    switch(gui_type)
	{
        case GuiType::TEXT :            os << "TEXT"; break;
        case GuiType::STOP:             os << "STOP"; break;
        case GuiType::START:            os << "START"; break;
        case GuiType::SENSORS:          os << "SENSORS"; break;
        case GuiType::PATH_ALGORITHMS:  os << "PATH_ALGORITHMS"; break;
        case GuiType::SAVE:             os << "SAVE"; break;
        case GuiType::LOAD:             os << "LOAD"; break;
        case GuiType::WALL_FOLLOWER:    os << "WALL_FOLLOWER"; break;
        case GuiType::BRUTE_FORCE:      os << "BRUTE_FORCE"; break;
        case GuiType::IR_SENSOR:        os << "IR_SENSOR"; break;
        case GuiType::LASER_SCANNER:    os << "LASER_SCANNER"; break;
    }

	return os;
}

extern std::string guiTypeToStr(GuiType type) {
    switch(type)
	{
        default:                        return "NONE";
        case GuiType::TEXT :            return "TEXT";
        case GuiType::STOP:             return "STOP";
        case GuiType::START:            return "START";
        case GuiType::SENSORS:          return "SENSORS";
        case GuiType::PATH_ALGORITHMS:  return "PATH_ALGORITHMS";
        case GuiType::SAVE:             return "SAVE";
        case GuiType::LOAD:             return "LOAD";
        case GuiType::WALL_FOLLOWER:    return "WALL_FOLLOWER";
        case GuiType::BRUTE_FORCE:      return "BRUTE_FORCE";
        case GuiType::IR_SENSOR:        return "IR_SENSOR";
        case GuiType::LASER_SCANNER:    return "LASER_SCANNER";
    }
}

