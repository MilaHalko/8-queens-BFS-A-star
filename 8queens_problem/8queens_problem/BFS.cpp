#include "BFS.hpp"

bool BFS(Board board) {
    Tree tree(board);
    Node *current = tree.root;
    do {
        tree.addChild(current);
        if (tree.checkChild(current->child)) {
            return true;
        }
        current = current->child;
    } while (current);
    return false;
}
