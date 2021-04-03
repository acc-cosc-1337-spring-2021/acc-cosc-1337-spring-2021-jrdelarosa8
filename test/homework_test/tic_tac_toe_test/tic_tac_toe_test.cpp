#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
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
}
