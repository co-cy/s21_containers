//
// Created by Nana Daughterless on 11/15/22.
//

#include "gtest/gtest.h"
#include "list/list.h"

TEST(listConstructTest, create_empty_list_char) {
  ASSERT_NO_THROW(s21::list<char>());
}

TEST(listConstructTest, create_empty_list_int) {
  ASSERT_NO_THROW(s21::list<int>());
}

TEST(listConstructTest, create_empty_list_ld) {
  ASSERT_NO_THROW(s21::list<long double>());
}

TEST(listConstructTest, create_n_list_char) {
  ASSERT_NO_THROW(s21::list<char>(0));
  ASSERT_NO_THROW(s21::list<char>(1));
  ASSERT_NO_THROW(s21::list<char>(8));
}

TEST(listConstructTest, create_n_list_int) {
  ASSERT_NO_THROW(s21::list<int>(0));
  ASSERT_NO_THROW(s21::list<int>(1));
  ASSERT_NO_THROW(s21::list<int>(8));
}

TEST(listConstructTest, create_n_list_ld) {
  ASSERT_NO_THROW(s21::list<long double>(0));
  ASSERT_NO_THROW(s21::list<long double>(1));
  ASSERT_NO_THROW(s21::list<long double>(8));
}

TEST(listConstructTest, create_init_list_list_char) {
  ASSERT_NO_THROW(s21::list<char>({}));
  ASSERT_NO_THROW(s21::list<char>({'a'}));
  ASSERT_NO_THROW(s21::list<char>({'a', 'b', 'c'}));
}

TEST(listConstructTest, create_init_list_list_int) {
  ASSERT_NO_THROW(s21::list<int>({}));
  ASSERT_NO_THROW(s21::list<int>({1}));
  ASSERT_NO_THROW(s21::list<int>({1, 2, 3}));
}

TEST(listConstructTest, create_init_list_list_ld) {
  ASSERT_NO_THROW(s21::list<long double>({}));
  ASSERT_NO_THROW(s21::list<long double>({0.025}));
  ASSERT_NO_THROW(s21::list<long double>({0.25, 1.9, 51.31, 1}));
}
