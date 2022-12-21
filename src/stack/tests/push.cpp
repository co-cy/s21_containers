//
// Created by co_cy on 22.11.22.
//

#include <gtest/gtest.h>

#include "stack/stack.h"

template <class T>
struct StackPushTest : public testing::Test {
  using Stack = s21::stack<T>;
};

using StackPushTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(StackPushTest, StackPushTypes);

TYPED_TEST(StackPushTest, empty) {
  using Stack = typename TestFixture::Stack;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  Stack a{};
  EXPECT_EQ(a.size(), 0);

  EXPECT_NO_THROW(a.push(value_1));
  EXPECT_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.top(), value_1);

  EXPECT_NO_THROW(a.push(value_2));
  EXPECT_EQ(a.size(), 2);
  EXPECT_DOUBLE_EQ(a.top(), value_2);

  EXPECT_NO_THROW(a.push(value_3));
  EXPECT_EQ(a.size(), 3);
  EXPECT_DOUBLE_EQ(a.top(), value_3);
}

TYPED_TEST(StackPushTest, one_item) {
  using Stack = typename TestFixture::Stack;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  Stack a{{TypeParam()}};
  EXPECT_EQ(a.size(), 1);

  EXPECT_NO_THROW(a.push(value_1));
  EXPECT_EQ(a.size(), 2);
  EXPECT_DOUBLE_EQ(a.top(), value_1);

  EXPECT_NO_THROW(a.push(value_2));
  EXPECT_EQ(a.size(), 3);
  EXPECT_DOUBLE_EQ(a.top(), value_2);

  EXPECT_NO_THROW(a.push(value_3));
  EXPECT_EQ(a.size(), 4);
  EXPECT_DOUBLE_EQ(a.top(), value_3);
}

TYPED_TEST(StackPushTest, many_item) {
  using Stack = typename TestFixture::Stack;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  Stack a{{TypeParam(), TypeParam(), TypeParam()}};
  EXPECT_EQ(a.size(), 3);

  EXPECT_NO_THROW(a.push(value_1));
  EXPECT_EQ(a.size(), 4);
  EXPECT_DOUBLE_EQ(a.top(), value_1);

  EXPECT_NO_THROW(a.push(value_2));
  EXPECT_EQ(a.size(), 5);
  EXPECT_DOUBLE_EQ(a.top(), value_2);

  EXPECT_NO_THROW(a.push(value_3));
  EXPECT_EQ(a.size(), 6);
  EXPECT_DOUBLE_EQ(a.top(), value_3);
}
