#include "Algorithm.hpp"

void Algorithm::startAlgo(Board board) {
    cout << "First State:" << endl;
    board.Output();
    
    cout << endl;
    cout << "AStar:" << endl;
    unsigned int start1 = clock();
    AStar(board);
    unsigned int end1 = clock();
    cout << "Time: " << (float)(end1 - start1) / CLOCKS_PER_SEC << endl;
    
    cout << endl;
    cout << "BFS:" << endl;
    unsigned int start2 = clock();
    BFS(board);
    unsigned int end2 = clock();
    cout << "Time: " << (float)(end2-start2) / CLOCKS_PER_SEC << endl;
}

bool Algorithm::BFS(Board board) {
    Node *current = new Node(board);
    statesNumBFS++;
    
    queue<Node*> nodes;
    nodes.push(current);
    
    set<Node*> visited;
    visited.insert(current);
    
    do {
        current = nodes.front();
        nodes.pop();
        iterationBFS++;
        if(current->board.GoodState()) {
            current->board.Output();
            cout << "Iterations: " << iterationBFS << endl;
            cout << "All states' number: " << statesNumBFS << endl;
            cout << "States in queue (finally): " << nodes.size() << endl;
            return true;
        }
        generateChildrenBFS(nodes, current, visited);
        
    } while (!nodes.empty());
    return false;
}

void Algorithm::generateChildrenBFS(queue<Node*> &nodes, Node* node, set<Node*> &visited) {
    Board subBoard;
    for (int row = 0; row < boardSize; row++) {
        for (int column = 0; column < boardSize; column++) {
            subBoard.squares[row][column] = node->board.squares[row][column];
        }
    }
    for (int row = 0; row < boardSize; row++) {
        for (int column = 0; column < boardSize; column++) {
            
            if (node->board.squares[row][column] == 1) {
                subBoard.squares[row][column] = 0;
                
                for (int subColumn = 0; subColumn < boardSize; subColumn++) {
                    if (subColumn != column) {
                        subBoard.squares[row][subColumn] = 1;
                        Node *child = new Node(subBoard);
                        if (visited.find(child) == visited.end()) {
                            statesNumBFS++;
                            nodes.push(child);
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

bool operator<(const pair<int, Board> &board1, const pair<int, Board> &board2) {
    return board1.first < board2.first;
}

bool Algorithm::AStar(Board board) {
    Node *current = new Node(board);
    statesNumAStar++;
    pr_queue nodes;
    int f2 = board.GetF2();
    nodes.push(make_pair(f2, current));
    set<Node*> visited;
    
    do {
        current = nodes.top().second;
        nodes.pop();
        visited.insert(current);
        
        iterationAStar++;
        if(current->board.GoodState()) {
            current->board.Output();
            cout << "Iterations: " << iterationAStar << endl;
            cout << "All states' number: " << statesNumAStar << endl;
            cout << "States in queue (finally): " << nodes.size() << endl;
            return true;
        }
        generateChildrenAStar(nodes, current, visited);
        
    } while (!nodes.empty());
    return false;
}

void Algorithm::generateChildrenAStar(pr_queue &nodes, Node *current, set<Node*> &visited) {
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
                        Node *child = new Node(subBoard);
                        if (visited.find(child) == visited.end()) {
                            statesNumAStar++;
                            int f2 = subBoard.GetF2();
                            nodes.push(make_pair(f2, child));
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
