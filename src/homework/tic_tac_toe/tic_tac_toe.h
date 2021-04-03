#include <string>
#include <vector>

class TicTacToe
{
public:
    bool game_over();
    void mark_board(int position);
    void start_game(std::string first_player);

    void display_board() const;
    std::string get_player() const;

private:
    bool check_board_full();
    void clear_board();
    void set_next_player();

    std::vector<std::string> pegs{9, " "};
    std::string player;
};
