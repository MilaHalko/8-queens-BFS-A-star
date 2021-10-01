#include "Node_BFS.hpp"
//Children_Node~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Node::generateChildren(queue<Node*> &nodes) {
    Board subBoard;
    for (int row = 0; row < boardSize; row++) {
        for (int column = 0; column < boardSize; column++) {
            subBoard.squares[row][column] = board.squares[row][column];
        }
    }
    for (int row = 0; row < boardSize; row++) {
        for (int column = 0; column < boardSize; column++) {
            if (board.squares[row][column] == 1) {
                
                subBoard.squares[row][column] = 0;
                for (int subColumn = 0; subColumn < boardSize; subColumn++) {
                    if (subColumn != column) {
                        subBoard.squares[row][subColumn] = 1;
                        Node *child = new Node(subBoard);
                        nodes.push(child);
                        subBoard.squares[row][subColumn] = 0;
                    }
                }
                subBoard.squares[row][column] = 1;
                continue;
            }
        }
    }
}
