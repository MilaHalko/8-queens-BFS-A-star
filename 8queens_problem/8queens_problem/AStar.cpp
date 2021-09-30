#include "AStar.hpp"

bool AStar(Board board) {
    Tree tree(board);
    Node *current = tree.root;
    tree.GenerateBoards(current);
    if (tree.checkChildren(current)) {return true;}
    do {
        current = current->children;
        do {
            tree.GenerateBoards(current);
            if(tree.checkChildren(current)) {
                return true;
            }
            if (current->next) {
                current = current->next;
            }
            else {
                break;
            }
        } while (current);
        current = current->parent->children;
        tree.upgradeRoot(current);
    } while (current->children);
    return false;
}
