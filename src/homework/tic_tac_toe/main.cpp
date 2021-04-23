#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"
#include <iostream>

using std::cout; using std::cin; using std::endl;

int main() 
{
    std::string choice;
    std::string play_again;
    int game_type = 0, o = 0, x = 0, t = 0;

    TicTacToeManager manager;
    unique_ptr<TicTacToe> game;

    do {

        while (game_type < 3 || game_type > 4)
        {
            cout << "What size grid would you like to play on?" << endl;
            cout << "Enter '3' for 3 x 3, enter '4' for 4 x 4: ";
            cin >> game_type;
        }

        if (game_type == 3)
        {
            game = make_unique<TicTacToe3>();
        }
        else
        {
            game = make_unique<TicTacToe4>();
        }

        cin >> *game;

        cout << "Game over!" << std::endl;

        if (game->get_winner() == "X" || game->get_winner() == "O")
        {
            cout << "Winner is player " << game->get_winner() << endl;
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
