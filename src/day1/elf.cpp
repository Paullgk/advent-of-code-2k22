#include <day1/elf.hpp>

void Elf::addFood(int calories){
    food.push_back(calories);
}

int Elf::getTotalCalories(){
    return accumulate(food.begin(), food.end(), 0);
}
