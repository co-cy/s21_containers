//
// Created by co_cy on 22.11.22.
//

#include <gtest/gtest.h>

#include "array/array.h"

template <class T>
struct ArrayEmptyTest : public testing::Test {};

using ArrayEmptyTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ArrayEmptyTest, ArrayEmptyTypes);

TYPED_TEST(ArrayEmptyTest, empty) {
  s21::array<TypeParam, 0U> a{};
  EXPECT_TRUE(a.empty());
}

TYPED_TEST(ArrayEmptyTest, initializer_list) {
  s21::array<TypeParam, 0U> tmp_1({});
  EXPECT_TRUE(tmp_1.empty());
  s21::array<TypeParam, 1U> tmp_2({TypeParam(1)});
  EXPECT_FALSE(tmp_2.empty());
  s21::array<TypeParam, 3U> tmp_3({TypeParam(1), TypeParam(2), TypeParam(3)});
  EXPECT_FALSE(tmp_3.empty());
}

TYPED_TEST(ArrayEmptyTest, other_construct) {
  s21::array<TypeParam, 1U> tmp_1({TypeParam(1)});
  EXPECT_FALSE(tmp_1.empty());
  s21::array<TypeParam, 1U> tmp_2{tmp_1};
  EXPECT_FALSE(tmp_2.empty());
  s21::array<TypeParam, 1U> tmp_3{std::move(tmp_2)};
  EXPECT_FALSE(tmp_3.empty());
  s21::array<TypeParam, 1U> tmp_4{{TypeParam(3)}};
  tmp_4 = std::move(tmp_3);
  EXPECT_FALSE(tmp_4.empty());
}
