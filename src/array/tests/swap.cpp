//
// Created by co_cy on 20.12.22.
//

#include <gtest/gtest.h>

#include "array/array.h"

template <class T>
struct ArraySwapTest : public testing::Test {};

using ArraySwapTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ArraySwapTest, ArraySwapTypes);

TYPED_TEST(ArraySwapTest, empty) {
  s21::array<TypeParam, 0U> a{};
  s21::array<TypeParam, 0U> b{};

  a.swap(b);

  EXPECT_EQ(a.size(), 0);
  EXPECT_EQ(b.size(), 0);
}

TYPED_TEST(ArraySwapTest, size_1) {
  TypeParam value_1{1};
  TypeParam value_2{2};

  s21::array<TypeParam, 1U> a({value_1});
  s21::array<TypeParam, 1U> b({value_2});

  a.swap(b);

  EXPECT_DOUBLE_EQ(a.front(), value_2);
  EXPECT_DOUBLE_EQ(b.front(), value_1);
}

TYPED_TEST(ArraySwapTest, size_3) {
  TypeParam value_1_1{1};
  TypeParam value_1_2{3};
  TypeParam value_1_3{5};

  TypeParam value_2_1{2};
  TypeParam value_2_2{4};
  TypeParam value_2_3{6};

  s21::array<TypeParam, 3U> a({value_1_1, value_1_2, value_1_3});
  s21::array<TypeParam, 3U> b({value_2_1, value_2_2, value_2_3});

  a.swap(b);

  EXPECT_DOUBLE_EQ(a[0], value_2_1);
  EXPECT_DOUBLE_EQ(a[1], value_2_2);
  EXPECT_DOUBLE_EQ(a[2], value_2_3);

  EXPECT_DOUBLE_EQ(b[0], value_1_1);
  EXPECT_DOUBLE_EQ(b[1], value_1_2);
  EXPECT_DOUBLE_EQ(b[2], value_1_3);
}
