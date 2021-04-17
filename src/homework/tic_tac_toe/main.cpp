#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() 
{
    std::string choice;
    std::string play_again;
    int position, o = 0, x = 0, t = 0;

    TicTacToeManager manager;
    TicTacToe game;

    do {

        cin >> game;

        cout << "Game over!" << std::endl;

        if (game.get_winner() == "X" || game.get_winner() == "O")
        {
            cout << "Winner is player " << game.get_winner() << endl;
        }
        else
        {
            cout << "Game is a tie" << endl;
        }

        manager.save_game(game);
        manager.get_winner_total(o, x, t);
        cout << "O wins: " << o << "\tX wins: " << x << "\tTies: " << t << endl;


        cout << "Enter 'Y' or 'y' to play again: ";
        cin >> play_again;

    } while(play_again == "Y" || play_again == "y");

    cout << endl << "Games Played" << endl;
    cout << "------------" << endl;
    cout << manager;

	return 0;
}
