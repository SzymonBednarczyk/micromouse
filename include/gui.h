#ifndef GUI_H
#define GUI_H

#include "gui_style.h"
#include "gui_entry.h"


class Gui : public sf::Transformable, public sf::Drawable {
public:
    Gui(sf::Vector2f dimensions, int padding, bool horizontal,
        GuiStyle& style, std::vector<std::pair<std::string, GuiType>> entries);

    /**
     * @brief Get the size of all gui
     *
     * @return sf::Vector2f size
     */
    sf::Vector2f getSize();

    /* Return the entry that the mouse is hovering over. Returns
     * -1 if the mouse if outside of the Gui */

    /**
     * @brief Get index of entry the mouse is hovering over
     *
     * @param mouse_pos position of mouse in screen coordinates
     * @return int index of entry, -1 if mouse outside gui
     */
    int getEntry(const sf::Vector2f mouse_pos);

    /* Change the text of an entry */
    void setEntryText(int entry, std::string text);

    /* Change the entry dimensions */
    void setDimensions(sf::Vector2f dimensions);

    /* Draw the menu */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    void show();

    void hide();

    /* Highlights an entry of the menu */
    void highlight(const int entry);

    /* Return the gui type bound to the entry */
    GuiType activate(const int entry);
    GuiType activate(const sf::Vector2f mouse_pos);

    std::vector<GuiEntry> entries() const;
    void setEntries(const std::vector<GuiEntry> &entries);

    bool visible() const;
    void setVisible(bool visible);

private:
    std::vector<GuiEntry> entries_;

    bool visible_;
    /* If true the menu entries will be horizontally, not vertically, adjacent */
    bool horizontal_;

    GuiStyle style_;

    sf::Vector2f dimensions_;

    int padding_;
};

#endif // GUI_H
