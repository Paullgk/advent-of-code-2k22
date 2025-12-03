#include <vector>
#include <tools/tools.h>
#include <day2/day2.hpp>
#include <day2/player.hpp>

int main(int argc,char* argv[]){
    Day2 day2PartOne;
    Day2 day2PartTwo;

    Tools tool;
    string input_data;
    int read_status = 0;
    vector<string> rounds;
    int partOnecomputedScore = 0;
    int partTwocomputedScore = 0;

    int totalScore = 0;
    read_status = tool.readInputFile("src/day2/input", &input_data);

    if(read_status == 0){
        tool.extractLines(input_data, &rounds);

        for(auto round:rounds){
            partOnecomputedScore = day2PartOne.simpleComputeGame(round);
            partTwocomputedScore = day2PartTwo.complexComputeGame(round);

            if((partOnecomputedScore || partTwocomputedScore) == GAME_ERROR){
                return GAME_ERROR;
            }
        }

        cout << "DAY 2: Answer for first puzzle is " << partOnecomputedScore << endl;
        cout << "DAY 2: Answer for second puzzle is " << partTwocomputedScore << endl;

    }
    return 0;
}
