
#ifndef ELF_H
#define ELF_H

#include <vector>
#include <numeric>

using namespace std;

/**
 * @brief A simple ELF, carrying food.
 *
 */
class Elf
{
private:
    /**
     * @brief Vector of each food carried by the ELF, in calories unit.
     *
     */
    vector<int> m_food;


public:
    /**
     * @brief Add a new food unit to the `food` vector, in calories unit.
     *
     * @param calories The food to add in calories unit.
     */
    void addFood(int calories);

    /**
     * @brief Get the sum of the `food` vector.
     *
     * @return int The total sum of the calories carried by the elf.
     */
    int getTotalCalories();

    /**
     * @brief Set the Elf `m_food` food calories vector.
     *
     * @param foodCalories A vector of int containing the food calories
     */
    void setElfFoodCalories(vector<int> foodCalories);

};
#endif
