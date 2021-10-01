#pragma once
#include "Board.hpp"
struct Node {
    Board board;
    
    Node(Board board) {
        this->board = board;
    }
    void generateChildren(queue<Node*>&);
};
