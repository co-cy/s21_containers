//
// Created by co_cy on 20.12.22.
//

#include <gtest/gtest.h>

#include "list/list.h"

template <typename T>
struct ListEmplaceBackTest : public testing::Test {
  using List = s21::list<T>;
};

using ListEmplaceBackTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListEmplaceBackTest, ListEmplaceBackTypes);

TYPED_TEST(ListEmplaceBackTest, empty) {
  using List = typename TestFixture::List;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  List a{};

  EXPECT_NO_THROW((void)a.emplace_back(value_1));
  EXPECT_NO_THROW((void)a.emplace_back(value_2, value_3));

  EXPECT_DOUBLE_EQ(*(a.begin() + 0), value_1);
  EXPECT_DOUBLE_EQ(*(a.begin() + 1), value_2);
  EXPECT_DOUBLE_EQ(*(a.begin() + 2), value_3);
  EXPECT_EQ(a.size(), 3);
}

TYPED_TEST(ListEmplaceBackTest, size_n) {
  using List = typename TestFixture::List;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  List a(0);
  EXPECT_NO_THROW(a.emplace_back(value_1));
  EXPECT_NO_THROW(a.emplace_back(value_2, value_3));
  EXPECT_DOUBLE_EQ(*(a.begin() + 0), value_1);
  EXPECT_DOUBLE_EQ(*(a.begin() + 1), value_2);
  EXPECT_DOUBLE_EQ(*(a.begin() + 2), value_3);
  EXPECT_EQ(a.size(), 3);

  List b(1);
  EXPECT_NO_THROW(b.emplace_back(value_1, value_2));
  EXPECT_NO_THROW(b.emplace_back(value_3));
  EXPECT_DOUBLE_EQ(*(b.begin() + 1), value_1);
  EXPECT_DOUBLE_EQ(*(b.begin() + 2), value_2);
  EXPECT_DOUBLE_EQ(*(b.begin() + 3), value_3);
  EXPECT_EQ(b.size(), 4);

  List c(8);
  EXPECT_NO_THROW(c.emplace_back(value_1));
  EXPECT_NO_THROW(c.emplace_back(value_2, value_3));
  EXPECT_DOUBLE_EQ(*(c.begin() + 8), value_1);
  EXPECT_DOUBLE_EQ(*(c.begin() + 9), value_2);
  EXPECT_DOUBLE_EQ(*(c.begin() + 10), value_3);
  EXPECT_EQ(c.size(), 11);
}
