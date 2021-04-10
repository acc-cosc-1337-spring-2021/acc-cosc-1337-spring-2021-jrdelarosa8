#include "tic_tac_toe.h"
#include <iostream>

using std::cout; using std::cin;

int main() 
{
    std::string choice;
    std::string play_again;
    int position;

    TicTacToe game;

    do {

        do {
            cout << "Enter X or O to select the first player: ";
            cin >> choice;

            if (choice == "x") {
                choice = "X";
            } else if (choice == "o") {
                choice = "O";
            }
        } while (!(choice == "X" || choice == "O"));

        game.start_game(choice);

        do {
            cout << "Your turn player " << game.get_player() << ". Enter a position on the board between 1 and 9: ";
            cin >> position;

            while (position > 10 || position < 0)
            {
                cout << "Invalid selection, please enter a position between 1 and 9: ";
                cin >> position;
            }

            game.mark_board(position);
            game.display_board();

        } while (!(game.game_over()));

        cout << "Game over!" << std::endl;
        cout << "Winner is player " << game.get_winner() << std::endl;

        cout << "Enter 'Y' or 'y' to play again: ";
        cin >> play_again;

    } while(play_again == "Y" || play_again == "y");

	return 0;
}
