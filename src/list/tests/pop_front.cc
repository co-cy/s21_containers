//
// Created by co_cy on 22.11.22.
//

#include <gtest/gtest.h>

#include "list/list.h"

template <class T>
struct ListPopFrontTest : public testing::Test {
  using List = s21::list<T>;
};

using ListPopFrontTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListPopFrontTest, ListPopFrontTypes);

TYPED_TEST(ListPopFrontTest, empty) {
  using List = typename TestFixture::List;
  List a{};

  EXPECT_NO_THROW(a.pop_front());
  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_EQ(a.begin(), a.end());
}

TYPED_TEST(ListPopFrontTest, one_item) {
  using List = typename TestFixture::List;
  List a({TypeParam()});

  EXPECT_NO_THROW(a.pop_front());
  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_EQ(a.begin(), a.end());
}

TYPED_TEST(ListPopFrontTest, many_item) {
  using List = typename TestFixture::List;
  TypeParam value(51);
  List a({TypeParam(), value, TypeParam()});

  EXPECT_NO_THROW(a.pop_front());
  EXPECT_DOUBLE_EQ(*a.begin(), value);
  EXPECT_DOUBLE_EQ(a.size(), 2);
}