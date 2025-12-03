#ifndef DAY2_H
#define DAY2_H

#include <vector>
#include <string>
#include <iostream>
#include <day2/player.hpp>
#include <day2/const.hpp>

using namespace std;

/**
 * @brief The day 2 puzzles.
 *
 */
class Day2 {
    private:
        /**
         * @brief The players. Player 1 represents the Elf player
         * (you), player 2 represents the Human player.
         */
        Player m_player1;
        Player m_player2;

    public:
        Day2();
        /**
         * @brief Simple game computation method (part 1). From the
         * current round, calculate the score for the player 2
         * **only**. Why?
         * - We don't need for the puzzle resolution the Elf score.
         * - If we know if player 2 win/lose win can deduct it for the
         *   other player.
         *
         * @param round The current played round containing the two
         * played shape (e.g A X).
         * @return int The player 2 total score
         */
        int simpleComputeGame(string round);
        /**
         * @brief Complex game computation (part 2).
         *
         * @param round The current played round containing the player
         * 1 shape and the player 2 action.
         * played shape (e.g A X).
         * @return int The player 2 total score.
         */
        int complexComputeGame(string round);

};

#endif
