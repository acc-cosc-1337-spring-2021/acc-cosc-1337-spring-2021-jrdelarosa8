#include "tic_tac_toe_data.h"
#include <fstream>
#include <memory>

void TicTacToeData::save_games(const std::vector<std::unique_ptr<TicTacToe>> &games)
{
    std::ofstream out_file;
    out_file.open(file_name);

    if (out_file.is_open())
    {
        for (auto &game: games)
        {
            for (auto peg: game->get_pegs())
            {
                out_file << peg;
            }
            out_file << game->get_winner() << "\n";
        }
    }
    out_file.close();
}

std::vector<std::unique_ptr<TicTacToe>> TicTacToeData::get_games()
{
    std::vector<std::unique_ptr<TicTacToe>> games;
    std::string line;

    std::ifstream in_file;
    in_file.open(file_name);

    if (in_file.is_open())
    {
        while (std::getline(in_file, line))
        {
            std::vector<std::string> pegs;

            for (std::size_t i = 0; i < (line.size() - 1); ++i)
            {
                std::string ch(1, line[i]);
                pegs.push_back(ch);
            }

            std::string winner{line[line.size() - 1]};
            std::unique_ptr<TicTacToe> game;

            if (pegs.size() == 9)
            {
                game = std::make_unique<TicTacToe3>(pegs, winner);
            }
            else if (pegs.size() == 16)
            {
                game = std::make_unique<TicTacToe4>(pegs, winner);
            }
            games.push_back(std::move(game));
        }
        in_file.close();
    }

    return games;
}
