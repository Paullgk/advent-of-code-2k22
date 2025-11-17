#include <tools/tools.h>
#include <day1/day1.hpp>

int main(int argc,char* argv[]){
    Day1 day1;
    Tools tool;
    string input_data;
    int most_caloried_elf = 0;
    int read_status = 0;

    read_status = tool.readInputFile("src/day1/input", &input_data);

    if(read_status == 0){
        day1.extractFood(input_data);
        most_caloried_elf = day1.findMaxElfCalories();

        cout << "DAY 1: Answer for first puzzle is " << most_caloried_elf << endl;
        return 0;
    }

    return read_status;
}
