#include "Model.h"


Model::Model() : _nodes(ROWS, std::vector<Node>(COLS))
{
}

int Model::getRows() const {
    return ROWS;
}

int Model::getCols() const {
    return COLS;
}

std::vector<std::vector<Node>>& Model::getNodes() {
    return _nodes;
}

void Model::setNodes(const std::vector<std::vector<Node>>& nodes) {
    _nodes = nodes;
}

std::vector<Node*> Model::get_num_nodes() const
{
    return _num_nodes;
}

void Model::set_num_nodes(const std::vector<Node*>& num_nodes)
{
    _num_nodes = num_nodes;
}
