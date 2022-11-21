//
// Created by co_cy on 16.11.22.
//

#include "gtest/gtest.h"
#include "list/list.h"

TEST(listFrontTest, check_empty_list_char) {
  s21::list<char> a;
  EXPECT_ANY_THROW((void)a.front());
}

TEST(listFrontTest, check_empty_list_int) {
  s21::list<int> a;
  EXPECT_ANY_THROW((void)a.front());
}

TEST(listFrontTest, check_empty_list_ld) {
  s21::list<long double> a;
  EXPECT_ANY_THROW((void)a.front());
}

TEST(listFrontTest, check_one_list_char) {
  s21::list<char> a({'a'});
  EXPECT_EQ(a.front(), 'a');
}

TEST(listFrontTest, check_one_list_int) {
  s21::list<int> a({1});
  EXPECT_EQ(a.front(), 1);
}

TEST(listFrontTest, check_one_list_ld) {
  s21::list<long double> a({2.121});
  EXPECT_DOUBLE_EQ(a.front(), 2.121);
}

TEST(listFrontTest, check_many_list_char) {
  s21::list<char> a({'g', 'a', 'c', 'd'});
  EXPECT_EQ(a.front(), 'g');
}

TEST(listFrontTest, check_many_list_int) {
  s21::list<int> a({-10, 1, 2, 312, 4, 1, 6, 1});
  EXPECT_EQ(a.front(), -10);
}

TEST(listFrontTest, check_many_list_ld) {
  s21::list<long double> a({-113, -1235, 2.121});
  EXPECT_DOUBLE_EQ(a.front(), -113);
}
