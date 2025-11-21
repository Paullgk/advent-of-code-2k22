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

TEST(extractDataLines, extractLines)
{
    string input_data_example;
    string input_data;
    vector<string> input_data_example_lines;
    vector<string> input_data_lines;

    Tools tool;

    tool.readInputFile("src/day1/example", &input_data_example);
    tool.readInputFile("src/day1/input", &input_data);

    tool.extractLines(input_data_example, &input_data_example_lines);
    tool.extractLines(input_data, &input_data_lines);

    EXPECT_EQ(input_data_example_lines.size(), 14);
    EXPECT_EQ(input_data_lines.size(), 2249);

}


TEST(CheckDay1PartTwo, top_three_most_caloried_elf)
{
    Day1 day1;
    string input_data;
    Tools tool;
    int read_status = 0;
    int top_three_most_caloried_elf = 0;

    read_status = tool.readInputFile("src/day1/example", &input_data);

    if(read_status == 0){
        day1.extractFood(input_data);
        top_three_most_caloried_elf = day1.findTopThreeElfCalories();
        GTEST_ASSERT_EQ(top_three_most_caloried_elf, 45000);
    }
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
