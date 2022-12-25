//
// Created by co_cy on 20.12.22.
//

#include <gtest/gtest.h>

#include "array/array.h"

template <class T>
struct ArrayFillTest : public testing::Test {};

using ArrayFillTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ArrayFillTest, ArrayFillTypes);

TYPED_TEST(ArrayFillTest, empty) {
  s21::array<TypeParam, 0U> a{};

  EXPECT_NO_THROW(a.fill(TypeParam(3)));
}

TYPED_TEST(ArrayFillTest, size_1) {
  s21::array<TypeParam, 1U> a{};

  TypeParam value{1};
  a.fill(value);

  EXPECT_DOUBLE_EQ(a.front(), value);
}

TYPED_TEST(ArrayFillTest, size_3) {
  s21::array<TypeParam, 3U> a{};

  TypeParam value{3};
  a.fill(value);

  EXPECT_DOUBLE_EQ(a[0], value);
  EXPECT_DOUBLE_EQ(a[1], value);
  EXPECT_DOUBLE_EQ(a[2], value);
}
