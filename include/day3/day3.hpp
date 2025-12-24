#ifndef DAY3_H
#define DAY3_H

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Day3{
    public:
        Day3();
        /**
         * @brief Split a rucksack in two equivalent part.
         *
         * @param rucksack The full rucksack to be splitted.
         * @param splittedRucksackFirstPart A pointer containing the
         * first rucksack part.
         * @param splittedRucksackSecondPart A pointer containing the
         * second rucksack part.
         */
        void splitRucksack(string rucksack, string* splittedRucksackFirstPart, string* splittedRucksackSecondPart);
        /**
         * @brief Get the Item Priority object (a-z) (A-Z)
         *
         * @param item The item, in ASCII format
         * @return int The item priority
         */
        int  getItemPriority(char item);
        /**
         * @brief Given two parts of a rucksack, find the first
         * occurrence of an item.
         *
         * @param splittedRucksackFirstPart A pointer to the first rucksack.
         * @param splittedRucksackSecondPart A pointer to the second rucksack.
         */
        void findItemOccurrences(string* splittedRucksackFirstPart, string* splittedRucksackSecondPart);
        /**
         * @brief Add the priority of an item to the total priority sum.
         *
         * @param itemPriority The item priority.
         */
        void addSumPriority(int itemPriority);
        /**
         * @brief Get the Sum Priority object.
         *
         * @return int The total sum priority.
         */
        int  getSumPriority();
    private:
        /**
         * @brief The total priority sum.
         *
         */
        int sumPriority;
};

#endif
