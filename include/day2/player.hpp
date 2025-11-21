#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include <iostream>
#include <day2/const.hpp>
using namespace std;

/**
 * @brief The representation of a player.
 *
 */
class Player {
    private:
        /**
         * @brief Each player is identified by its side (right or left).
         */
        enum SIDE m_playerSide;
        /**
         * @brief The total score accumated by the player.
         *
         */
        int m_score;
    public:
        Player();
        ~Player();
        /**
         * @brief Construct a new Player object, with its side.
         *
         * @param playerSide The player side (right or left).
         */
        Player(SIDE playerSide);
        /**
         * @brief From the current round, extract the appropriate shape
         * played by the player, based on its side. For example, if
         * round is 'A X', and player is on left side, the shape will
         * be 'A'.
         *
         * @param round The current round for the two players (e.g 'A X').
         * @return SHAPE The played shape by the player.
         */
        int extractPlayerRound(string round);
        /**
         * @brief As the extracted shape from the round is an ASCII
         * char, we need to translate it to a game shape.
         *
         * @param asciiShape The extracted played shape for the player
         * from the current round.
         * @return SHAPE The translated shape.
         */
        int translateAsciiToShape(int asciiShape);
        /**
         * @brief Compute the hand score for the player, based on the
         * resulted hand (the substraction between the two shape), and
         * the current played shape. **NOTE:** Only implemented from
         * the human player perspective.
         *
         * @param resultedHand The result of the 'fight' (e.g the
         * substraction between player 2 shape - player 1 shape).
         * @param playedShape The played shape
         * @return int The computed, and accumulated player score.
         */


        /**
         * @brief Compute the hand score for the player, based on the
         * resulted hand (the substraction between the two shape), and
         * the current played shape. **NOTE:** Only implemented from
         * the human player perspective.
         *
         * @param resultedHand The result of the 'fight' (e.g the
         * substraction between player 2 shape - player 1 shape).
         * @param playedShape The played shape by the human player.
         * @param computedScore A pointer to the score to update.
         * @return GAME_END THe state of the game when its done.
         */
        GAME_END computeHandScore(int resultedHand, SHAPE playedShape, int *computedScore);
        /**
         * @brief Update the score of the player.
         *
         * @param score The score value to accumulate.
         */
        void updateScore(int score);
        /**
         * @brief Get the accumulated score value.
         *
         * @return int The accumulated score value.
         */
        int getScore();
};

#endif
