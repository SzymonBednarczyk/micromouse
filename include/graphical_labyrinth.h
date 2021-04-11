#ifndef GRAPHICAL_LABYRINTH_H
#define GRAPHICAL_LABYRINTH_H

#include "labyrinth.h"
#include "labyrinth_tile.h"
#include "texture_manager.h"


class GraphicalLabyrinth {
public:
    GraphicalLabyrinth();
    virtual ~GraphicalLabyrinth(){}
    void loadEntity(TextureManager *texture_manager);
    void draw(sf::RenderWindow* window);
    void update();
    Labyrinth labirynth() const;

    static const int DRAWING_ORIGIN_X = 300;
    static const int DRAWING_ORIGIN_Y = 300;
private:
    Labyrinth labirynth_;
    LabyrinthTile tiles_ [Labyrinth::LABYRINTH_SIZE][Labyrinth::LABYRINTH_SIZE];
};

#endif // GRAPHICAL_LABYRINTH_H
