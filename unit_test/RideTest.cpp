#include <gtest/gtest.h>

#include "ride.cpp"

TEST(RideTest, test_default)
{
    Ride r;
    ASSERT_TRUE(r.get_distance() == 0);
    ASSERT_TRUE(r.get_waittime() == 0);
}

TEST(RideTest, test_get)
{
    Ride r1(1,0);
    ASSERT_TRUE(r1.get_distance() == 1);
    ASSERT_TRUE(r1.get_waittime() == 0);
}


TEST(RideTest, test_copy)
{
    Ride r1(1,2);
    Ride r2(r1);
    ASSERT_TRUE(r2.get_distance() == 1);
    ASSERT_TRUE(r2.get_waittime() == 2);
}

TEST(RideTest, test_set_get)
{
    Ride r1;
    r1.set_distance(123);
    ASSERT_TRUE(r1.get_distance() == 123);
    ASSERT_TRUE(r1.get_waittime() == 0);

    r1.set_waittime(20);
    ASSERT_TRUE(r1.get_distance() == 123);
    ASSERT_TRUE(r1.get_waittime() == 20);
}

TEST(RideTest, test_set_invalid)
{
    Ride r1;
    r1.set_distance(-1);
    ASSERT_TRUE(r1.get_distance() == (unsigned int)-1);
    ASSERT_TRUE(r1.get_waittime() == 0);

    r1.set_waittime(-1);
    ASSERT_TRUE(r1.get_distance() ==  (unsigned int)-1);
    ASSERT_TRUE(r1.get_waittime() ==  (unsigned int)-1);
}

TEST(RideTest, test_from_string_1)
{
    Ride r1;
    ASSERT_TRUE(r1.from_string("3公里,等待0分钟"));
    ASSERT_TRUE(r1.get_distance() == 3);
    ASSERT_TRUE(r1.get_waittime() == 0);
}


TEST(RideTest, test_from_string_2)
{
    Ride r1;
    ASSERT_TRUE(r1.from_string("2公里,等待3分钟"));
    ASSERT_TRUE(r1.get_distance() == 2);
    ASSERT_TRUE(r1.get_waittime() == 3);
}


TEST(RideTest, test_from_string_3)
{
    Ride r1;
    ASSERT_TRUE(r1.from_string("1公里等待1分钟"));
    ASSERT_TRUE(r1.get_distance() == 1);
    ASSERT_TRUE(r1.get_waittime() == 1);
}

TEST(RideTest, test_from_string_4)
{
    Ride r1;
    ASSERT_TRUE(r1.from_string("3公里,等待0分钟"));
    ASSERT_TRUE(r1.get_distance() == 3);
    ASSERT_TRUE(r1.get_waittime() == 0);

    ASSERT_FALSE(r1.from_string("600公,等待0分钟"));
    ASSERT_TRUE(r1.get_distance() == 3);
    ASSERT_TRUE(r1.get_waittime() == 0);
}


TEST(RideTest, test_from_string_5)
{
    Ride r1;
    ASSERT_TRUE(r1.from_string("3公里,等待0分钟"));
    ASSERT_TRUE(r1.get_distance() == 3);
    ASSERT_TRUE(r1.get_waittime() == 0);

    ASSERT_FALSE(r1.from_string("600公里,等0分钟"));
    ASSERT_TRUE(r1.get_distance() == 3);
    ASSERT_TRUE(r1.get_waittime() == 0);
}

TEST(RideTest, test_from_string_6)
{
    Ride r1;
    ASSERT_TRUE(r1.from_string("3公里,等待0分钟"));
    ASSERT_TRUE(r1.get_distance() == 3);
    ASSERT_TRUE(r1.get_waittime() == 0);

    ASSERT_FALSE(r1.from_string("600公里,等待0分"));
    ASSERT_TRUE(r1.get_distance() == 3);
    ASSERT_TRUE(r1.get_waittime() == 0);
}
