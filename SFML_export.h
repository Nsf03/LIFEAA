#include <SFML/Graphics.hpp>
#include "Grid.h"

unsigned int x_max = 1800;
unsigned int y_max = 850;
float cell_size_max = 20;

sf::VideoMode make_window(unsigned int x_size, unsigned int y_size, unsigned int x_max, unsigned int y_max, float cell_max_size){
    unsigned int x = x_size;
    unsigned int y = y_size;
    float cell_size = 1;

    while (( x+x_size <= x_max) && (y+y_size<=y_max) && ((cell_size+1) <= cell_size_max))  {
        x += x_size;
        y += y_size;
        cell_size ++;

    };

    if (x > x_max || y > y_max){
        if (float(x_max)/float(x_size) > float(y_max)/float(y_size)){
            cell_size = float(y_max)/float(y_size);
            x = int(cell_size*x_size)+1;
            y = y_max;
        }
        else{
            cell_size = float(x_max)/float(x_size);
            x = int(cell_size*y_size)+1;
            x = x_max;
        };
    };

    return sf::VideoMode(x, y);
}

void Visual(sf::RenderWindow *window, float cell_size,  Grid *g) {
    std::cout << 1;
    auto rectangles = new sf::RectangleShape[g->y_size*g->x_size+1];

    for (int i = 0; i < g->y_size; i++) {
        for (int j = 0; j < g->x_size; j++) {
            rectangles[i*g->x_size + j].setPosition(j*cell_size, i*cell_size);
            if (g->field[i*g->x_size + j].state == 0){
                rectangles[i*g->x_size + j].setFillColor(sf::Color(0, 0, 0));
        }
            else if (g->field[i*g->x_size + j].state == 1){
                rectangles[i*g->x_size + j].setFillColor(sf::Color(255, 255, 255));
            }
            else if (g->field[i*g->x_size + j].state == 2){
                rectangles[i*g->x_size + j].setFillColor(sf::Color(102, 255, 255));
            }
    };



        for (int j = 0; j < g->y_size*g->x_size+1; ++j) {
            window->draw(rectangles[j]);
        }
        window->display();

        delete []rectangles;


    }
}


