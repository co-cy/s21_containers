//
// Created by co_cy on 22.11.22.
//

#include <gtest/gtest.h>

#include "list/list.h"

template <class T>
struct ListPopBackTest : public testing::Test {
  using List = s21::list<T>;
};

using ListPopBackTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListPopBackTest, ListPopBackTypes);

TYPED_TEST(ListPopBackTest, empty) {
  using List = typename TestFixture::List;
  List a{};

  EXPECT_NO_THROW(a.pop_back());
  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_EQ(a.begin(), a.end());
}

TYPED_TEST(ListPopBackTest, one_item) {
  using List = typename TestFixture::List;
  List a({TypeParam()});

  EXPECT_NO_THROW(a.pop_back());
  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_EQ(a.begin(), a.end());
}

TYPED_TEST(ListPopBackTest, many_item) {
  using List = typename TestFixture::List;
  TypeParam value(121);
  List a({TypeParam(), value, TypeParam()});

  EXPECT_NO_THROW(a.pop_back());
  EXPECT_DOUBLE_EQ(*(--a.end()), value);
  EXPECT_DOUBLE_EQ(a.size(), 2);
}