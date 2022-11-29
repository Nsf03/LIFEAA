#include <iostream>
#include <string>
#include "SFML_export.h"
#include <unistd.h>



int main() {
    Grid_2c g(50, 50);
    unsigned int steps = 100000;
    float cell_size=5;
    sf::RenderWindow window(make_window(g.x_size, g.y_size, x_max, y_max, cell_size_max), "SFML Application");

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    for (int step = 0; step < steps; ++step){
        Visual(&window, cell_size, &g);
        g.step();
        window.clear();
    };



    return 0;
}
