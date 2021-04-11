#include <iostream>
#include "graphical_simulation.h"
#include "labyrinth.h"

int main()
{
    Labyrinth labirynth_test;
    labirynth_test.printLabyrinth();
    GraphicalSimulation GraphicalSimulation;
    // Game loop
    while (GraphicalSimulation.getWindowIsOpen())
    {
        GraphicalSimulation.update();

        GraphicalSimulation.render();
    }

    return 0;
}