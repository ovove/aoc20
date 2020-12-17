
#include "solver.hh"

#include <gtest/gtest.h>
#include <string>


TEST(Day5, Test1_1)
{
    const std::string seat_code{"BFFFBBFRRR"};
    EXPECT_EQ(get_row(seat_code), 70);
    EXPECT_EQ(get_col(seat_code), 7);
    EXPECT_EQ(get_id(seat_code), 567);
}

TEST(Day5, Test1_2)
{
    const std::string seat_code{"FFFBBBFRRR"};
    EXPECT_EQ(get_row(seat_code), 14);
    EXPECT_EQ(get_col(seat_code), 7);
    EXPECT_EQ(get_id(seat_code), 119);
}

TEST(Day5, Test1_3)
{
    const std::string seat_code{"BBFFBBFRLL"};
    EXPECT_EQ(get_row(seat_code), 102);
    EXPECT_EQ(get_col(seat_code), 4);
    EXPECT_EQ(get_id(seat_code), 820);
}
