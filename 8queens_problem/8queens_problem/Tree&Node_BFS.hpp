#pragma once
#include "Board.hpp"
struct Node {
    Board board;
    Node *parent;
    Node *next;
    Node *children;
    
    Node(Board board, Node *parent = nullptr, Node *next = nullptr, Node *children = nullptr) {
        this->board = board;
        this->parent = parent;
        this->next = next;
        this->children = children;
    }
};

class Tree {
    Node *root;
    int depth;
    int nodeNum;
    
    void GenerateBoards(Node*);
    bool checkChildren(Node*);
    void upgradeRoot(Node*);
    void DeleteNode(Node*);
public:
    Tree(Board);
    ~Tree();
    
    friend bool BFS(Board);
};
