#include "BFS.hpp"


int main() {
    Board board;
    board.GetFirstState("board.txt");
    board.Output();
    if (!board.GoodState()) {
        BFS(board);
        //AStar(board);
    }
    else {
        cout << "true" << endl;
    }
    return 0;
}
