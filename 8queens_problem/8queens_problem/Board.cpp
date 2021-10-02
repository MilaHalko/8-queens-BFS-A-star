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
                    
                    int diagonalUp = column + row - j;
                    int diagonalDown = column + j - row;
                    
                    if (diagonalUp >= 0 && squares[j][diagonalUp] == 1) {return false;}
                    if (diagonalDown < boardSize && squares[j][diagonalDown] == 1) {return false;}
                }
            }
        }
    }
    return true;
};

//H2~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int Board::GetF2() {
    int conflicts = 0;
    for (int row = 0; row < boardSize; row++) {
        for (int column = 0; column < boardSize; column++) {
            
            if (squares[row][column] == 1) {
                bool UpConflict = false;
                bool DownConflict = false;
                for (int j = row + 1; j < boardSize; j++) {
                    int diagonalUp = column + row - j;
                    int diagonalDown = column + j - row;
                    
                    if (diagonalUp >= 0 && !UpConflict && squares[j][diagonalUp] == 1) {
                        conflicts++;
                        UpConflict = true;
                    }
                    if (diagonalDown < boardSize && !DownConflict && squares[j][diagonalDown] == 1) {
                        conflicts++;
                        DownConflict = true;
                    }
                    if (UpConflict && DownConflict) {
                        break;
                    }
                }
            }
        }
    }
    return conflicts;
}

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
