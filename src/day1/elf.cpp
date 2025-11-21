#include <day1/elf.hpp>

void Elf::addFood(int calories){
    m_food.push_back(calories);
}

int Elf::getTotalCalories(){
    return accumulate(m_food.begin(), m_food.end(), 0);
}

void Elf::setElfFoodCalories(vector<int> foodCalories){
    m_food = foodCalories;
}
