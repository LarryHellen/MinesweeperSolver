#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <cstdlib>
#include <ctime>


#include "Model.h"
#include "View.h"

class Controller
{
private:
    static const int CHANCE = 10; //chance a node is bomb = 1 / CHANCE
    Model* _model;
    View* _view;

    Node* selected;

public:
    Controller(Model* model, View* view);
    void setup();

    bool solve(int index);

    bool canPlaceFlagC(std::vector<Node*> combination);

    bool isSolved();
};

#endif //CONTROLLER_H
