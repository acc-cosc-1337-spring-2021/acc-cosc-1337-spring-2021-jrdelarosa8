#include "tic_tac_toe.h"
#include <iostream>

bool TicTacToe::game_over()
{
    if (check_column_win() || check_row_win() || check_diagonal_win())
    {
        set_winner();
        return true;
    }
    else if (check_board_full())
    {
        winner = "C";
        return true;
    }
    else
    {
        return false;
    }
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();
}

void TicTacToe::start_game(std::string first_player)
{
    player = first_player;
    clear_board();
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

std::string TicTacToe::get_player() const
{
    return player;
}

std::string TicTacToe::get_winner() const
{
    return winner;
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

void TicTacToe::set_winner()
{
    if(player == "X")
    {
        winner = "O";
    }
    else
    {
        winner = "X";
    }
}

bool TicTacToe::check_column_win() const
{
    if ((pegs[0] == "X") && (pegs[3] == "X") && (pegs[6] == "X"))
    {
        return true;
    }
    else if ((pegs[1] == "X") && (pegs[4] == "X") && (pegs[7] == "X"))
    {
        return true;
    }
    else if ((pegs[2] == "X") && (pegs[5] == "X") && (pegs[8] == "X"))
    {
        return true;
    }
    else if ((pegs[0] == "O") && (pegs[3] == "O") && (pegs[6] == "O"))
    {
        return true;
    }
    else if ((pegs[1] == "O") && (pegs[4] == "O") && (pegs[7] == "O"))
    {
        return true;
    }
    else if ((pegs[2] == "O") && (pegs[5] == "O") && (pegs[8] == "O"))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TicTacToe::check_row_win() const
{
    if ((pegs[0] == "X") && (pegs[1] == "X") && (pegs[2] == "X"))
    {
        return true;
    }
    else if ((pegs[3] == "X") && (pegs[4] == "X") && (pegs[5] == "X"))
    {
        return true;
    }
    else if ((pegs[6] == "X") && (pegs[7] == "X") && (pegs[8] == "X"))
    {
        return true;
    }
    else if ((pegs[0] == "O") && (pegs[1] == "O") && (pegs[2] == "O"))
    {
        return true;
    }
    else if ((pegs[3] == "O") && (pegs[4] == "O") && (pegs[5] == "O"))
    {
        return true;
    }
    else if ((pegs[6] == "0") && (pegs[7] == "0") && (pegs[8] == "0"))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TicTacToe::check_diagonal_win() const
{
    if ((pegs[0] == "X") && (pegs[4] == "X") && (pegs[8] == "X"))
    {
        return true;
    }
    else if ((pegs[6] == "X") && (pegs[4] == "X") && (pegs[2] == "X"))
    {
        return true;
    }
    else if ((pegs[0] == "O") && (pegs[4] == "O") && (pegs[8] == "O"))
    {
        return true;
    }
    else if ((pegs[6] == "O") && (pegs[4] == "O") && (pegs[2] == "O"))
    {
        return true;
    }
    else
    {
        return false;
    }
}
