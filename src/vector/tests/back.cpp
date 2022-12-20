//
// Created by co_cy on 23.11.22.
//

#include <gtest/gtest.h>

#include "vector/vector.h"

template <typename T>
struct VectorBackTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorBackTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorBackTest, VectorBackTypes);

TYPED_TEST(VectorBackTest, one_item) {
  using Vector = typename TestFixture::Vector;
  TypeParam value(13);
  Vector vector({value});
  EXPECT_DOUBLE_EQ(vector.back(), value);
}

TYPED_TEST(VectorBackTest, many_item) {
  using Vector = typename TestFixture::Vector;
  TypeParam value(14);
  Vector vector({TypeParam(), TypeParam(), TypeParam(), value});
  EXPECT_DOUBLE_EQ(vector.back(), value);
}