#include <gtest/gtest.h>

#include <string>
#include <fstream>
#include <iostream>

#include "trips.h"

#define NON_EXIST_INPUT_FILE "./RANDOM_FILE_NAME_ASDFASDFASFAQFQWASDVW.txt"
#define VALID_INPUT_FILE "./TripsTestValidInput.txt"
#define INVALID_INPUT_FILE "./TripsTestInvalidInput.txt"

TEST(TripsTest, test_default)
{
    Trips ts;
    ASSERT_TRUE(ts.to_string().empty());
}

TEST(TripsTest, test_non_exist_input)
{
    Trips ts(NON_EXIST_INPUT_FILE);
    ASSERT_TRUE(ts.to_string().empty());
}

TEST(TripsTest, test_one_valid_line)
{
    std::ofstream test_file(VALID_INPUT_FILE);
    test_file<<"1公里,等待0分钟"<<std::endl;
    test_file.close();

    Trips ts(VALID_INPUT_FILE);
    ASSERT_TRUE(ts.to_string() == "收费6元\n");
}

TEST(TripsTest, test_four_valid_lines) 
{
    std::ofstream test_file(VALID_INPUT_FILE);
    test_file<<"1公里,等待0分钟"<<std::endl;
    test_file<<"3公里,等待0分钟"<<std::endl;
    test_file<<"10公里,等待0分钟"<<std::endl;
    test_file<<"2公里,等待3分钟"<<std::endl;
    test_file.close();

    Trips ts(VALID_INPUT_FILE);
    ASSERT_TRUE(ts.to_string() == "收费6元\n收费7元\n收费13元\n收费7元\n");
}

TEST(TripsTest, test_one_invalid_lines) 
{
    std::ofstream test_file(INVALID_INPUT_FILE);
    test_file<<"1公里,等0分钟"<<std::endl;
    test_file.close();

    Trips ts(INVALID_INPUT_FILE);
    ASSERT_TRUE(ts.to_string().empty());
}


TEST(TripsTest, test_multiple_invalid_lines_1) 
{
    std::ofstream test_file(INVALID_INPUT_FILE);
    test_file<<"1公里,等0分钟"<<std::endl;          // <-- invalid input
    test_file<<"3公里,等待0分钟"<<std::endl;
    test_file<<"10公里,等待0分钟"<<std::endl;
    test_file<<"2公里,等待3分钟"<<std::endl;
    test_file.close();

    Trips ts(INVALID_INPUT_FILE);
    ASSERT_TRUE(ts.to_string().empty());
}


TEST(TripsTest, test_multiple_invalid_lines_2) 
{
    std::ofstream test_file(INVALID_INPUT_FILE);
    test_file<<"1公里,等待0分钟"<<std::endl;         
    test_file<<"3公里,等待分钟"<<std::endl;     // <-- invalid input
    test_file<<"10公里,等待0分钟"<<std::endl;
    test_file<<"2公里,等待3分钟"<<std::endl;
    test_file.close();

    Trips ts(INVALID_INPUT_FILE);
    ASSERT_TRUE(ts.to_string().empty());
}
