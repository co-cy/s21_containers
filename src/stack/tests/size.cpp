//
// Created by co_cy on 22.11.22.
//

#include "gtest/gtest.h"
#include "stack/stack.h"

template <typename T>
struct StackSizeTest : public testing::Test {
  using Stack = s21::stack<T>;
};

using StackSizeTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(StackSizeTest, StackSizeTypes);

TYPED_TEST(StackSizeTest, empty) {
  using Stack = typename TestFixture::Stack;
  EXPECT_EQ(Stack().size(), 0);
}

TYPED_TEST(StackSizeTest, size_n) {
  using Stack = typename TestFixture::Stack;
  EXPECT_EQ(Stack(0U).size(), 0);
  EXPECT_EQ(Stack(1U).size(), 1);
  EXPECT_EQ(Stack(8U).size(), 8);
}

TYPED_TEST(StackSizeTest, initializer_list) {
  using Stack = typename TestFixture::Stack;
  EXPECT_EQ(Stack({}).size(), 0);
  EXPECT_EQ(Stack({TypeParam()}).size(), 1);
  EXPECT_EQ(Stack({TypeParam(), TypeParam(), TypeParam()}).size(), 3);
}

TYPED_TEST(StackSizeTest, other_constructor) {
  using Stack = typename TestFixture::Stack;

  Stack tmp_1{{TypeParam(1)}};
  EXPECT_EQ(tmp_1.size(), 1);
  Stack tmp_2(tmp_1);
  EXPECT_EQ(tmp_1.size(), 1);
  EXPECT_EQ(tmp_2.size(), 1);
  Stack tmp_3(std::move(tmp_2));
  EXPECT_EQ(tmp_3.size(), 1);
  Stack tmp_4{{TypeParam(4)}};
  EXPECT_EQ(tmp_4.size(), 1);
  tmp_4 = std::move(tmp_3);
  EXPECT_EQ(tmp_4.size(), 1);
}
