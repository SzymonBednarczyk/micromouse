#include <iostream>
#include "graphical_simulation.h"

int main()
{
    GraphicalSimulation GraphicalSimulation;
    // Game loop
    while (GraphicalSimulation.getWindowIsOpen())
    {
        GraphicalSimulation.update();

        GraphicalSimulation.render();
    }

    return 0;
}