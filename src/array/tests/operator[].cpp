//
// Created by co_cy on 20.12.22.
//

#include <gtest/gtest.h>

#include "array/array.h"

template <class T>
struct ArrayOperatorGetTest : public testing::Test {};

using ArrayOperatorGetTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ArrayOperatorGetTest, ArrayOperatorGetTypes);

TYPED_TEST(ArrayOperatorGetTest, size_1) {
  TypeParam value{99};
  s21::array<TypeParam, 1U> a{{value}};
  const s21::array<TypeParam, 1U> const_a{{value}};

  EXPECT_DOUBLE_EQ(a[0], value);
  EXPECT_DOUBLE_EQ(const_a[0], value);
}

TYPED_TEST(ArrayOperatorGetTest, size_3) {
  TypeParam value_1{91};
  TypeParam value_2{92};
  TypeParam value_3{93};
  s21::array<TypeParam, 3U> a{{value_1, value_2, value_3}};
  const s21::array<TypeParam, 3U> const_a{{value_1, value_2, value_3}};

  EXPECT_DOUBLE_EQ(a[0], value_1);
  EXPECT_DOUBLE_EQ(a[1], value_2);
  EXPECT_DOUBLE_EQ(a[2], value_3);

  EXPECT_DOUBLE_EQ(const_a[0], value_1);
  EXPECT_DOUBLE_EQ(const_a[1], value_2);
  EXPECT_DOUBLE_EQ(const_a[2], value_3);
}
