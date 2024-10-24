#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "Node.h"

class Model
{
private:
    static const int ROWS = 10;
    static const int COLS = 10;
    std::vector<std::vector<Node>> _nodes;
    std::vector<Node*> _num_nodes;

public:
    Model();



    int getRows() const;
    int getCols() const;
    std::vector<std::vector<Node>>& getNodes();
    void setNodes(const std::vector<std::vector<Node>>& nodes);


    std::vector<Node*> get_num_nodes() const;
    void set_num_nodes(const std::vector<Node*>& num_nodes);
};

#endif //MODEL_H
