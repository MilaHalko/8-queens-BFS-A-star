#include "Algorithm.hpp"


int main() {
    Board board;
    board.GetFirstState("board.txt");
    
    if (!board.GoodState()) {
        Algorithm algorithm;
        algorithm.startAlgo(board);
    }
    else {
        cout << "true" << endl;
    }
    return 0;
}
