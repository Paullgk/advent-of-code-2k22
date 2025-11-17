#include <day1/day1.hpp>

void Day1::extractFood(string InputData){
    const int InputDataLength = InputData.length();
    int current_pos = 0;
    int space_pos = 0;
    int elf_calories = 0;
    int elf_calories_length = 0;
    string elf_food;
    int elf_food_length = 0;

    while ( current_pos < InputDataLength )
    {
        Elf tiny_elf;

        // Looking for the space delimiter, that delimit each elf in
        // input data
        space_pos = InputData.find(SPACE_DELIMITER, current_pos);

        // Extract the substr between the current index position and
        // the space position
        elf_food = InputData.substr(current_pos,space_pos-current_pos);
        elf_food_length = elf_food.length();

        // Moving on the cursor just after the space
        current_pos=space_pos + SPACE_DELIMITER_LENGTH;

        // From the extracted food, extract the calories and add them
        // to our tiny elf

        extractCalories(elf_food, &tiny_elf);
        elfs.push_back(tiny_elf);

        if( space_pos == -1)
            break;

    }
}


void Day1::extractCalories(string Food, Elf* elf){
    const int FoodLength = Food.length();
    int current_pos = 0;
    int carriage_pos = 0;
    string calories;
    int absolute_calories = 0;
    int calories_length = 0;


    while ( current_pos < FoodLength ) {
        // Same stuff as `extractFood()`
        carriage_pos = Food.find('\n', current_pos);

        if( carriage_pos == -1)
            break;

        calories = Food.substr(current_pos, carriage_pos - current_pos);
        absolute_calories = stoi(calories);

        elf->addFood(absolute_calories);
        calories_length = calories.length();
        current_pos = carriage_pos + 1;

    }

}

int Day1::findMaxElfCalories(){
    vector<int> elf_calories; // Store every summed calories
    int elf_calorie = 0;
    int elf_index = 0;
    int sum = 0;

    // Parse every defined elfs
    for(auto elf:elfs){
        elf_calorie = elf.getTotalCalories();
        cout << "DEBUG: Elf " << elf_index << " weigth " << elf_calorie << endl;

        elf_calories.push_back(elf_calorie);

        elf_index += 1;
        sum += elf_calorie;
    }

    // Finding the maximum sum of calories
    auto max_calorie = *max_element(elf_calories.begin(), elf_calories.end());
    cout << "DEBUG: total sum:" << sum << endl;

    return max_calorie;
}
