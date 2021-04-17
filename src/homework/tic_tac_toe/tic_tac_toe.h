#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <string>
#include <vector>

class TicTacToe
{

friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
friend std::istream& operator>>(std::istream& in, TicTacToe& game);

public:
    bool game_over();
    void mark_board(int position);
    void start_game(std::string first_player);

    std::string get_player() const;
    std::string get_winner() const;

private:
    bool check_board_full();
    void clear_board();
    void set_next_player();
    void set_winner();

    bool check_column_win() const;
    bool check_row_win() const;
    bool check_diagonal_win() const;

    std::vector<std::string> pegs{9, " "};
    std::string player;
    std::string winner;
};

#endif
