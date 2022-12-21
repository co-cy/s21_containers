//
// Created by co_cy on 22.11.22.
//

#include <gtest/gtest.h>

#include "stack/stack.h"

template <class T>
struct StackPopTest : public testing::Test {
  using Stack = s21::stack<T>;
};

using StackPopTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(StackPopTest, StackPopTypes);

TYPED_TEST(StackPopTest, empty) {
  using Stack = typename TestFixture::Stack;

  Stack a{};
  EXPECT_NO_THROW(a.pop());
}

TYPED_TEST(StackPopTest, one_item) {
  using Stack = typename TestFixture::Stack;
  TypeParam value_1(1);

  Stack a{{value_1}};
  EXPECT_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.top(), value_1);
  EXPECT_NO_THROW(a.pop());
  EXPECT_EQ(a.size(), 0);
}

TYPED_TEST(StackPopTest, many_item) {
  using Stack = typename TestFixture::Stack;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  Stack a{{value_1, value_2, value_3}};
  EXPECT_EQ(a.size(), 3);
  EXPECT_DOUBLE_EQ(a.top(), value_1);

  EXPECT_NO_THROW(a.pop());
  EXPECT_EQ(a.size(), 2);
  EXPECT_DOUBLE_EQ(a.top(), value_2);

  EXPECT_NO_THROW(a.pop());
  EXPECT_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.top(), value_3);

  EXPECT_NO_THROW(a.pop());
  EXPECT_EQ(a.size(), 0);
}
