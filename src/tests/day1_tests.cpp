#include <gtest/gtest.h>
#include <day1/day1.hpp>
#include <tools/tools.h>

TEST(ReadDay1InputFile, readInputFile)
{
    string input_data;
    Tools tool;
    GTEST_ASSERT_EQ(tool.readInputFile("src/day1/input", &input_data), 0);
    GTEST_ASSERT_NE(tool.readInputFile("src/day1/thisfiledoesnotexist", &input_data), 0);
}

TEST(CheckDay1PartOne, findMaxElfCalories)
{
    Day1 day1;
    string example_data;
    string input_data;
    Tools tool;
    int read_status = 0;
    int most_caloried_elf = 0;

    read_status = tool.readInputFile("src/day1/example", &example_data);

    if(read_status == 0){
        day1.extractFood(example_data);
        most_caloried_elf = day1.findMaxElfCalories();
        GTEST_ASSERT_EQ(most_caloried_elf, 24000);
    }

    read_status = tool.readInputFile("src/day1/input", &input_data);

    if(read_status == 0){
        day1.extractFood(input_data);
        most_caloried_elf = day1.findMaxElfCalories();
        GTEST_ASSERT_EQ(most_caloried_elf, 69501);
    }
}
int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
