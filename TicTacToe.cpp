#include <iostream>

enum class SquareType {Empty, X, O };

struct Board{
    SquareType squares[3][3];
    int row;
    int col;
};

std::string SquareTypeStringify(SquareType sq){
    std::string empty = "\U00002B1C";
    std::string x = "\U0000274C"; // or "\xE2\x9D\x8C"
    std::string circle = "\U00002B55";

	switch(sq){
		case SquareType::X: return x; break; //if the SquareType passed into the function is x , return string representsation of x
		case SquareType::Empty: return empty; break;
        case SquareType::O: return circle; break;
	}
}

void DisplayBoard(const Board &b){
    for (int i = 0; i < 3; i ++){
        for (int j = 0; j < 3; j++){
            std::cout << SquareTypeStringify(b.squares[i][j]) + " ";
        }
        std::cout << std::endl;
    }
}

void CreateBoard (Board &board){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            board.squares[i][j] = SquareType::Empty;
        }
    }
}

int main (){
    Board *board = new Board();
    CreateBoard(*board);
    DisplayBoard(*board);
}