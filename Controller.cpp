#include "Controller.h"

Controller::Controller(Model* model, View* view) : _model(model), _view(view), selected(nullptr)
{
    setup();
}

void Controller::setup()
{
    std::srand(time(0));
    int rows = _model->getRows();
    int cols = _model->getCols();
    auto& nodes = _model->getNodes();

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (std::rand() % CHANCE == 0)
            {
                nodes[row][col].setBomb(true);
            }
        }
    }

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            int bombCount = 0;

            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    int r = row + i;
                    int c = col + j;
                    if (r >= 0 && r < rows && c >= 0 && c < cols && !(i == 0 && j == 0))
                    {
                        if (nodes[r][c].isBomb())
                            bombCount++;

                        nodes[row][col].get_neighbor_grid().push_back(&nodes[r][c]);
                    }

                }
            }

            if(nodes[row][col].isBomb())
                bombCount = 0;

            nodes[row][col].setNeighbors(bombCount);
        }
    }

    std::vector<Node*> num_nodes;
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if(nodes[row][col].getNeighbors() != 0)
            {
                nodes[row][col].generateCombinations();
                num_nodes.push_back(&nodes[row][col]);
            }
        }
    }
    _model->set_num_nodes(num_nodes);

    _view->step();

    solve(0);

}

bool Controller::solve(int index)
{

    std::vector<Node*> num_nodes = _model->get_num_nodes();

    if(index == num_nodes.size())
    {
        return isSolved();
    }


    for(auto& combination : num_nodes[index]->get_combinations())
    {
        if(selected != nullptr)
        {
            selected->set_is_selected(false);
        }
        selected = num_nodes[index];
        selected->set_is_selected(true);
        _view->step();

        if(canPlaceFlagC(combination))
        {
            std::vector<Node*> newlyPlacedFlags;

            for(Node* n : combination)
            {
                if(!n->hasFlag())
                {
                    n->placeFlag();
                    newlyPlacedFlags.push_back(n);

                    _view->step();
                }
            }

            if(solve(index + 1))
            {
                return true;
            }

            if(selected != nullptr)
            {
                selected->set_is_selected(false);
            }
            selected = num_nodes[index];
            selected->set_is_selected(true);
            _view->step();

            for(Node* n : newlyPlacedFlags)
            {
                n->resetFlag();

                _view->step();
            }
        }
    }

    return false;
}

bool Controller::canPlaceFlagC(std::vector<Node*> combination)
{
    for(Node* c : combination)
    {
        if(!c->canPlaceFlagN())
            return false;
    }
    return true;
}

bool Controller::isSolved()
{
    int rows = _model->getRows();
    int cols = _model->getCols();
    auto& nodes = _model->getNodes();


    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (!nodes[row][col].hasFlag() && nodes[row][col].get_near_flags() != nodes[row][col].getNeighbors())
                return false;
        }
    }

    return true;
}
