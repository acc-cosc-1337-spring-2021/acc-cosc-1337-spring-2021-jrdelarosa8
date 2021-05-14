#include "tic_tac_toe.h"
#include <iostream>

bool TicTacToe::game_over()
{
    if (this->check_column_win() || this->check_row_win() || this->check_diagonal_win())
    {
        this->set_winner();
        return true;
    }
    else if (this->check_board_full())
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

    for (auto i: this->pegs)
    {
        if (i != " ")
        {
            count += 1;
        }
    }

    if (this->pegs.size() == count)
    {
        return true;
    }
    else
    {
        return false;
    }
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
    return false;
}

bool TicTacToe::check_row_win() const
{
    return false;
}

bool TicTacToe::check_diagonal_win() const
{
    return false;
}

std::ostream& operator<<(std::ostream& out, const TicTacToe& game)
{
    if (game.pegs.size() == 9)
    {
        for (std::size_t i = 1; i <= game.pegs.size(); i++)
        {
            if(i % 3 == 0)
            {
                out << game.pegs[i - 1];
                out << std::endl;
            }
            else
            {
                out << game.pegs[i - 1];
            }
        }
    }
    else if (game.pegs.size() == 16)
    {
        for (std::size_t i = 1; i <= game.pegs.size(); i++)
        {
            if(i % 4 == 0)
            {
                out << game.pegs[i - 1];
                out << std::endl;
            }
            else
            {
                out << game.pegs[i - 1];
            }
        }
    }

    out << std::endl;

    return out;
}

std::istream& operator>>(std::istream& in, TicTacToe& game)
{
    std::string choice;
    int position = 0;

    do {
        std::cout << "Enter X or O to select the first player: ";
        in >> choice;

        if (choice == "x")
        {
            choice = "X";
        }
        else if (choice == "o")
        {
            choice = "O";
        }
    } while (!(choice == "X" || choice == "O"));

    game.start_game(choice);

    if (game.pegs.size() == 9)
    {
        do {
            std::cout << "Your turn player " << game.get_player() << ". Enter a position on the board between 1 and 9: ";
            in >> position;

            while (position > 9 || position < 1)
            {
                std::cout << "Invalid selection, please enter a position between 1 and 9: ";
                in >> position;
            }

            game.mark_board(position);
            std::cout << game;

        } while (!(game.game_over()));
    }
    else
    {
        do {
            std::cout << "Your turn player " << game.get_player() << ". Enter a position on the board between 1 and 16: ";
            in >> position;

            while (position > 16 || position < 1)
            {
                std::cout << "Invalid selection, please enter a position between 1 and 16: ";
                in >> position;
            }

            game.mark_board(position);
            std::cout << game;

        } while (!(game.game_over()));
    }

    return in;
}
