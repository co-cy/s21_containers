//
// Created by co_cy on 23.11.22.
//

#include <gtest/gtest.h>

#include "vector/vector.h"

template <typename T>
struct VectorFrontTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorFrontTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorFrontTest, VectorFrontTypes);

TYPED_TEST(VectorFrontTest, one_item) {
  using Vector = typename TestFixture::Vector;
  TypeParam value(11);
  Vector vector({value});
  EXPECT_DOUBLE_EQ(vector.front(), value);
}

TYPED_TEST(VectorFrontTest, many_item) {
  using Vector = typename TestFixture::Vector;
  TypeParam value(12);
  Vector vector({value, TypeParam(), TypeParam(), TypeParam()});
  EXPECT_DOUBLE_EQ(vector.front(), value);
}
