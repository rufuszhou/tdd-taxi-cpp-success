#include <gtest/gtest.h>

#include "trip.h"

TEST(BasicTripTest, test_default)
{
    BasicTrip r;
    ASSERT_TRUE(r.get_distance() == 0);
    ASSERT_TRUE(r.get_waittime() == 0);
}

TEST(BasicTripTest, test_get)
{
    BasicTrip r1(1,0);
    ASSERT_TRUE(r1.get_distance() == 1);
    ASSERT_TRUE(r1.get_waittime() == 0);
}


TEST(BasicTripTest, test_copy)
{
    BasicTrip r1(1,2);
    BasicTrip r2(r1);
    ASSERT_TRUE(r2.get_distance() == 1);
    ASSERT_TRUE(r2.get_waittime() == 2);
}

TEST(BasicTripTest, test_set_get)
{
    BasicTrip r1;
    r1.set_distance(123);
    ASSERT_TRUE(r1.get_distance() == 123);
    ASSERT_TRUE(r1.get_waittime() == 0);

    r1.set_waittime(20);
    ASSERT_TRUE(r1.get_distance() == 123);
    ASSERT_TRUE(r1.get_waittime() == 20);
}

TEST(BasicTripTest, test_set_invalid)
{
    BasicTrip r1;
    r1.set_distance(-1);
    ASSERT_TRUE(r1.get_distance() == (unsigned int)-1);
    ASSERT_TRUE(r1.get_waittime() == 0);

    r1.set_waittime(-1);
    ASSERT_TRUE(r1.get_distance() ==  (unsigned int)-1);
    ASSERT_TRUE(r1.get_waittime() ==  (unsigned int)-1);
}


TEST(BasicTripTest, test_0_0)
{
	BasicTrip t(0,0);
	std::cout << t.to_string() ;
	ASSERT_TRUE(t.to_string() == "收费0元");
}

TEST(BasicTripTest, test_1_0)
{
	BasicTrip t(1,0);
	std::cout << t.to_string() ;
	ASSERT_TRUE(t.to_string() == "收费6元");
}

TEST(BasicTripTest, test_3_0)
{
	BasicTrip t(3,0);
	std::cout << t.to_string() ;
	ASSERT_TRUE(t.to_string() == "收费7元");
}

TEST(BasicTripTest, test_10_0)
{
	BasicTrip t(10,0);
	std::cout << t.to_string() ;
	ASSERT_TRUE(t.to_string() == "收费13元");
}

TEST(BasicTripTest, test_2_3)
{
	BasicTrip t(2,3);
	std::cout << t.to_string() ;
	ASSERT_TRUE(t.to_string() == "收费7元");
}