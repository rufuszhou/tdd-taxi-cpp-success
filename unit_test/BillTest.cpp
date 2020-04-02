#include <gtest/gtest.h>

#include "bill.cpp"

TEST(BillTest, test_0_0)
{
	Bill b(Ride(0,0));
	std::cout << b.to_string() ;
	ASSERT_TRUE(b.to_string() == "收费0元");
}

TEST(BillTest, test_1_0)
{
	Bill b(Ride(1,0));
	std::cout << b.to_string() ;
	ASSERT_TRUE(b.to_string() == "收费6元");
}

TEST(BillTest, test_3_0)
{
	Bill b(Ride(3,0));
	std::cout << b.to_string() ;
	ASSERT_TRUE(b.to_string() == "收费7元");
}

TEST(BillTest, test_10_0)
{
	Bill b(Ride(10,0));
	std::cout << b.to_string() ;
	ASSERT_TRUE(b.to_string() == "收费13元");
}

TEST(BillTest, test_2_3)
{
	Bill b(Ride(2,3));
	std::cout << b.to_string() ;
	ASSERT_TRUE(b.to_string() == "收费7元");
}