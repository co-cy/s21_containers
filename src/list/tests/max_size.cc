//
// Created by Nana Daughterless on 11/15/22.
//

#include "gtest/gtest.h"
#include "list/list.h"
#include <list>

TEST(listMaxSizeTest, check_empty_list_char) {
  s21::list<char> a{};
  std::list<char> b{};

  EXPECT_EQ(a.max_size(), b.max_size());
}

TEST(listMaxSizeTest, check_empty_list_int) {
  s21::list<int> a{};
  std::list<int> b{};

  EXPECT_EQ(a.max_size(), b.max_size());
}

TEST(listMaxSizeTest, check_empty_list_ld) {
  s21::list<long double> a{};
  std::list<long double> b{};

  EXPECT_EQ(a.max_size(), b.max_size());
}

