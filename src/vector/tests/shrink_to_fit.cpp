//
// Created by co_cy on 04.12.22.
//

#include <gtest/gtest.h>

#include "vector/vector.h"

template <typename T>
struct VectorShrinkTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorShrinkTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorShrinkTest, VectorShrinkTypes);

TYPED_TEST(VectorShrinkTest, empty) {
  using Vector = typename TestFixture::Vector;
  Vector a{};
  EXPECT_NO_THROW(a.shrink_to_fit());

  EXPECT_DOUBLE_EQ(a.capacity(), 0);
}

TYPED_TEST(VectorShrinkTest, size_n) {
  using Vector = typename TestFixture::Vector;

  Vector a(1U);
  a.reserve(100U);
  EXPECT_NO_THROW(a.shrink_to_fit());
  EXPECT_DOUBLE_EQ(a.capacity(), 1);

  Vector b(8U);
  b.reserve(16U);
  EXPECT_NO_THROW(b.shrink_to_fit());
  EXPECT_DOUBLE_EQ(b.capacity(), 8);
}

TYPED_TEST(VectorShrinkTest, initializer_list) {
  using Vector = typename TestFixture::Vector;
  EXPECT_DOUBLE_EQ(Vector({}).capacity(), 0);

  Vector a{{TypeParam()}};
  a.reserve(2U);
  EXPECT_NO_THROW(a.shrink_to_fit());
  EXPECT_DOUBLE_EQ(a.capacity(), 1);

  Vector b{{TypeParam(), TypeParam(), TypeParam()}};
  b.reserve(6U);
  EXPECT_NO_THROW(b.shrink_to_fit());
  EXPECT_DOUBLE_EQ(b.capacity(), 3);
}