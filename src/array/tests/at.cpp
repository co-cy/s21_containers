//
// Created by co_cy on 20.12.22.
//

#include <gtest/gtest.h>

#include "array/array.h"

template <class T>
struct ArrayAtTest : public testing::Test {};

using ArrayAtTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ArrayAtTest, ArrayAtTypes);

TYPED_TEST(ArrayAtTest, empty) {
  s21::array<TypeParam, 0U> a{};

  EXPECT_ANY_THROW((void)a.at(0));
  EXPECT_ANY_THROW((void)a.at(1));
  EXPECT_ANY_THROW((void)a.at(100));
}

TYPED_TEST(ArrayAtTest, size_1) {
  TypeParam value{99};
  s21::array<TypeParam, 1U> a{{value}};

  EXPECT_DOUBLE_EQ(a.at(0), value);
  EXPECT_ANY_THROW((void)a.at(1));
  EXPECT_ANY_THROW((void)a.at(100));
}

TYPED_TEST(ArrayAtTest, size_3) {
  TypeParam value_1{91};
  TypeParam value_2{92};
  TypeParam value_3{93};
  s21::array<TypeParam, 3U> a{{value_1, value_2, value_3}};

  EXPECT_DOUBLE_EQ(a.at(0), value_1);
  EXPECT_DOUBLE_EQ(a.at(1), value_2);
  EXPECT_DOUBLE_EQ(a.at(2), value_3);
  EXPECT_ANY_THROW((void)a.at(3));
  EXPECT_ANY_THROW((void)a.at(4));
  EXPECT_ANY_THROW((void)a.at(10));
}
