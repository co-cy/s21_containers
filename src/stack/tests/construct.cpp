//
// Created by co_cy on 22.11.22.
//

#include <gtest/gtest.h>

#include "stack/stack.h"

template <typename T>
struct StackConstructorTest : public testing::Test {
  using Stack = s21::stack<T>;
};

using StackConstructorTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(StackConstructorTest, StackConstructorTypes);

TYPED_TEST(StackConstructorTest, empty) {
  using Stack = typename TestFixture::Stack;
  ASSERT_NO_THROW(Stack());
}

TYPED_TEST(StackConstructorTest, size_n) {
  using Stack = typename TestFixture::Stack;
  ASSERT_NO_THROW(Stack(0));
  ASSERT_NO_THROW(Stack(1));
  ASSERT_NO_THROW(Stack(8));
}

TYPED_TEST(StackConstructorTest, initializer_list) {
  using Stack = typename TestFixture::Stack;
  ASSERT_NO_THROW(Stack({}));
  ASSERT_NO_THROW(Stack({TypeParam()}));
  ASSERT_NO_THROW(Stack({TypeParam(), TypeParam(), TypeParam()}));
}
