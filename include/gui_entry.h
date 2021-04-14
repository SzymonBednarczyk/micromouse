#ifndef GUI_ENTRY_H
#define GUI_ENTRY_H

#include <SFML/Graphics.hpp>
#include "data_structures.h"


class GuiEntry {
public:
    sf::RectangleShape shape;
    GuiType type;
    sf::Text text;

    GuiEntry(const GuiType& type, sf::RectangleShape shape, sf::Text text)
    {
        this->type = type;
        this->shape = shape;
        this->text = text;
    }

    GuiEntry() {}
};

#endif // GUI_ENTRY_H
