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
    std::cout << "   1  2  3" << std::endl;
    for (int i = 0; i < 3; i ++){
        std::cout << i+1 << " ";
        for (int j = 0; j < 3; j++){
            std::cout << SquareTypeStringify(b.squares[i][j]) + " ";
        }
        std::cout << std::endl;
    }
}

void GetPlayerChoice(Board &b){
    bool success = 0;
    b.row = -1;
    b.col = -1;
    std::cout << "Where would you like to play?" << std::endl;
    std::cout << "Row: ";
    std::cin >> b.row;
    b.row--;
    while (b.row < 0 || b.row > 2){
        std::cout << "Not a valid square. Please enter a number from 1 to 3 and somewhere not played yet." << std::endl;
        std::cin >> b.row;
        b.row--;
    }
    std::cout << std::endl;
    std::cout << "Column: ";
    std::cin >> b.col;
    b.col--;
    while (b.col < 0 || b.col > 2){
        std::cout << "Not a valid square. Please enter a number from 1 to 3 and somewhere not played yet." << std::endl;
        std::cin >> b.col;
        b.col--;
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