#ifndef TIC_TAC_TOE_3_H
#define TIC_TAC_TOE_3_H

#include "tic_tac_toe.h"

class TicTacToe3: public TicTacToe
{
public:
    TicTacToe3(const std::vector<std::string>& p, const std::string& w): TicTacToe(p, w){};
    TicTacToe3() : TicTacToe(3){};

private:
    bool check_column_win() const override;
    bool check_diagonal_win() const override;
    bool check_row_win() const override;
};

#endif
