#include "Board.hpp"

Board::Board() {
    squares.resize(boardSize);
    for (auto &cell: squares) {
        cell.resize(boardSize);
    }
}

Board::~Board(){
    for (auto column: squares) {column.clear();}
    squares.clear();
}

//PARSING~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Board::GetFirstState(string file) {
    ifstream fin (file);
    string boardStates;
    getline(fin, boardStates);
    for (auto &cell: squares) {
        int position = stoi(boardStates.substr(0,1));
        cell[position] = 1;
        boardStates.erase(0,1);
    }
}

//STATE_CHECKING~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bool Board::GoodState() {
    for (int row = 0; row < boardSize; row++) {
        for (int column = 0; column < boardSize; column++) {
            if (squares[row][column] == 1) {
                for (int j = row + 1; j < boardSize; j++) {
                    if (squares[j][column] == 1) {
                        return false;}
                    
                    int diagonalLeft = column + row - j;
                    int diagonalRight = column + j - row;
                    
                    if (diagonalLeft >= 0 && squares[j][diagonalLeft] == 1) {
                        return false;}
                    if (diagonalRight < boardSize && squares[j][diagonalRight] == 1) {
                        return false;}
                }
            }
        }
    }
    return true;
};

//OUTPUT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Board::Output() {
    for (int column = 0; column < boardSize; column++) {
        for (int row = 0; row < boardSize; row++) {
            cout << squares[row][column] << " ";
        }
        cout << endl;
    }
    cout << endl;
};
