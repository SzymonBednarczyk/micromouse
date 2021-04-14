#ifndef GUI_STYLE_H
#define GUI_STYLE_H

#include <SFML/Graphics.hpp>


class GuiStyle {
public:
    sf::Color body_col;
    sf::Color body_highlight_col;
    sf::Color border_col;
    sf::Color border_highlight_col;
    sf::Color text_col;
    sf::Color text_highlight_col;
    sf::Font* font;

    float border_size;

    GuiStyle(sf::Font* font, float border_size,
        sf::Color body_col, sf::Color border_col, sf::Color text_col,
        sf::Color body_highlight_col, sf::Color border_highlight_col, sf::Color text_highlight_col) {
        this->body_col = body_col;
        this->border_col = border_col;
        this->text_col = text_col;
        this->body_highlight_col = body_highlight_col;
        this->border_highlight_col = border_highlight_col;
        this->text_highlight_col = text_highlight_col;
        this->font = font;
        this->border_size = border_size;
    }

    GuiStyle() {}
};

#endif // GUI_STYLE_H
