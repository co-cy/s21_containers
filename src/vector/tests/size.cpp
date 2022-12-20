//
// Created by co_cy on 22.11.22.
//

#include <gtest/gtest.h>

#include "vector/vector.h"

template <typename T>
struct VectorSizeTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorSizeTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorSizeTest, VectorSizeTypes);

TYPED_TEST(VectorSizeTest, empty) {
  using Vector = typename TestFixture::Vector;
  Vector a{};

  EXPECT_EQ(a.size(), 0);
}

TYPED_TEST(VectorSizeTest, size_n) {
  using Vector = typename TestFixture::Vector;
  Vector a(0U);
  EXPECT_EQ(a.size(), 0);

  Vector b(1U);
  EXPECT_EQ(b.size(), 1);

  Vector c(8U);
  EXPECT_EQ(c.size(), 8);
}

TYPED_TEST(VectorSizeTest, initializer_list) {
  using Vector = typename TestFixture::Vector;
  Vector a({});
  EXPECT_EQ(a.size(), 0);

  Vector b({TypeParam()});
  EXPECT_EQ(b.size(), 1);

  Vector c({TypeParam(), TypeParam(), TypeParam()});
  EXPECT_EQ(c.size(), 3);
}
