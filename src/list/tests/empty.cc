//
// Created by Nana Daughterless on 11/15/22.
//

#include "gtest/gtest.h"
#include "list/list.h"

TEST(listEmptyTest, check_empty_list_char) {
  s21::list<char> a{};
  EXPECT_TRUE(a.empty());
}

TEST(listEmptyTest, check_empty_list_int) {
  s21::list<int> a{};
  EXPECT_TRUE(a.empty());
}

TEST(listEmptyTest, check_empty_list_ld) {
  s21::list<long double> a{};
  EXPECT_TRUE(a.empty());
}
