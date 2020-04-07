#include <gtest/gtest.h>

#include "trip_factory.cpp"

TEST(TripFactoryTest, test_create_1)
{
    Trip* pt = TripFactory::create("3公里,等待0分钟");
	ASSERT_TRUE(pt != nullptr);
	BasicTrip * bt = dynamic_cast<BasicTrip*>(pt);
    ASSERT_TRUE(bt->get_distance() == 3);
    ASSERT_TRUE(bt->get_waittime() == 0);
	delete pt;
}


TEST(TripFactoryTest, test_create_2)
{
    Trip* pt = TripFactory::create("2公里,等待3分钟");
	ASSERT_TRUE(pt != nullptr);
	BasicTrip * bt = dynamic_cast<BasicTrip*>(pt);
    ASSERT_TRUE(bt->get_distance() == 2);
    ASSERT_TRUE(bt->get_waittime() == 3);
	delete pt;
}


TEST(TripFactoryTest, test_create_3)
{
    Trip* pt = TripFactory::create("1公里等待1分钟");
	ASSERT_TRUE(pt != nullptr);
	BasicTrip * bt = dynamic_cast<BasicTrip*>(pt);
    ASSERT_TRUE(bt->get_distance() == 1);
    ASSERT_TRUE(bt->get_waittime() == 1);
	delete pt;
}

TEST(TripFactoryTest, test_create_4)
{
    Trip* pt = TripFactory::create("600公,等待0分钟");
	ASSERT_FALSE(pt != nullptr);
}


TEST(TripFactoryTest, test_create_5)
{
    Trip* pt = TripFactory::create("600公里,等0分钟");
	ASSERT_FALSE(pt != nullptr);
}

TEST(TripFactoryTest, test_create_6)
{
    Trip* pt = TripFactory::create("600公里,等待0分");
	ASSERT_FALSE(pt != nullptr);
}


