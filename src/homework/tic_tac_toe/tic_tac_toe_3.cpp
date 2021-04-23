#include "tic_tac_toe_3.h"

bool TicTacToe3::check_column_win() const
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

bool TicTacToe3::check_diagonal_win() const
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

bool TicTacToe3::check_row_win() const
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
