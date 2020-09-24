/* CSCI 3010 - IPW
* Felipe Lima and Ziad Alwazzan
* PE 4 - git & version control (part 2)
* 09/24/2020
* Our Program is a fun tic-tac-toe game where there are no winners or losers!
* How to run:
~ g++ -std=c++11 TicTacToe.cpp -o play
~./play
*/
#include <iostream>

enum class SquareType {Empty, X, O };

struct Board{
    SquareType squares[3][3];
    int row;
    int col;
};

std::string SquareTypeStringify(SquareType sq){ // Helper function to DisplayBoard that sets Squaretypes to strings 
    std::string empty = "\U00002B1C";
    std::string x = "\U0000274C"; // or "\xE2\x9D\x8C"
    std::string circle = "\U00002B55";

	switch(sq){
		case SquareType::X: return x; break; //if the SquareType passed into the function is x , return string representsation of x
		case SquareType::Empty: return empty; break;
        case SquareType::O: return circle; break;
	}
}

void DisplayBoard(const Board &b){ // Function used to Display current state if the board
    std::cout << "   1  2  3" << std::endl;
    for (int i = 0; i < 3; i ++){
        std::cout << i+1 << " ";
        for (int j = 0; j < 3; j++){
            std::cout << SquareTypeStringify(b.squares[i][j]) + " "; // Calls Stringify to translate SquareType in current cell to a string
        }
        std::cout << std::endl;
    }
}

void CreateBoard (Board &board){ //Creates an empty board by assigning all cells/squares to the empty squaretype
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            board.squares[i][j] = SquareType::Empty;
        }
    }
}

void GetPlayerChoice(Board &b){ // get the player choice for where to play and stores into Board elements
    b.row = -1;
    b.col = -1;
    std::cout << "Where would you like to play?" << std::endl;
    std::cout << "Row: ";
    std::cin >> b.row; // user input to row to be played
    b.row--; // decreases row to translate to computer language (i.e user input 1 means row 0 for computer)
    while (b.row < 0 || b.row > 2){ // while the user input is not valid
        std::cout << "Not a valid square. Please enter a number from 1 to 3 and somewhere not played yet." << std::endl;
        std::cin >> b.row;
        b.row--;
    }
    std::cout << "Column: ";
    std::cin >> b.col;
    b.col--;
    while (b.col < 0 || b.col > 2){
        std::cout << "Not a valid square. Please enter a number from 1 to 3 and somewhere not played yet." << std::endl;
        std::cin >> b.col;
        b.col--;
    }
}

void PlaceMarker(Board &b, int player_num){ //returns the squaretype X/O based on who is currently playing
    if (player_num == 1)
    {
        b.squares[b.row][b.col] = SquareType::O; // player 1 is O
    }
    else if (player_num == 2)
    {
        b.squares[b.row][b.col] = SquareType::X; // player 2 is X
    }
}

int main (){
    int player_num = 0;
    Board *board = new Board(); // creates a new board
    CreateBoard(*board); // creates board with elements
    for (int i = 0; i < 9; i++){ // for 9 turns for each player
        player_num++;
        if (player_num == 3){ // make sure the playes alternate only between players 1 and 2
            player_num = 1;
        }
        DisplayBoard(*board);
        std::cout << "It's player" << player_num << "'s turn" << std::endl;
        GetPlayerChoice(*board);
        std::cout << std::endl;
        PlaceMarker(*board, player_num);
    }
    DisplayBoard(*board);
    std::cout << "Game over!" << std::endl;
}