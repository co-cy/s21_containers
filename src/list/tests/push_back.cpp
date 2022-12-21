//
// Created by co_cy on 22.11.22.
//

#include <gtest/gtest.h>

#include "list/list.h"

template <class T>
struct ListPushBackTest : public testing::Test {
  using List = s21::list<T>;
};

using ListPushBackTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListPushBackTest, ListPushBackTypes);

TYPED_TEST(ListPushBackTest, empty) {
  using List = typename TestFixture::List;
  List a{};
  TypeParam value(81);

  EXPECT_NO_THROW(a.push_back(value));
  EXPECT_DOUBLE_EQ(a.back(), value);
  EXPECT_DOUBLE_EQ(a.size(), 1);
}

TYPED_TEST(ListPushBackTest, one_item) {
  using List = typename TestFixture::List;
  List a({TypeParam()});
  TypeParam value(11);

  EXPECT_NO_THROW(a.push_back(value));
  EXPECT_DOUBLE_EQ(a.back(), value);
  EXPECT_DOUBLE_EQ(*(++a.begin()), value);
  EXPECT_DOUBLE_EQ(a.size(), 2);
}

TYPED_TEST(ListPushBackTest, many_item) {
  using List = typename TestFixture::List;
  List a({TypeParam(), TypeParam(), TypeParam()});
  TypeParam value(39);

  EXPECT_NO_THROW(a.push_back(value));
  EXPECT_DOUBLE_EQ(a.back(), value);
  EXPECT_DOUBLE_EQ(a.size(), 4);
}