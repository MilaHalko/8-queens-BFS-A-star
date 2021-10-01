#include "BFS.hpp"

bool BFS(Board board) {
    Node *current = new Node(board);
    queue<Node*> nodes;
    nodes.push(current);
    
    do {
        current = nodes.front();
        current->board.Output();
        nodes.pop();
        if(current->board.GoodState()) {
            current->board.Output();
            return true;
        }
        current->generateChildren(nodes);
        
    } while (!nodes.empty());
    return false;
}
