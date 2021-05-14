#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

#include <memory>

using std::endl;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test first player set to X")
{
    TicTacToe3 game;
    game.start_game("X");

    REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player set to O")
{
    TicTacToe3 game;
    game.start_game("O");

    REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test game over if 9 slots are selected")
{
    TicTacToe3 game;
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
    TicTacToe3 game;
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
    TicTacToe3 game;
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
    TicTacToe3 game;
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
    TicTacToe3 game;
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
    TicTacToe3 game;
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
    TicTacToe3 game;
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
    TicTacToe3 game;
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
    TicTacToe3 game;
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
    unique_ptr<TicTacToe> game1 = make_unique<TicTacToe3>();
    unique_ptr<TicTacToe> game2 = make_unique<TicTacToe3>();
    unique_ptr<TicTacToe> game3 = make_unique<TicTacToe3>();
    int o = 0, x = 0, t = 0;

    game1->start_game("X");

    game1->mark_board(1);
    game1->mark_board(2);
    game1->mark_board(3);
    game1->mark_board(4);
    game1->mark_board(5);
    game1->mark_board(7);
    game1->mark_board(6);
    game1->mark_board(9);
    game1->mark_board(8);

    if (game1->game_over())
    {
        manager.save_game(game1);
    }

    game2->start_game("X");

    game2->mark_board(1);
    game2->mark_board(2);
    game2->mark_board(4);
    game2->mark_board(3);
    game2->mark_board(7);

    if (game2->game_over()) {
        manager.save_game(game2);
    }

    game3->start_game("O");

    game3->mark_board(1);
    game3->mark_board(2);
    game3->mark_board(4);
    game3->mark_board(3);
    game3->mark_board(7);

    if (game3->game_over())
    {
        manager.save_game(game3);
    }

    manager.get_winner_total(o, x, t);

    REQUIRE(o == 1);
    REQUIRE(x == 1);
    REQUIRE(t == 1);

}

TEST_CASE("Test first player set to X - 4")
{
    TicTacToe4 game;
    game.start_game("X");

    REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player set to O - 4")
{
    TicTacToe4 game;
    game.start_game("O");

    REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test game over if 16 slots are selected - 4")
{
    TicTacToe4 game;
    std::vector<int> positions{1, 4, 5, 8, 9, 12, 16, 13, 2, 3, 7, 6, 10, 11, 15, 14};

    game.start_game("X");

    for(auto i: positions)
    {
        game.mark_board(i);

        if (i == 14)
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

TEST_CASE("Test win by first column - 4")
{
    TicTacToe4 game;
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
    REQUIRE(game.game_over() == false);

    game.mark_board(7);
    REQUIRE(game.game_over() == false);

    game.mark_board(13);
    REQUIRE(game.game_over() == true);

    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by second column - 4")
{
    TicTacToe4 game;
    game.start_game("X");

    game.mark_board(2);
    REQUIRE(game.game_over() == false);

    game.mark_board(1);
    REQUIRE(game.game_over() == false);

    game.mark_board(6);
    REQUIRE(game.game_over() == false);

    game.mark_board(3);
    REQUIRE(game.game_over() == false);

    game.mark_board(10);
    REQUIRE(game.game_over() == false);

    game.mark_board(3);
    REQUIRE(game.game_over() == false);

    game.mark_board(14);
    REQUIRE(game.game_over() == true);

    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by third column - 4")
{
    TicTacToe4 game;
    game.start_game("X");

    game.mark_board(3);
    REQUIRE(game.game_over() == false);

    game.mark_board(1);
    REQUIRE(game.game_over() == false);

    game.mark_board(7);
    REQUIRE(game.game_over() == false);

    game.mark_board(4);
    REQUIRE(game.game_over() == false);

    game.mark_board(11);
    REQUIRE(game.game_over() == false);

    game.mark_board(12);
    REQUIRE(game.game_over() == false);

    game.mark_board(15);
    REQUIRE(game.game_over() == true);

    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by fourth column - 4")
{
    TicTacToe4 game;
    game.start_game("X");

    game.mark_board(4);
    REQUIRE(game.game_over() == false);

    game.mark_board(1);
    REQUIRE(game.game_over() == false);

    game.mark_board(8);
    REQUIRE(game.game_over() == false);

    game.mark_board(10);
    REQUIRE(game.game_over() == false);

    game.mark_board(12);
    REQUIRE(game.game_over() == false);

    game.mark_board(2);
    REQUIRE(game.game_over() == false);

    game.mark_board(16);
    REQUIRE(game.game_over() == true);

    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by first row - 4")
{
    TicTacToe4 game;
    game.start_game("X");

    game.mark_board(1);
    REQUIRE(game.game_over() == false);

    game.mark_board(5);
    REQUIRE(game.game_over() == false);

    game.mark_board(2);
    REQUIRE(game.game_over() == false);

    game.mark_board(6);
    REQUIRE(game.game_over() == false);

    game.mark_board(3);
    REQUIRE(game.game_over() == false);

    game.mark_board(7);
    REQUIRE(game.game_over() == false);

    game.mark_board(4);
    REQUIRE(game.game_over() == true);

    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by second row - 4")
{
    TicTacToe4 game;
    game.start_game("X");

    game.mark_board(5);
    REQUIRE(game.game_over() == false);

    game.mark_board(1);
    REQUIRE(game.game_over() == false);

    game.mark_board(6);
    REQUIRE(game.game_over() == false);

    game.mark_board(2);
    REQUIRE(game.game_over() == false);

    game.mark_board(7);
    REQUIRE(game.game_over() == false);

    game.mark_board(3);
    REQUIRE(game.game_over() == false);

    game.mark_board(8);
    REQUIRE(game.game_over() == true);

    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by third row - 4")
{
    TicTacToe4 game;
    game.start_game("X");

    game.mark_board(9);
    REQUIRE(game.game_over() == false);

    game.mark_board(1);
    REQUIRE(game.game_over() == false);

    game.mark_board(10);
    REQUIRE(game.game_over() == false);

    game.mark_board(2);
    REQUIRE(game.game_over() == false);

    game.mark_board(11);
    REQUIRE(game.game_over() == false);

    game.mark_board(3);
    REQUIRE(game.game_over() == false);

    game.mark_board(12);
    REQUIRE(game.game_over() == true);

    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win by fourth row - 4")
{
    TicTacToe4 game;
    game.start_game("X");

    game.mark_board(13);
    REQUIRE(game.game_over() == false);

    game.mark_board(1);
    REQUIRE(game.game_over() == false);

    game.mark_board(14);
    REQUIRE(game.game_over() == false);

    game.mark_board(2);
    REQUIRE(game.game_over() == false);

    game.mark_board(15);
    REQUIRE(game.game_over() == false);

    game.mark_board(3);
    REQUIRE(game.game_over() == false);

    game.mark_board(16);
    REQUIRE(game.game_over() == true);

    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win diagonally from top left - 4")
{
    TicTacToe4 game;
    game.start_game("X");

    game.mark_board(1);
    REQUIRE(game.game_over() == false);

    game.mark_board(2);
    REQUIRE(game.game_over() == false);

    game.mark_board(6);
    REQUIRE(game.game_over() == false);

    game.mark_board(3);
    REQUIRE(game.game_over() == false);

    game.mark_board(11);
    REQUIRE(game.game_over() == false);

    game.mark_board(4);
    REQUIRE(game.game_over() == false);

    game.mark_board(16);
    REQUIRE(game.game_over() == true);

    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left - 4")
{
    TicTacToe4 game;
    game.start_game("X");

    game.mark_board(13);
    REQUIRE(game.game_over() == false);

    game.mark_board(2);
    REQUIRE(game.game_over() == false);

    game.mark_board(10);
    REQUIRE(game.game_over() == false);

    game.mark_board(3);
    REQUIRE(game.game_over() == false);

    game.mark_board(7);
    REQUIRE(game.game_over() == false);

    game.mark_board(6);
    REQUIRE(game.game_over() == false);

    game.mark_board(4);
    REQUIRE(game.game_over() == true);

    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test TicTacToeManager::get_winner_total function - 4")
{
    TicTacToeManager manager;
    int o = 0, x = 0, t = 0;

    unique_ptr<TicTacToe> game1 = make_unique<TicTacToe4>();
    unique_ptr<TicTacToe> game2 = make_unique<TicTacToe4>();
    unique_ptr<TicTacToe> game3 = make_unique<TicTacToe4>();

    std::vector<int> positions1{13, 1, 14, 2, 15, 3, 16};
    std::vector<int> positions2{1, 4, 5, 8, 9, 12, 16, 13, 2, 3, 7, 6, 10, 11, 15, 14};

    game1->start_game("X");
    for (auto pos: positions1)
    {
        game1->mark_board(pos);
    }

    if (game1->game_over())
    {
        manager.save_game(game1);
    }


    game2->start_game("X");
    for (auto pos: positions2)
    {
        game2->mark_board(pos);
    }

    if (game2->game_over()) {
        manager.save_game(game2);
    }

    game3->start_game("O");
    for (auto pos: positions1)
    {
        game3->mark_board(pos);
    }

    if (game3->game_over())
    {
        manager.save_game(game3);
    }

    manager.get_winner_total(o, x, t);

    REQUIRE(o == 1);
    REQUIRE(x == 1);
    REQUIRE(t == 1);
}
