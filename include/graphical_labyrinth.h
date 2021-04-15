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
    Labyrinth* labirynth();
    bool loadLabyrinthFromFile(std::string file_path);
    void saveLabyrinthToFile(std::string file_path);

    static const int DRAWING_ORIGIN_X = 150;
    static const int DRAWING_ORIGIN_Y = 800;
private:
    Labyrinth labirynth_;
    LabyrinthTile tiles_ [Labyrinth::LABYRINTH_SIZE][Labyrinth::LABYRINTH_SIZE];
};

#endif // GRAPHICAL_LABYRINTH_H
