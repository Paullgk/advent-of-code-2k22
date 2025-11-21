#include <vector>
#include <tools/tools.h>
#include <day2/day2.hpp>
#include <day2/player.hpp>

int main(int argc,char* argv[]){
    Day2 day2;
    Tools tool;
    string input_data;
    int read_status = 0;
    vector<string> rounds;
    int computedScore = 0;
    int totalScore = 0;
    read_status = tool.readInputFile("src/day2/input", &input_data);

    if(read_status == 0){
        tool.extractLines(input_data, &rounds);

        for(auto round:rounds){
            computedScore = day2.simpleComputeGame(round);

            if(computedScore == GAME_ERROR){
                return GAME_ERROR;
            }
        }

        cout << "DAY 2: Answer for first puzzle is " << computedScore << endl;
    }
    return 0;
}
