#include <iostream>

enum class SquareType {Empty, X, O };

struct Board{
    SquareType board[3][3];
    int row;
    int col;
};

void CreateBoard (Board *board){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            board->board[i][j] = SquareType::Empty;
        }
    }
}

int main (){
    Board *board = new Board();
    CreateBoard(board);
}