#include <gtest/gtest.h>
#include <day1/day1.hpp>
#include <day2/day2.hpp>
#include <day2/player.hpp>
#include <tools/tools.h>


/* TOOLS TESTS */
TEST(ReadDay1InputFile, readInputFile)
{
    string input_data;
    Tools tool;
    GTEST_ASSERT_EQ(tool.readInputFile("src/day1/input", &input_data), 0);
    GTEST_ASSERT_NE(tool.readInputFile("src/day1/thisfiledoesnotexist", &input_data), 0);
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

/* DAY 1 TESTS  */
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

/* DAY 2 TESTS*/
TEST(CheckPlayerRoundExtraction, extractPlayerRound){
    Day2 day2;
    string input_data;
    Tools tool;

    Player player1 = Player(LEFT);
    Player player2 = Player(RIGHT);

    int player1Ascii = 0;
    int player2Ascii = 0;

    SHAPE player1Shape;
    SHAPE player2Shape;



    player1Ascii = player1.extractPlayerRound("X Y");
    player2Ascii = player2.extractPlayerRound("X Y");

    player1Shape = (SHAPE)player1.translateAsciiToShape(player1Ascii);
    player2Shape = (SHAPE)player2.translateAsciiToShape(player2Ascii);

    GTEST_ASSERT_EQ(player1Shape, ROCK);
    GTEST_ASSERT_EQ(player2Shape, PAPER);

    player1Ascii = player1.extractPlayerRound("A B");
    player2Ascii = player2.extractPlayerRound("C C");

    player1Shape = (SHAPE)player1.translateAsciiToShape(player1Ascii);
    player2Shape = (SHAPE)player2.translateAsciiToShape(player2Ascii);

    GTEST_ASSERT_EQ(player1Shape, ROCK);
    GTEST_ASSERT_EQ(player2Shape, SCISSORS);

}

TEST(CheckDay2PartOne, computeSimpleGame){

    Day2 day2;
    string input_data;
    Tools tool;
    vector<string> rounds;
    int computedScore = 0;
    int read_status = 0;

    read_status = tool.readInputFile("src/day2/input", &input_data);

    if(read_status == 0){
        tool.extractLines(input_data, &rounds);

        for(auto round:rounds){
            computedScore = day2.simpleComputeGame(round);
        }

        GTEST_ASSERT_EQ(computedScore, 14264);
    }
}

TEST(CheckDay2PartTwo, computeComplexGame){

    Day2 day2;
    string input_data;
    Tools tool;
    vector<string> rounds;
    int computedScore = 0;
    int read_status = 0;

    read_status = tool.readInputFile("src/day2/input", &input_data);

    if(read_status == 0){
        tool.extractLines(input_data, &rounds);

        for(auto round:rounds){
            computedScore = day2.complexComputeGame(round);
        }

        GTEST_ASSERT_EQ(computedScore, 12382);
    }
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
