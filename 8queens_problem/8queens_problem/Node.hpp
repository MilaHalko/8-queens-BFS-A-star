#pragma once
#include "Board.hpp"
class Node {
    Board board;
    Node(Board board) {
        this->board = board;
    }
    friend class Algorithm;
};
