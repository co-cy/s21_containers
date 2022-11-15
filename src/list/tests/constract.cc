//
// Created by Nana Daughterless on 11/15/22.
//

#include "gtest/gtest.h"
#include "list/list.h"

TEST(listConstructTest, create_empty_list_char) {
  ASSERT_NO_THROW(s21::list<char> a{});
}

TEST(listConstructTest, create_empty_list_int) {
  ASSERT_NO_THROW(s21::list<int> a{});
}

TEST(listConstructTest, create_empty_list_ld) {
  ASSERT_NO_THROW(s21::list<long double> a{});
}
