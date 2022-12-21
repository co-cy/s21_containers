//
// Created by co_cy on 20.12.22.
//

#include <gtest/gtest.h>

#include "stack/stack.h"

template <typename T>
struct StackEmplaceFrontTest : public testing::Test {
  using Stack = s21::stack<T>;
};

using StackEmplaceFrontTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(StackEmplaceFrontTest, StackEmplaceFrontTypes);

TYPED_TEST(StackEmplaceFrontTest, empty) {
  using Stack = typename TestFixture::Stack;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  Stack a{};

  EXPECT_NO_THROW((void)a.emplace_front(value_1));
  EXPECT_NO_THROW((void)a.emplace_front(value_2, value_3));
  EXPECT_EQ(a.size(), 3);

  EXPECT_DOUBLE_EQ(a.top(), value_2);
  EXPECT_NO_THROW(a.pop());
  EXPECT_EQ(a.size(), 2);
  EXPECT_DOUBLE_EQ(a.top(), value_3);
  EXPECT_NO_THROW(a.pop());
  EXPECT_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.top(), value_1);
  EXPECT_NO_THROW(a.pop());
  EXPECT_EQ(a.size(), 0);
}

TYPED_TEST(StackEmplaceFrontTest, size_n) {
  using Stack = typename TestFixture::Stack;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  Stack a(0U);
  EXPECT_NO_THROW((void)a.emplace_front(value_1));
  EXPECT_NO_THROW((void)a.emplace_front(value_2, value_3));
  EXPECT_EQ(a.size(), 3);

  EXPECT_DOUBLE_EQ(a.top(), value_2);
  EXPECT_NO_THROW(a.pop());
  EXPECT_EQ(a.size(), 2);
  EXPECT_DOUBLE_EQ(a.top(), value_3);
  EXPECT_NO_THROW(a.pop());
  EXPECT_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.top(), value_1);
  EXPECT_NO_THROW(a.pop());
  EXPECT_EQ(a.size(), 0);

  Stack b(1U);
  EXPECT_NO_THROW((void)b.emplace_front(value_1));
  EXPECT_NO_THROW((void)b.emplace_front(value_2, value_3));
  EXPECT_EQ(b.size(), 4);

  EXPECT_DOUBLE_EQ(b.top(), value_2);
  EXPECT_NO_THROW(b.pop());
  EXPECT_EQ(b.size(), 3);
  EXPECT_DOUBLE_EQ(b.top(), value_3);
  EXPECT_NO_THROW(b.pop());
  EXPECT_EQ(b.size(), 2);
  EXPECT_DOUBLE_EQ(b.top(), value_1);
  EXPECT_NO_THROW(b.pop());
  EXPECT_EQ(b.size(), 1);

  Stack c(8U);
  EXPECT_NO_THROW((void)c.emplace_front(value_1));
  EXPECT_NO_THROW((void)c.emplace_front(value_2, value_3));
  EXPECT_EQ(c.size(), 11);

  EXPECT_DOUBLE_EQ(c.top(), value_2);
  EXPECT_NO_THROW(c.pop());
  EXPECT_EQ(c.size(), 10);
  EXPECT_DOUBLE_EQ(c.top(), value_3);
  EXPECT_NO_THROW(c.pop());
  EXPECT_EQ(c.size(), 9);
  EXPECT_DOUBLE_EQ(c.top(), value_1);
  EXPECT_NO_THROW(c.pop());
  EXPECT_EQ(c.size(), 8);
}
