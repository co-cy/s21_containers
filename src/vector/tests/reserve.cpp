//
// Created by co_cy on 20.12.22.
//

#include <gtest/gtest.h>

#include "vector/vector.h"

template <typename T>
struct VectorReserveTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorReserveTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorReserveTest, VectorReserveTypes);

TYPED_TEST(VectorReserveTest, empty) {
  using Vector = typename TestFixture::Vector;
  Vector a{};
  EXPECT_EQ(a.capacity(), 0);
  a.reserve(100U);
  EXPECT_EQ(a.capacity(), 100);
}

TYPED_TEST(VectorReserveTest, size_n) {
  using Vector = typename TestFixture::Vector;
  Vector a(0U);
  EXPECT_EQ(a.capacity(), 0);
  a.reserve(1U);
  EXPECT_EQ(a.capacity(), 1);

  Vector b(1U);
  EXPECT_EQ(b.capacity(), 1);
  b.reserve(0U);
  EXPECT_EQ(b.capacity(), 1);
  b.reserve(10U);
  EXPECT_EQ(b.capacity(), 10);

  Vector c(8U);
  EXPECT_EQ(c.capacity(), 8);
  c.reserve(2U);
  EXPECT_EQ(c.capacity(), 8);
}

TYPED_TEST(VectorReserveTest, initializer_list) {
  using Vector = typename TestFixture::Vector;
  Vector a({});
  EXPECT_EQ(a.capacity(), 0);
  a.reserve(0U);
  EXPECT_EQ(a.capacity(), 0);

  Vector b({TypeParam()});
  EXPECT_EQ(b.capacity(), 1);
  b.reserve(1U);
  EXPECT_EQ(b.capacity(), 1);

  Vector c({TypeParam(), TypeParam(), TypeParam()});
  EXPECT_EQ(c.capacity(), 3);
  c.reserve(0U);
  EXPECT_EQ(c.capacity(), 3);
}
