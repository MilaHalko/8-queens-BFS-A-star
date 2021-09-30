#include "Tree&Node.hpp"

void Node::AddBoard(Board board) {
    boards.push_back(board);
}

Tree::Tree(Board board) {
    root = new Node();
    root->boards.push_back(board);
    depth = 1;
}

//Children_Node~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void Tree::addChild(Node *current) {
    current->child = new Node();
    current->child->parent = current;
    GenerateBoards(current->child);
}

void Tree::GenerateBoards(Node *current) {
    for ( auto board: current->boards) {
        Board subBoard;
        for (int row = 0; row < boardSize; row++) {
            for (int column = 0; column < boardSize; column++) {
                subBoard.squares[row][column] = board.squares[row][column];
            }
        }
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                if (board.squares[i][j] == 1) {
                    subBoard.squares[i][j] = 0;
                    for (int row = 0; row < boardSize; row++) {
                        if (row != i) {
                            subBoard.squares[row][j] = 1;
                            current->child->boards.push_back(subBoard);
                            subBoard.squares[row][j] = 0;
                        }
                    }
                    break;
                }
            }
        }
    }
}

bool Tree::checkChild(Node *current) {
    for (auto board: current->boards) {
        board.Output();
        if (board.GoodState()) {
            board.Output();
            return true;
        }
    }
    return false;
}

//DELETING~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Tree::renewParent() {
    Node* oldRoot = root;
    root = root->child;
    delete oldRoot;
}

Tree::~Tree() {
    DeleteNode(root);
}

void Tree::DeleteNode(Node *node) {
    if(node->child) {DeleteNode(node->child);}
    node->boards.clear();
    delete node;
}
