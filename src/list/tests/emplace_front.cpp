//
// Created by co_cy on 20.12.22.
//

#include <gtest/gtest.h>

#include "list/list.h"

template <typename T>
struct ListEmplaceFrontTest : public testing::Test {
  using List = s21::list<T>;
};

using ListEmplaceFrontTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListEmplaceFrontTest, ListEmplaceFrontTypes);

TYPED_TEST(ListEmplaceFrontTest, empty) {
  using List = typename TestFixture::List;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  List a{};

  EXPECT_NO_THROW((void)a.emplace_front(value_1));
  EXPECT_NO_THROW((void)a.emplace_front(value_2, value_3));

  EXPECT_DOUBLE_EQ(*(a.begin() + 0), value_2);
  EXPECT_DOUBLE_EQ(*(a.begin() + 1), value_3);
  EXPECT_DOUBLE_EQ(*(a.begin() + 2), value_1);
  EXPECT_EQ(a.size(), 3);
}

TYPED_TEST(ListEmplaceFrontTest, size_n) {
  using List = typename TestFixture::List;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  List a(0);
  EXPECT_NO_THROW(a.emplace_front(value_1));
  EXPECT_NO_THROW(a.emplace_front(value_2, value_3));
  EXPECT_DOUBLE_EQ(*(a.begin() + 0), value_2);
  EXPECT_DOUBLE_EQ(*(a.begin() + 1), value_3);
  EXPECT_DOUBLE_EQ(*(a.begin() + 2), value_1);
  EXPECT_EQ(a.size(), 3);

  List b(1);
  EXPECT_NO_THROW(b.emplace_front(value_1, value_2));
  EXPECT_NO_THROW(b.emplace_front(value_3));
  EXPECT_DOUBLE_EQ(*(b.begin() + 0), value_3);
  EXPECT_DOUBLE_EQ(*(b.begin() + 1), value_1);
  EXPECT_DOUBLE_EQ(*(b.begin() + 2), value_2);
  EXPECT_EQ(b.size(), 4);

  List c(8);
  EXPECT_NO_THROW(c.emplace_front(value_1));
  EXPECT_NO_THROW(c.emplace_front(value_2, value_3));
  EXPECT_DOUBLE_EQ(*(c.begin() + 0), value_2);
  EXPECT_DOUBLE_EQ(*(c.begin() + 1), value_3);
  EXPECT_DOUBLE_EQ(*(c.begin() + 2), value_1);
  EXPECT_EQ(c.size(), 11);
}
