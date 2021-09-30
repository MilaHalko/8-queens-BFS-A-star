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
                for (int i = column + 1; i < boardSize; i++) {
                    if (squares[row][i] == 1) {return false;}
                    
                    int diagonalUp = row + column - i;
                    int diagonalDown = row + i - column;
                    
                    if (diagonalUp >= 0 && squares[diagonalUp][i] == 1) { return false;}
                    if (diagonalDown < boardSize && squares[diagonalDown][i] == 1) {return false;}
                }
            }
        }
    }
    return true;
};

//OUTPUT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Board::Output() {
    for (auto row: squares) {
        for (auto cell: row) {
            cout << cell << " ";
        }
        cout << endl;
    }
};
