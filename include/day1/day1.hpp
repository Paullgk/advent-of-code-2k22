#ifndef DAY1_H
#define DAY1_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <day1/elf.hpp>
#include <tools/tools.h>

using namespace std;

/**
 * @brief The day 1 puzzles.
 *
 */
class Day1 {
    public:
        /**
         * @brief From the input data, extract each elf food, and
         * instanciate the elf with their carried food to the vector `elfs`.
         *
         * @param InputData The puzzle read input data
         */
        void extractFood(string InputData);
        /**
         * @brief From the food, extract each calories and append them
         * to the elf that carry them.
         *
         * @param Food The elf food, extrated by `extractFood`.
         * @param elf The elf pointer object where the extracted
         * food calories should go.
         */
        void extractCalories(string Food, Elf* elf);
        /**
         * @brief find the maximum sum of calories carried by an elf.
         *
         * @return int The maximum calories value carried by an elf.
         */
        int findMaxElfCalories();

    private:
        /**
         * @brief The vector of elfs carrying their food.
         *
         */
        vector<Elf> elfs;
};
#endif
