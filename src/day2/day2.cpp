#include <day2/day2.hpp>

Day2::Day2() {
    m_player1 = Player(LEFT);
    m_player2 = Player(RIGHT);
}

int Day2::simpleComputeGame(string round){
    int player1Input = 0;
    int player2Input = 0;
    int score = 0;

    SHAPE player1Shape;
    SHAPE player2Shape;
    int computedHand = 0;


    player1Input = m_player1.extractPlayerRound(round);
    player2Input = m_player2.extractPlayerRound(round);

    player1Shape = (SHAPE)m_player1.translateAsciiToShape(player1Input);
    player2Shape = (SHAPE)m_player2.translateAsciiToShape(player2Input);


    computedHand = player2Shape - player1Shape;

    if(m_player2.computeHandScore(computedHand, player2Shape, &score) == GAME_ERROR){
        return GAME_ERROR;
    }

    m_player2.updateScore(score);
    return m_player2.getScore();
}

int Day2::complexComputeGame(string round){
    int player1Input = 0;
    int player2Input = 0;

    ACTION player2Action;
    GAME_END end;
    SHAPE player1Shape;

    int computedHand = 0;
    int score = 0;

    player1Input = m_player1.extractPlayerRound(round);
    player2Input = m_player2.extractPlayerRound(round);

    player1Shape = (SHAPE)m_player1.translateAsciiToShape(player1Input);
    player2Action = (ACTION)m_player2.translateAsciiToAction(player2Input);


    /**
     * @brief The neat part: deduct the shape to play based on the
     * action. For that we test each shape combinaison until the result
     * of the fight is the action we want.
     *
     */
    for(int testedShape=ROCK; testedShape<=SCISSORS; testedShape++){
        computedHand = testedShape - player1Shape;
        end = m_player2.computeHandScore(computedHand, (SHAPE)testedShape, &score);
        // TODO: Handle GAME ERROR case

        if(end == GAME_ERROR){
            return GAME_ERROR;
        }

        if((ACTION)end == player2Action){
            break;
        }
        // Reset the score if the action is not the one we want.
        score = 0;
    }
    m_player2.updateScore(score);

    return m_player2.getScore();
}
