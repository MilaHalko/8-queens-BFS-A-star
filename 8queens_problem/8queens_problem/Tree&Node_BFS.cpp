#include "Tree&Node_BFS.hpp"

Tree::Tree(Board board) {
    root = new Node(board);
    depth = 1;
    nodeNum = 1;
}

//Children_Node~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Tree::GenerateBoards(Node *current) {
    Board subBoard;
    for (int row = 0; row < boardSize; row++) {
        for (int column = 0; column < boardSize; column++) {
            subBoard.squares[row][column] = current->board.squares[row][column];
        }
    }
    for (int row = 0; row < boardSize; row++) {
        for (int column = 0; column < boardSize; column++) {
            if (current->board.squares[row][column] == 1) {
                subBoard.squares[row][column] = 0;
                for (int subColumn = 0; subColumn < boardSize; subColumn++) {
                    if (subColumn != column) {
                        subBoard.squares[row][subColumn] = 1;
                        if (current->children == nullptr) {
                            current->children = new Node(subBoard, current);
                            nodeNum++;
                        }
                        else {
                            Node *node = current->children;
                            while (node->next) {
                                node = node->next;
                            }
                            node->next = new Node(subBoard, current);
                            nodeNum++;
                        }
                        subBoard.squares[row][subColumn] = 0;
                    }
                }
                subBoard.squares[row][column] = 1;
                continue;
            }
        }
    }
}

bool Tree::checkChildren(Node *current) {
    Node *node = current->children;
    do {
        if (node->board.GoodState()) {
            return true;
        }
        node = node->next;
    } while (node);
    return false;
}

//DELETING~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Tree::~Tree() {
    DeleteNode(root);
}

void Tree::DeleteNode(Node *node) {
    if(node->children) {DeleteNode(node->children);}
    if(node->next) {DeleteNode(node->next);}
    delete node;
}

void Tree::upgradeRoot(Node *node) {
    Node *oldRoot = root;
    root = node;
    node->parent = nullptr;
    while (node->next) {
        node = node->next;
        node->parent = nullptr;
    }
    delete oldRoot;
}
