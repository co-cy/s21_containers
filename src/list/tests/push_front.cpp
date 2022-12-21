//
// Created by co_cy on 22.11.22.
//

#include <gtest/gtest.h>

#include "list/list.h"

template <class T>
struct ListPushFrontTest : public testing::Test {
  using List = s21::list<T>;
};

using ListPushFrontTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListPushFrontTest, ListPushFrontTypes);

TYPED_TEST(ListPushFrontTest, empty) {
  using List = typename TestFixture::List;
  List a{};
  TypeParam value(81);

  EXPECT_NO_THROW(a.push_front(value));
  EXPECT_DOUBLE_EQ(a.front(), value);
  EXPECT_DOUBLE_EQ(a.size(), 1);
}

TYPED_TEST(ListPushFrontTest, one_item) {
  using List = typename TestFixture::List;
  List a({TypeParam()});
  TypeParam value(11);

  EXPECT_NO_THROW(a.push_front(value));
  EXPECT_DOUBLE_EQ(a.front(), value);
  EXPECT_DOUBLE_EQ(*a.begin(), value);
  EXPECT_DOUBLE_EQ(a.size(), 2);
}

TYPED_TEST(ListPushFrontTest, many_item) {
  using List = typename TestFixture::List;
  List a({TypeParam(), TypeParam(), TypeParam()});
  TypeParam value(39);

  EXPECT_NO_THROW(a.push_front(value));
  EXPECT_DOUBLE_EQ(a.front(), value);
  EXPECT_DOUBLE_EQ(a.size(), 4);
}