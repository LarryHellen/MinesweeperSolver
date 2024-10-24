#include "Node.h"

Node::Node() : _neighbors(0), _is_bomb(false), _has_flag(false), _near_flags(0) {}


void Node::setBomb(bool isBomb)
{
    _is_bomb = isBomb;
}

bool Node::isBomb() const
{
    return _is_bomb;
}

// void Node::setFlag(bool hasFlag)
// {
//     _has_flag = hasFlag;
// }
//
bool Node::hasFlag() const
{
    return _has_flag;
}


void Node::setNeighbors(int neighbors)
{
    _neighbors = neighbors;
}

int Node::getNeighbors() const
{
    return _neighbors;
}

int Node::get_near_flags() const
{
    return _near_flags;
}

std::vector<Node*>& Node::get_neighbor_grid()
{
    return neighbor_grid;
}

void Node::set_neighbor_grid(const std::vector<Node*>& neighbor_grid)
{
    this->neighbor_grid = neighbor_grid;
}

std::vector<std::vector<Node*>> Node::get_combinations() const
{
    return _combinations;
}

void Node::set_combinations(const std::vector<std::vector<Node*>>& combinations)
{
    _combinations = combinations;
}

void Node::generateCombinations(int start, std::vector<Node*> combination)
{
    if(_neighbors == 0)
        return;

    if(combination.size() == _neighbors)
    {
        _combinations.push_back(combination);
        return;
    }

    for(int i = start; i < neighbor_grid.size(); i++)
    {
        if(neighbor_grid[i]->_neighbors == 0)
        {
            combination.push_back(neighbor_grid[i]);
            generateCombinations(i+1, combination);
            combination.pop_back();
        }
    }
}

void Node::generateCombinations()
{
    generateCombinations(0, std::vector<Node*>());
}

void Node::resetFlag()
{
    if(!_has_flag)
        std::cout<<"resetting no flag!";

    _has_flag = false;
    for(Node* n : neighbor_grid)
    {
        n->_near_flags--;
    }
}

void Node::placeFlag()
{
    if(_has_flag)
        std::cout << "cant place flag on flag";

    _has_flag = true;
    for(Node* n : neighbor_grid)
    {
        n->_near_flags++;
    }
}

bool Node::canPlaceFlagN()
{
    if(_has_flag)
        return true;

    for(Node* n : neighbor_grid)
    {
        if (n->_neighbors != 0 && n->_neighbors == n->_near_flags)
            return false;
    }

    return true;
}

bool Node::is_is_selected() const
{
    return is_selected;
}

void Node::set_is_selected(bool is_selected)
{
    this->is_selected = is_selected;
}

