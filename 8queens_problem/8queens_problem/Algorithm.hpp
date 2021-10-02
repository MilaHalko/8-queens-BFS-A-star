#pragma once
#include "Node.hpp"

class Algorithm {
    int statesNumBFS, statesNumAStar;
    int iterationBFS, iterationAStar;
    
    friend bool operator<(const pair<int, Board>&, const pair<int, Board>&);
    using pr_queue = priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, std::greater<pair<int, Node*>>>;
    
    bool BFS(Board);
    bool AStar(Board);

    void generateChildrenBFS(queue<Node*>&, Node*);
    void generateChildrenAStar(pr_queue&, Node*);
    
public:
    Algorithm(): statesNumBFS(0), statesNumAStar(0), iterationBFS(0), iterationAStar(0) {}
    void startAlgo(Board);
};
