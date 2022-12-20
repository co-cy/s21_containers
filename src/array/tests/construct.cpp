//
// Created by co_cy on 22.11.22.
//

#include <gtest/gtest.h>

#include "array/array.h"

template <class T>
struct ArrayConstructorTest : public testing::Test {};

using ArrayConstructorTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ArrayConstructorTest, ArrayConstructorTypes);

TYPED_TEST(ArrayConstructorTest, empty) { s21::array<TypeParam, 0U>(); }

TYPED_TEST(ArrayConstructorTest, initializer_list) {
  s21::array<TypeParam, 0U> tmp_1({});
  s21::array<TypeParam, 1U> tmp_2({TypeParam(1)});
  s21::array<TypeParam, 3U> tmp_3({TypeParam(1), TypeParam(2), TypeParam(3)});

  ASSERT_ANY_THROW((s21::array<TypeParam, 0U>{{TypeParam(1)}}));
}

TYPED_TEST(ArrayConstructorTest, other_construct) {
  s21::array<TypeParam, 1U> tmp_1({TypeParam(1)});
  s21::array<TypeParam, 1U> tmp_2{tmp_1};
  s21::array<TypeParam, 1U> tmp_3{std::move(tmp_2)};
  s21::array<TypeParam, 1U> tmp_4{{TypeParam(3)}};
  tmp_4 = std::move(tmp_3);
}
