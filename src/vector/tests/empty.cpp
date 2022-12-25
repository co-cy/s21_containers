//
// Created by co_cy on 22.11.22.
//

#include <gtest/gtest.h>

#include "vector/vector.h"

template <typename T>
struct VectorEmptyTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorEmptyTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorEmptyTest, VectorEmptyTypes);

TYPED_TEST(VectorEmptyTest, empty) {
  using Vector = typename TestFixture::Vector;
  Vector a{};

  EXPECT_TRUE(a.empty());
}

TYPED_TEST(VectorEmptyTest, size_n) {
  using Vector = typename TestFixture::Vector;
  Vector a(0U);
  EXPECT_TRUE(a.empty());
  Vector b(1U);
  EXPECT_FALSE(b.empty());
  Vector c(8U);
  EXPECT_FALSE(c.empty());
}

TYPED_TEST(VectorEmptyTest, initializer_list) {
  using Vector = typename TestFixture::Vector;
  Vector a({});
  EXPECT_TRUE(a.empty());

  Vector b({TypeParam()});
  EXPECT_FALSE(b.empty());

  Vector c({TypeParam(), TypeParam(), TypeParam()});
  EXPECT_FALSE(c.empty());
}
