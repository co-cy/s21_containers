//
// Created by co_cy on 16.11.22.
//

#include "gtest/gtest.h"
#include "list/list.h"

TEST(listClearTest, create_empty_list_char) {
  s21::list<char> a{};

  ASSERT_NO_THROW(a.clear());
  ASSERT_NO_THROW(a.clear());
  ASSERT_EQ(a.size(), 0);
  ASSERT_EQ(a.empty(), 0);
}

TEST(listClearTest, create_empty_list_int) {
  s21::list<int> a{};

  ASSERT_NO_THROW(a.clear());
  ASSERT_EQ(a.size(), 0);
  ASSERT_EQ(a.empty(), 0);
}

TEST(listClearTest, create_empty_list_ld) {
  s21::list<long double> a{};

  ASSERT_NO_THROW(a.clear());
  ASSERT_EQ(a.size(), 0);
  ASSERT_EQ(a.empty(), 0);
}

TEST(listClearTest, create_n_list_char) {
  s21::list<char> a(0);
  ASSERT_NO_THROW(a.clear());
  ASSERT_EQ(a.size(), 0);
  ASSERT_EQ(a.empty(), 0);

  s21::list<char> b(1);
  ASSERT_NO_THROW(b.clear());
  ASSERT_EQ(b.size(), 0);
  ASSERT_EQ(b.empty(), 0);

  s21::list<char> c(8);
  ASSERT_NO_THROW(c.clear());
  ASSERT_NO_THROW(c.clear());
  ASSERT_EQ(c.size(), 0);
  ASSERT_EQ(c.empty(), 0);
}

TEST(listClearTest, create_n_list_int) {
  s21::list<int> a(0);
  ASSERT_NO_THROW(a.clear());
  ASSERT_EQ(a.size(), 0);
  ASSERT_EQ(a.empty(), 0);

  s21::list<int> b(1);
  ASSERT_NO_THROW(b.clear());
  ASSERT_EQ(b.size(), 0);
  ASSERT_EQ(b.empty(), 0);

  s21::list<int> c(8);
  ASSERT_NO_THROW(c.clear());
  ASSERT_NO_THROW(c.clear());
  ASSERT_EQ(c.size(), 0);
  ASSERT_EQ(c.empty(), 0);
}

TEST(listClearTest, create_n_list_ld) {
  s21::list<long double> a(0);
  ASSERT_NO_THROW(a.clear());
  ASSERT_EQ(a.size(), 0);
  ASSERT_EQ(a.empty(), 0);

  s21::list<long double> b(1);
  ASSERT_NO_THROW(b.clear());
  ASSERT_NO_THROW(b.clear());
  ASSERT_EQ(b.size(), 0);
  ASSERT_EQ(b.empty(), 0);

  s21::list<long double> c(8);
  ASSERT_NO_THROW(c.clear());
  ASSERT_EQ(c.size(), 0);
  ASSERT_EQ(c.empty(), 0);
}

TEST(listClearTest, create_init_list_list_char) {
  s21::list<char> a({});
  ASSERT_NO_THROW(a.clear());
  ASSERT_EQ(a.size(), 0);
  ASSERT_EQ(a.empty(), 0);

  s21::list<char> b({'a'});
  ASSERT_NO_THROW(b.clear());
  ASSERT_EQ(b.size(), 0);
  ASSERT_EQ(b.empty(), 0);

  s21::list<char> c({'a', 'b', 'c'});
  ASSERT_NO_THROW(c.clear());
  ASSERT_EQ(c.size(), 0);
  ASSERT_EQ(c.empty(), 0);
}

TEST(listClearTest, create_init_list_list_int) {
  s21::list<int> a({});
  ASSERT_NO_THROW(a.clear());
  ASSERT_EQ(a.size(), 0);
  ASSERT_EQ(a.empty(), 0);

  s21::list<int> b({1});
  ASSERT_NO_THROW(b.clear());
  ASSERT_NO_THROW(b.clear());
  ASSERT_EQ(b.size(), 0);
  ASSERT_EQ(b.empty(), 0);

  s21::list<int> c({1, 2, 3});
  ASSERT_NO_THROW(c.clear());
  ASSERT_EQ(c.size(), 0);
  ASSERT_EQ(c.empty(), 0);
}

TEST(listClearTest, create_init_list_list_ld) {
  s21::list<long double> a({});
  ASSERT_NO_THROW(a.clear());
  ASSERT_EQ(a.size(), 0);
  ASSERT_EQ(a.empty(), 0);

  s21::list<long double> b({0.0025});
  ASSERT_NO_THROW(b.clear());
  ASSERT_EQ(b.size(), 0);
  ASSERT_EQ(b.empty(), 0);

  s21::list<long double> c({0.12, -0.1, 1123, -1});
  ASSERT_NO_THROW(c.clear());
  ASSERT_EQ(c.size(), 0);
  ASSERT_EQ(c.empty(), 0);
}
