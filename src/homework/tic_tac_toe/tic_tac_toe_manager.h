#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include "tic_tac_toe.h"
#include <memory>
#include <string>
#include <vector>

using std::unique_ptr; using std::make_unique;

class TicTacToeManager
{

friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);

public:
    void get_winner_total(int &o, int& x, int& t);
    void save_game(unique_ptr<TicTacToe>& game);

private:
    std::vector<unique_ptr<TicTacToe>> games;
    int x_win = 0;
    int o_win = 0;
    int ties = 0;

    void update_winner_count(std::string winner);
};

#endif
