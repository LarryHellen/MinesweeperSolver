#ifndef NODE_H
#define NODE_H

#include <vector>
#include <iostream>

class Node
{
private:
    int _neighbors;
    bool _is_bomb;
    bool _has_flag;

    bool is_selected;

    int _near_flags;

    std::vector<Node*> neighbor_grid;
    std::vector<std::vector<Node*>> _combinations;


    void generateCombinations(int start, std::vector<Node*> combination);
public:
    Node();

    void setBomb(bool isBomb);
    bool isBomb() const;


    // void setFlag(bool hasFlag);
    bool hasFlag() const;

    void setNeighbors(int neighbors);
    int getNeighbors() const;


    int get_near_flags() const;


    std::vector<Node*>& get_neighbor_grid();
    void set_neighbor_grid(const std::vector<Node*>& neighbor_grid);

    std::vector<std::vector<Node*>> get_combinations() const;
    void set_combinations(const std::vector<std::vector<Node*>>& combinations);

    void generateCombinations();

    void resetFlag();
    void placeFlag();

    bool canPlaceFlagN();

    bool is_is_selected() const;
    void set_is_selected(bool is_selected);


};

#endif //NODE_H
