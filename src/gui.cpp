#include "gui.h"

/* Constructor */
Gui::Gui(sf::Vector2f dimensions, int padding, bool horizontal,
         GuiStyle& style, std::vector<std::pair<std::string, GuiType>> entries) {
    visible_ = false;
    horizontal_ = horizontal;
    style_ = style;
    dimensions_ = dimensions;
    padding_ = padding;

    /* Construct the background shape */
    sf::RectangleShape shape;
    shape.setSize(dimensions_);
    shape.setFillColor(style_.body_col);
    shape.setOutlineThickness(-style_.border_size);
    shape.setOutlineColor(style_.border_col);

    /* Construct each gui entry */
    for(auto entry : entries) {
        /* Construct the text */
        sf::Text text;
        text.setString(entry.first);
        text.setFont(*style_.font);
        text.setFillColor(style_.text_col);
        text.setCharacterSize(dimensions_.y - style_.border_size - padding_);

        entries_.push_back(GuiEntry(entry.second, shape, text));
    }
}

sf::Vector2f Gui::getSize() {
    return sf::Vector2f(
        dimensions_.x, dimensions_.y * entries_.size());
}

int Gui::getEntry(const sf::Vector2f mouse_pos) {
    if(entries_.size() == 0 || !visible_)
        return -1;

    for(int i = 0; i < entries_.size(); ++i) {
        /* Translate point to use the entry's local coordinates*/
        sf::Vector2f point = mouse_pos;
        point += entries_[i].shape.getOrigin();
        point -= entries_[i].shape.getPosition();

        if(point.x < 0 ||
           point.x > entries_[i].shape.getScale().x * dimensions_.x) continue;

        if(point.y < 0 ||
           point.y > entries_[i].shape.getScale().y * dimensions_.y) continue;
        return i;
    }

    return -1;
}

void Gui::setEntryText(int entry, std::string text) {
    if(entry >= entries_.size() || entry < 0) return;

    entries_[entry].text.setString(text);

    return;
}

void Gui::setDimensions(sf::Vector2f dimensions) {
    dimensions_ = dimensions;

    for(auto& entry : entries_) {
        entry.shape.setSize(dimensions);
        entry.text.setCharacterSize(dimensions.y-style_.border_size - padding_);
    }

    return;
}

void Gui::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if(!visible_) return;

    for(auto entry : entries_) {
        target.draw(entry.shape);
        target.draw(entry.text);
    }
}

void Gui::show() {
    sf::Vector2f offset(0.0f, 0.0f);

    visible_ = true;

    for(auto& entry : entries_) {
        // Set the origin of the entry
        sf::Vector2f origin = getOrigin();
        origin -= offset;
        entry.shape.setOrigin(origin);
        entry.text.setOrigin(origin);

        // Compute the position of the entry
        entry.shape.setPosition(getPosition());
        entry.text.setPosition(getPosition());

        if(horizontal_)
            offset.x += dimensions_.x;
        else
            offset.y += dimensions_.y;
    }
}

void Gui::hide() {
    visible_ = false;
}

void Gui::highlight(const int entry) {
    for(int i = 0; i < entries_.size(); ++i) {
        if(i == entry) {
            entries_[i].shape.setFillColor(style_.body_highlight_col);
            entries_[i].shape.setOutlineColor(style_.border_highlight_col);
            entries_[i].text.setFillColor(style_.text_highlight_col);
        }
        else {
            entries_[i].shape.setFillColor(style_.body_col);
            entries_[i].shape.setOutlineColor(style_.border_col);
            entries_[i].text.setFillColor(style_.text_col);
        }
    }
}

GuiType Gui::activate(const int entry) {
    if(entry == -1)
        return GuiType::NONE;

    return entries_[entry].type;
}

GuiType Gui::activate(const sf::Vector2f mouse_pos) {
    int entry = getEntry(mouse_pos);

    return activate(entry);
}


std::vector<GuiEntry> Gui::entries() const { return entries_; }

void Gui::setEntries(const std::vector<GuiEntry> &entries) { entries_ = entries; }

bool Gui::visible() const { return visible_; }
