//
// Created by co_cy on 22.11.22.
//

#include <gtest/gtest.h>

#include <array>

#include "array/array.h"

template <class T>
struct ArraySizeTest : public testing::Test {};

using ArraySizeTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ArraySizeTest, ArraySizeTypes);

TYPED_TEST(ArraySizeTest, empty) {
  s21::array<TypeParam, 0U> a{};
  std::array<TypeParam, 0U> b{};
  EXPECT_EQ(a.max_size(), b.max_size());
}

TYPED_TEST(ArraySizeTest, initializer_list) {
  s21::array<TypeParam, 0U> tmp_1_a({});
  std::array<TypeParam, 0U> tmp_1_b({});
  EXPECT_EQ(tmp_1_a.max_size(), tmp_1_b.max_size());

  s21::array<TypeParam, 1U> tmp_2_a({TypeParam(1)});
  std::array<TypeParam, 1U> tmp_2_b({TypeParam(1)});
  EXPECT_EQ(tmp_2_a.max_size(), tmp_2_b.max_size());

  s21::array<TypeParam, 3U> tmp_3_a({TypeParam(1), TypeParam(2), TypeParam(3)});
  std::array<TypeParam, 3U> tmp_3_b({TypeParam(1), TypeParam(2), TypeParam(3)});
  EXPECT_EQ(tmp_3_a.max_size(), tmp_3_b.max_size());
}

TYPED_TEST(ArraySizeTest, other_construct) {
  s21::array<TypeParam, 1U> tmp_1_a({TypeParam(1)});
  std::array<TypeParam, 1U> tmp_1_b({TypeParam(1)});
  EXPECT_EQ(tmp_1_a.max_size(), tmp_1_b.max_size());

  s21::array<TypeParam, 1U> tmp_2_a{tmp_1_a};
  std::array<TypeParam, 1U> tmp_2_b{tmp_1_b};
  EXPECT_EQ(tmp_2_a.max_size(), tmp_2_b.max_size());

  s21::array<TypeParam, 1U> tmp_3_a{std::move(tmp_2_a)};
  std::array<TypeParam, 1U> tmp_3_b{std::move(tmp_2_b)};
  EXPECT_EQ(tmp_3_a.max_size(), tmp_3_b.max_size());

  s21::array<TypeParam, 1U> tmp_4_a{{TypeParam(3)}};
  tmp_4_a = std::move(tmp_3_a);
  std::array<TypeParam, 1U> tmp_4_b{{TypeParam(3)}};
  tmp_4_b = std::move(tmp_3_b);
  EXPECT_EQ(tmp_4_a.max_size(), tmp_4_b.max_size());
}
