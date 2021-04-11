#ifndef GRAPHICAL_LABYRINTH_H
#define GRAPHICAL_LABYRINTH_H

#include "labyrinth.h"
#include "labyrinth_tile.h"
#include "texture_manager.h"

class GraphicalLabyrinth {
public:
    GraphicalLabyrinth();
    virtual ~GraphicalLabyrinth(){}
    void setSprites(TextureManager *texture_manager);
    void draw(sf::RenderWindow* window);
    void update();
    Labyrinth labirynth() const;
private:
    Labyrinth labirynth_;
    LabyrinthTile tiles_ [3][3];
    int drawing_origin_x_ = 100;
    int drawing_origin_y_ = 300;
};

#endif // GRAPHICAL_LABYRINTH_H
