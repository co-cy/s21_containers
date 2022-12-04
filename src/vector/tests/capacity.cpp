//
// Created by co_cy on 04.12.22.
//
#include <gtest/gtest.h>

#include "vector/vector.h"

template <typename T>
struct VectorCapacityTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorCapacityTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorCapacityTest, VectorCapacityTypes);

TYPED_TEST(VectorCapacityTest, empty) {
  using Vector = typename TestFixture::Vector;
  EXPECT_DOUBLE_EQ(Vector().capacity(), 0);
}

TYPED_TEST(VectorCapacityTest, size_n) {
  using Vector = typename TestFixture::Vector;
  EXPECT_DOUBLE_EQ(Vector(0).capacity(), 0);
  EXPECT_DOUBLE_EQ(Vector(1).capacity(), 1);
  EXPECT_DOUBLE_EQ(Vector(8).capacity(), 8);
}

TYPED_TEST(VectorCapacityTest, initializer_list) {
  using Vector = typename TestFixture::Vector;
  EXPECT_DOUBLE_EQ(Vector({}).capacity(), 0);
  EXPECT_DOUBLE_EQ(Vector({TypeParam()}).capacity(), 1);
  EXPECT_DOUBLE_EQ(Vector({TypeParam(), TypeParam(), TypeParam()}).capacity(),
                   3);
}