//
// Created by co_cy on 20.12.22.
//

#include <gtest/gtest.h>

#include "list/list.h"

template <typename T>
struct ListEmplaceTest : public testing::Test {
  using List = s21::list<T>;
};

using ListEmplaceTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListEmplaceTest, ListEmplaceTypes);

TYPED_TEST(ListEmplaceTest, empty) {
  using List = typename TestFixture::List;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  List a{};

  EXPECT_NO_THROW((void)a.emplace(a.begin(), value_1));
  EXPECT_NO_THROW((void)a.emplace(a.end(), value_2, value_3));

  EXPECT_DOUBLE_EQ(*(a.begin() + 0), value_1);
  EXPECT_DOUBLE_EQ(*(a.begin() + 1), value_2);
  EXPECT_DOUBLE_EQ(*(a.begin() + 2), value_3);
  EXPECT_EQ(a.size(), 3);
}

TYPED_TEST(ListEmplaceTest, size_n) {
  using List = typename TestFixture::List;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  List a(0);
  EXPECT_NO_THROW(a.emplace(a.begin(), value_1, value_2));
  EXPECT_NO_THROW(a.emplace(a.end(), value_3));
  EXPECT_DOUBLE_EQ(*(a.begin() + 0), value_1);
  EXPECT_DOUBLE_EQ(*(a.begin() + 1), value_2);
  EXPECT_DOUBLE_EQ(*(a.begin() + 2), value_3);
  EXPECT_EQ(a.size(), 3);

  List b(1);
  EXPECT_NO_THROW(b.emplace(b.begin(), value_1, value_2));
  EXPECT_NO_THROW(b.emplace(b.end(), value_3));
  EXPECT_DOUBLE_EQ(*(b.begin() + 0), value_1);
  EXPECT_DOUBLE_EQ(*(b.begin() + 1), value_2);
  EXPECT_DOUBLE_EQ(*(b.begin() + 3), value_3);
  EXPECT_EQ(b.size(), 4);

  List c(8);
  EXPECT_NO_THROW(c.emplace(c.begin() + 4, value_1, value_2));
  EXPECT_NO_THROW(c.emplace(c.begin(), value_3));
  EXPECT_DOUBLE_EQ(*(c.begin() + 5), value_1);
  EXPECT_DOUBLE_EQ(*(c.begin() + 6), value_2);
  EXPECT_DOUBLE_EQ(*(c.begin() + 0), value_3);
  EXPECT_EQ(c.size(), 11);
}
