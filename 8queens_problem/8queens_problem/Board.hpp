#pragma once
#include "libraries.hpp"

class Board {
    vector<vector<int>> squares;
public:
    Board();
    void GetFirstState(string);
    bool GoodState();
    void Output();
    int GetF2();
    ~Board();
    
    friend class Algorithm;
};
