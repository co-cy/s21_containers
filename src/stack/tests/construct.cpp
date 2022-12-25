//
// Created by co_cy on 22.11.22.
//

#include "gtest/gtest.h"
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
  ASSERT_NO_THROW(Stack(0U));
  ASSERT_NO_THROW(Stack(1U));
  ASSERT_NO_THROW(Stack(8U));
}

TYPED_TEST(StackConstructorTest, initializer_list) {
  using Stack = typename TestFixture::Stack;
  ASSERT_NO_THROW(Stack({}));
  ASSERT_NO_THROW(Stack({TypeParam()}));
  ASSERT_NO_THROW(Stack({TypeParam(), TypeParam(), TypeParam()}));
}

TYPED_TEST(StackConstructorTest, other_constructor) {
  using Stack = typename TestFixture::Stack;

  ASSERT_NO_THROW({
    Stack tmp_1{{TypeParam(1)}};
    Stack tmp_2(tmp_1);
    Stack tmp_3(std::move(tmp_2));
    Stack tmp_4{{TypeParam(4)}};
    tmp_4 = std::move(tmp_3);
  });
}
