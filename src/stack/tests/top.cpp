//
// Created by co_cy on 22.11.22.
//

#include "gtest/gtest.h"
#include "stack/stack.h"

template <typename T>
struct StackTopTest : public testing::Test {
  using Stack = s21::stack<T>;
};

using StackTopTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(StackTopTest, StackTopTypes);

TYPED_TEST(StackTopTest, size_1) {
  using Stack = typename TestFixture::Stack;
  TypeParam value(88);
  Stack a{{value}};

  EXPECT_DOUBLE_EQ(a.top(), value);
}

TYPED_TEST(StackTopTest, size_2) {
  using Stack = typename TestFixture::Stack;
  TypeParam value(88);
  Stack a{{value, TypeParam(1)}};

  EXPECT_DOUBLE_EQ(a.top(), value);
}

TYPED_TEST(StackTopTest, size_3) {
  using Stack = typename TestFixture::Stack;
  TypeParam value(88);
  Stack a{{value, TypeParam(1), TypeParam(2)}};

  EXPECT_DOUBLE_EQ(a.top(), value);
}
