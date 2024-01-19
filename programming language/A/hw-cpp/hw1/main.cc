#include "hw1.h"
#include "gtest/gtest.h"

TEST(TEST_IS_OLDER, test_equal) {
  ASSERT_EQ(is_older({2012, 1, 1}, {2012, 1, 1}), false);
}

TEST(TEST_IS_OLDER, test_single_less) {
  ASSERT_EQ(is_older({2012, 2, 1}, {2013, 2, 1}), true);
  ASSERT_EQ(is_older({2013, 1, 1}, {2013, 2, 1}), true);
  ASSERT_EQ(is_older({2013, 1, 31}, {2013, 2, 1}), true);
  
  ASSERT_EQ(is_older({2013, 2, 1}, {2012, 2, 1}), false);
  ASSERT_EQ(is_older({2013, 2, 1}, {2013, 1, 1}), false);
  ASSERT_EQ(is_older({2013, 2, 1}, {2013, 1, 31}), false);
}

TEST(TEST_IS_OLDER, test_double_less) {
  ASSERT_EQ(is_older({2012, 1, 2}, {2013, 2, 2}), true);
  ASSERT_EQ(is_older({2012, 2, 1}, {2013, 2, 2}), true);
  ASSERT_EQ(is_older({2013, 1, 1}, {2013, 2, 2}), true);
  
  ASSERT_EQ(is_older({2013, 2, 2}, {2012, 1, 2}), false);
  ASSERT_EQ(is_older({2013, 2, 2}, {2013, 2, 1}), false);
  ASSERT_EQ(is_older({2013, 2, 2}, {2013, 1, 1}), false);
}

TEST(TEST_IS_OLDER, test_all_less) {
  ASSERT_EQ(is_older({2012, 1, 1}, {2013, 2, 2}), true);
  
  ASSERT_EQ(is_older({2013, 2, 2}, {2012, 1, 1}), false);
}

TEST(TEST_NUMBER_IN_MONTH, test_all) {
  ASSERT_EQ(number_in_month({
    {2012, 2, 1}, {2012, 2, 3}, {2012, 1, 3}, {2012, 2, 3},
    {2012, 1, 3}, {2012, 2, 3}, {2012, 1, 3}, {2012, 2, 3}
  }, 2), 5);
}

TEST(TEST_NUMBER_IN_MONTHS, test_all) {
  ASSERT_EQ(number_in_months({
    {2012, 2, 1}, {2012, 2, 3}, {2012, 1, 3}, {2012, 2, 3},
    {2012, 1, 3}, {2012, 2, 3}, {2012, 1, 3}, {2012, 2, 3}
  }, {1, 2, 3}), 8);
}

TEST(TEST_DATES_IN_MONTH, test_all) {
  ASSERT_EQ(dates_in_month({
    {2012, 2, 1}, {2012, 2, 3}, {2012, 1, 3}, {2012, 2, 3},
    {2012, 1, 3}, {2012, 2, 3}, {2012, 1, 3}, {2012, 2, 3}
  }, 2), (date_list_type{
    {2012, 2, 1}, {2012, 2, 3}, {2012, 2, 3}, {2012, 2, 3}, {2012, 2, 3}
  }));
}

TEST(TEST_DATES_IN_MONTHS, test_all) {
  ASSERT_EQ(dates_in_months({
    {2012, 2, 1}, {2012, 2, 3}, {2012, 1, 3}, {2012, 2, 3},
    {2012, 1, 3}, {2012, 2, 3}, {2012, 1, 3}, {2012, 2, 3}
  }, {1, 2, 3}), (date_list_type{
    {2012, 2, 1}, {2012, 2, 3}, {2012, 1, 3}, {2012, 2, 3},
    {2012, 1, 3}, {2012, 2, 3}, {2012, 1, 3}, {2012, 2, 3}
  }));
}

TEST(TEST_GET_NTH, test_all) {
  ASSERT_EQ(get_nth({
    "hi", "there", "how", "are", "you"
  }, 2), "there");
}

GTEST_API_ int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
} 