#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test first player set to X")
{
    TicTacToe game;
    game.start_game("X");

    REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player set to O")
{
    TicTacToe game;
    game.start_game("O");

    REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test game over if 9 slots are selected")
{
    TicTacToe game;
    std::vector<int> positions{1, 2, 3, 4, 5, 7, 6, 9, 8};

    game.start_game("X");

    for(auto i: positions)
    {
        game.mark_board(i);

        if (i == 8)
        {
            REQUIRE(game.game_over() == true);
        }
        else
        {
            REQUIRE(game.game_over() == false);
        }
    }

    REQUIRE(game.get_winner() == "C");
}

TEST_CASE("Test win by first column")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1);
    REQUIRE(game.game_over() == false);

    game.mark_board(2);
    REQUIRE(game.game_over() == false);

    game.mark_board(4);
    REQUIRE(game.game_over() == false);

    game.mark_board(3);
    REQUIRE(game.game_over() == false);

    game.mark_board(7);
    REQUIRE(game.game_over() == true);

    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by second column")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(2);
    REQUIRE(game.game_over() == false);

    game.mark_board(1);
    REQUIRE(game.game_over() == false);

    game.mark_board(5);
    REQUIRE(game.game_over() == false);

    game.mark_board(3);
    REQUIRE(game.game_over() == false);

    game.mark_board(8);
    REQUIRE(game.game_over() == true);

    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by third column")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(3);
    REQUIRE(game.game_over() == false);

    game.mark_board(1);
    REQUIRE(game.game_over() == false);

    game.mark_board(6);
    REQUIRE(game.game_over() == false);

    game.mark_board(4);
    REQUIRE(game.game_over() == false);

    game.mark_board(9);
    REQUIRE(game.game_over() == true);

    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by first row")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1);
    REQUIRE(game.game_over() == false);

    game.mark_board(4);
    REQUIRE(game.game_over() == false);

    game.mark_board(2);
    REQUIRE(game.game_over() == false);

    game.mark_board(5);
    REQUIRE(game.game_over() == false);

    game.mark_board(3);
    REQUIRE(game.game_over() == true);

    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by second row")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(4);
    REQUIRE(game.game_over() == false);

    game.mark_board(1);
    REQUIRE(game.game_over() == false);

    game.mark_board(5);
    REQUIRE(game.game_over() == false);

    game.mark_board(2);
    REQUIRE(game.game_over() == false);

    game.mark_board(6);
    REQUIRE(game.game_over() == true);

    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by third row")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(7);
    REQUIRE(game.game_over() == false);

    game.mark_board(1);
    REQUIRE(game.game_over() == false);

    game.mark_board(8);
    REQUIRE(game.game_over() == false);

    game.mark_board(2);
    REQUIRE(game.game_over() == false);

    game.mark_board(9);
    REQUIRE(game.game_over() == true);

    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win diagonally from top left")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(1);
    REQUIRE(game.game_over() == false);

    game.mark_board(2);
    REQUIRE(game.game_over() == false);

    game.mark_board(5);
    REQUIRE(game.game_over() == false);

    game.mark_board(3);
    REQUIRE(game.game_over() == false);

    game.mark_board(9);
    REQUIRE(game.game_over() == true);

    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left")
{
    TicTacToe game;
    game.start_game("X");

    game.mark_board(7);
    REQUIRE(game.game_over() == false);

    game.mark_board(1);
    REQUIRE(game.game_over() == false);

    game.mark_board(5);
    REQUIRE(game.game_over() == false);

    game.mark_board(2);
    REQUIRE(game.game_over() == false);

    game.mark_board(3);
    REQUIRE(game.game_over() == true);

    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test TicTacToeManager::get_winner_total function")
{
    TicTacToeManager manager;
    TicTacToe game1, game2, game3;
    int o = 0, x = 0, t = 0;

    game1.start_game("X");

    game1.mark_board(1);
    game1.mark_board(2);
    game1.mark_board(3);
    game1.mark_board(4);
    game1.mark_board(5);
    game1.mark_board(7);
    game1.mark_board(6);
    game1.mark_board(9);
    game1.mark_board(8);

    if (game1.game_over())
    {
        manager.save_game(game1);
    }

    game2.start_game("X");

    game2.mark_board(1);
    game2.mark_board(2);
    game2.mark_board(4);
    game2.mark_board(3);
    game2.mark_board(7);

    if (game2.game_over()) {
        manager.save_game(game2);
    }

    game3.start_game("O");

    game3.mark_board(1);
    game3.mark_board(2);
    game3.mark_board(4);
    game3.mark_board(3);
    game3.mark_board(7);

    if (game3.game_over())
    {
        manager.save_game(game3);
    }

    manager.get_winner_total(o, x, t);

    REQUIRE(o == 1);
    REQUIRE(x == 1);
    REQUIRE(t == 1);

}