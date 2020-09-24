#include <iostream>

enum class SquareType {Empty, X, O };

struct Board{
    SquareType squares[3][3];
    int row;
    int col;
};

void CreateBoard (Board &board){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            board.squares[i][j] = SquareType::Empty;
        }
    }
}

std::string SquareTypeStringify(SquareType sq){ /*FULLY IMPLEMENTED AND WORKING*/
    if (sq == SquareType::X )
    {
        return "❌";
    }
    else if (sq == SquareType::O )
    {
        return "⭕️";
    }
    else
    {
        return "⬛️";
    }
}

void DisplayBoard(Board &board){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout<< SquareTypeStringify(board.squares[i][j]);
            if (j<2)
            {
                std::cout<<"  |  ";
            }
        }
        std::cout<<std::endl;
    }
}

int main (){
    Board *board = new Board();
    CreateBoard(*board);
    DisplayBoard(*board);
}