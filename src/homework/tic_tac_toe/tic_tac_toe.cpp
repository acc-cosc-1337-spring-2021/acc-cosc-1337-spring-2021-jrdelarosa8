#include "tic_tac_toe.h"
#include <iostream>

bool TicTacToe::game_over()
{
    return check_board_full();
}

void TicTacToe::start_game(std::string first_player)
{
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();
}

std::string TicTacToe::get_player() const
{
    return player;
}

void TicTacToe::display_board() const
{
    for (std::size_t i = 1; i <= pegs.size(); i++)
    {
        if(i % 3 == 0)
        {
            std::cout << pegs[i - 1];
            std::cout << std::endl;
        }
        else
        {
            std::cout << pegs[i - 1];
        }
    }

    std::cout << std::endl;
}

void TicTacToe::set_next_player()
{
    if(player == "X")
    {
        player = "O";
    }
    else
    {
        player = "X";
    }
}

bool TicTacToe::check_board_full()
{
    int count = 0;

    for (auto i: pegs)
    {
        if(i != " ")
        {
            count += 1;
        }
    }

    if(count == 9)
    {
        return true;
    }

    return false;
}

void TicTacToe::clear_board()
{
    for(std::size_t i = 0; i < pegs.size(); i++)
    {
        pegs[i] = " ";
    }
}
