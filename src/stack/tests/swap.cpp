//
// Created by co_cy on 16.11.22.
//

#include <gtest/gtest.h>

#include "stack/stack.h"

template <typename T>
struct StackSwapTest : public testing::Test {
  using Stack = s21::stack<T>;
};

using StackSwapTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(StackSwapTest, StackSwapTypes);

TYPED_TEST(StackSwapTest, empty) {
  using Stack = typename TestFixture::Stack;
  Stack a{};
  Stack b{};

  EXPECT_NO_THROW(a.swap(b));
  EXPECT_EQ(a.size(), 0);
  EXPECT_EQ(b.size(), 0);
}

TYPED_TEST(StackSwapTest, one_item) {
  using Stack = typename TestFixture::Stack;
  Stack a(1U);
  Stack b(1U);

  EXPECT_NO_THROW(a.swap(b));
  EXPECT_EQ(a.size(), 1U);
  EXPECT_EQ(b.size(), 1U);
}

TYPED_TEST(StackSwapTest, many_item) {
  using Stack = typename TestFixture::Stack;
  Stack a(8U);
  Stack b(16U);

  EXPECT_NO_THROW(a.swap(b));
  EXPECT_EQ(a.size(), 16U);
  EXPECT_EQ(b.size(), 8U);
}
