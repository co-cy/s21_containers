//
// Created by co_cy on 22.11.22.
//

#include "gtest/gtest.h"
#include "stack/stack.h"

template <typename T>
struct StackEmptyTest : public testing::Test {
  using Stack = s21::stack<T>;
};

using StackEmptyTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(StackEmptyTest, StackEmptyTypes);

TYPED_TEST(StackEmptyTest, empty) {
  using Stack = typename TestFixture::Stack;
  EXPECT_TRUE(Stack().empty());
}

TYPED_TEST(StackEmptyTest, size_n) {
  using Stack = typename TestFixture::Stack;
  EXPECT_TRUE(Stack(0U).empty());
  EXPECT_FALSE(Stack(1U).empty());
  EXPECT_FALSE(Stack(8U).empty());
}

TYPED_TEST(StackEmptyTest, initializer_list) {
  using Stack = typename TestFixture::Stack;
  EXPECT_TRUE(Stack({}).empty());
  EXPECT_FALSE(Stack({TypeParam()}).empty());
  EXPECT_FALSE(Stack({TypeParam(), TypeParam(), TypeParam()}).empty());
}

TYPED_TEST(StackEmptyTest, other_constructor) {
  using Stack = typename TestFixture::Stack;

  Stack tmp_1{{TypeParam(1)}};
  EXPECT_FALSE(tmp_1.empty());
  Stack tmp_2(tmp_1);
  EXPECT_FALSE(tmp_1.empty());
  EXPECT_FALSE(tmp_2.empty());
  Stack tmp_3(std::move(tmp_2));
  EXPECT_FALSE(tmp_3.empty());
  Stack tmp_4{{TypeParam(4)}};
  tmp_4 = std::move(tmp_3);
  EXPECT_FALSE(tmp_4.empty());
}
