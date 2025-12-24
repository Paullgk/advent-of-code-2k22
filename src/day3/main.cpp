#include <day3/day3.hpp>
#include <tools/tools.h>


int main(int argc,char* argv[]){
    Day3 day3PartOne;
    Tools tool;
    int read_status = 0;
    int answerPartOne = 0;
    string input_data;
    string splittedRucksackFirstPart;
    string splittedRucksackSecondPart;

    vector<string> rucksacks;

    read_status = tool.readInputFile("src/day3/input", &input_data);

    if(read_status == 0){
        tool.extractLines(input_data, &rucksacks);
    }

    for(auto rucksack:rucksacks){
        day3PartOne.splitRucksack(rucksack, &splittedRucksackFirstPart, &splittedRucksackSecondPart);
        day3PartOne.findItemOccurrences(&splittedRucksackFirstPart, &splittedRucksackSecondPart);
    }


    answerPartOne = day3PartOne.getSumPriority();
    cout << "DAY 3: Answer for first puzzle is " << answerPartOne << endl;



    return 0;

}
