#pragma once
#include "Board.hpp"
struct Node {
    vector<Board> boards;
    Node *parent;
    Node *child;
    
    Node(Node *parent = nullptr, Node *child = nullptr) {
        boards.resize(0);
        this->parent = parent;
        this->child = child;
    }
    void AddBoard(Board);
};

class Tree {
    Node *root;
    int depth;
    
    void addChild(Node*);
    void GenerateBoards(Node*);
    void renewParent();
    bool checkChild(Node*);
    void DeleteNode(Node*);
public:
    Tree(Board);
    ~Tree();
    
    friend bool BFS(Board);
};
