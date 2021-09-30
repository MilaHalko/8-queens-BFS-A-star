#pragma once
#include "libraries.hpp"
#include "Tree&Node.hpp"

class Board {
    vector<vector<int>> squares;
public:
    Board();
    void GetFirstState(string);
    bool GoodState();
    void Output();
    ~Board();
    
    friend class Tree;
};
