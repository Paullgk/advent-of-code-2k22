#include <day2/player.hpp>

Player::Player(){

}

Player::Player(SIDE playerSide){
    m_score = 0;
    m_playerSide = playerSide;
}

Player::~Player(){

}

int Player::extractPlayerRound(string round){
    char playerInput = round[m_playerSide];
    return playerInput;
}

int Player::translateAsciiToShape(int asciiShape){
    int magicNumber = 0;
    int playedShape;

    switch (asciiShape){
        case 65:
            // 'A' ASCII char
            playedShape = ROCK;
            break;
        case 66:
            // 'B' ASCII char
            playedShape = PAPER;
            break;
        case 67:
            // 'B' ASCII char
            playedShape = SCISSORS;
            break;
        case 88:
        // 'X' ASCII char
            playedShape = ROCK;
            break;
        case 89:
        // 'Y' ASCII char
            playedShape = PAPER;
            break;
        case 90:
        // 'Z' ASCII char
            playedShape = SCISSORS;
            break;
        default:
            cout << "ERROR: Unauthorized ASCII character provided: " << (char)asciiShape << endl;
            break;
    }

    return playedShape;
}

int Player::translateAsciiToAction(int asciiShape){
    int magicNumber = 0;
    int actionToPlay;

    switch (asciiShape)
    {
    case 88:
    // 'X' ASCII char
        actionToPlay = X;
        break;
    case 89:
    // 'Y' ASCII char
        actionToPlay = Y;
        break;
    case 90:
    // 'Z' ASCII char
        actionToPlay = Z;
        break;
    default:
        cout << "ERROR: Unauthorized ASCII character provided: " << (char)asciiShape << endl;
        actionToPlay = GAME_ERROR;
        break;
    }
    return actionToPlay;
}



void Player::updateScore(int score){
    m_score += score;
}

GAME_END Player::computeHandScore(int resultedHand, SHAPE playedShape, int *computedHandScore){
    *computedHandScore = 0;
    GAME_END end;
    // Each combinaison is deterministic from the player 1 POV.
    switch (resultedHand)
    {
    case -2:
        /* LOSE */
        *computedHandScore = playedShape + WIN;
        end = WIN;
        break;
    case -1:
        /* LOSE */
        *computedHandScore = playedShape + LOSE;
        end = LOSE;
        break;
    case 0:
        /* DRAW */
        *computedHandScore = playedShape + DRAW;
        end = DRAW;
        break;
    case 1:
        /* WIN */
        *computedHandScore = playedShape + WIN;
        end = WIN;
        break;
    case 2:
        /* LOSE */
        *computedHandScore = playedShape + LOSE;
        end = LOSE;
        break;
    default:
        /* Impossible condition, fatal error*/
        cout << "ERROR: Impossible hand computed: " << resultedHand << endl;
        *computedHandScore = GAME_ERROR;
        break;
    }

    return end;
}

int Player::getScore(){
    return m_score;
}
