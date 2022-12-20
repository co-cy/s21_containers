//
// Created by co_cy on 22.11.22.
//

#include <gtest/gtest.h>

#include "array/array.h"

template <class T>
struct ArrayMaxSizeTest : public testing::Test {};

using ArrayMaxSizeTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ArrayMaxSizeTest, ArrayMaxSizeTypes);

TYPED_TEST(ArrayMaxSizeTest, empty) {
  s21::array<TypeParam, 0U> a{};
  EXPECT_EQ(a.size(), 0);
}

TYPED_TEST(ArrayMaxSizeTest, initializer_list) {
  s21::array<TypeParam, 0U> tmp_1({});
  EXPECT_EQ(tmp_1.size(), 0);
  s21::array<TypeParam, 1U> tmp_2({TypeParam(1)});
  EXPECT_EQ(tmp_2.size(), 1);
  s21::array<TypeParam, 3U> tmp_3({TypeParam(1), TypeParam(2), TypeParam(3)});
  EXPECT_EQ(tmp_3.size(), 3);
}

TYPED_TEST(ArrayMaxSizeTest, other_construct) {
  s21::array<TypeParam, 1U> tmp_1({TypeParam(1)});
  EXPECT_EQ(tmp_1.size(), 1);
  s21::array<TypeParam, 1U> tmp_2{tmp_1};
  EXPECT_EQ(tmp_2.size(), 1);
  s21::array<TypeParam, 1U> tmp_3{std::move(tmp_2)};
  EXPECT_EQ(tmp_3.size(), 1);
  s21::array<TypeParam, 1U> tmp_4{{TypeParam(3)}};
  tmp_4 = std::move(tmp_3);
  EXPECT_EQ(tmp_4.size(), 1);
}
