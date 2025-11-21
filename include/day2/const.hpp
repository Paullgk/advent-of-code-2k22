#ifndef CONST_H
#define CONST_H

/**
 * @brief Game error code if something went wrong.
 *
 */
const int GAME_ERROR = -100;

/**
 * @brief The possible values resulted from a fight.
 *
 */
enum GAME_END{
    WIN = 6,
    DRAW = 3,
    LOSE = 0,
};

/**
 * @brief The value of each shape.
 *
 */
enum SHAPE {
    ROCK = 1,
    PAPER = 2,
    SCISSORS = 3,
};

/**
 * @brief The value of a side, RIGHT is '2' to make the compute of
 * ASCII to shape.
 *
 */
enum SIDE {
    LEFT = 0,
    RIGHT = 2,
};

/**
 * @brief Link each player action to it proper shape.
 *
 */
enum ACTION {
    X = LOSE,
    Y = DRAW,
    Z = WIN,
};
#endif
