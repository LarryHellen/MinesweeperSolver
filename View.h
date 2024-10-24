#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include "Model.h"
#include <SFML/Graphics.hpp>
#include "SpriteSheetCutter.h"

class View
{
private:
    static const int DELAY = 100;
    static const bool HAS_DELAY = true;
    Model* _model;

public:
    View(Model* model);
    sf::RenderWindow window;
    void step();
};git

#endif //VIEW_H
