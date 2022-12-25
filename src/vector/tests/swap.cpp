//
// Created by co_cy on 18.12.22.
//

#include <gtest/gtest.h>

#include "vector/vector.h"

template <typename T>
struct VectorSwapTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorSwapTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorSwapTest, VectorSwapTypes);

TYPED_TEST(VectorSwapTest, empty) {
  using Vector = typename TestFixture::Vector;
  Vector a{}, b{};
  EXPECT_NO_THROW(a.swap(b));
}

TYPED_TEST(VectorSwapTest, size_0) {
  using Vector = typename TestFixture::Vector;
  Vector a(0U), b(0U);
  EXPECT_NO_THROW(a.swap(b));
}

TYPED_TEST(VectorSwapTest, size_1) {
  using Vector = typename TestFixture::Vector;
  Vector a(1), b(1);
  EXPECT_NO_THROW(a.swap(b));
}

TYPED_TEST(VectorSwapTest, size_8) {
  using Vector = typename TestFixture::Vector;
  Vector a(4), b(8);
  EXPECT_NO_THROW(a.swap(b));

  EXPECT_EQ(a.size(), 8);
  EXPECT_EQ(b.size(), 4);
}

TYPED_TEST(VectorSwapTest, initializer_list) {
  using Vector = typename TestFixture::Vector;
  TypeParam value(14);

  Vector a{}, b{{value}};

  EXPECT_NO_THROW(b.swap(a));

  EXPECT_EQ(a.size(), 1);
  EXPECT_EQ(b.size(), 0);

  EXPECT_DOUBLE_EQ(a.front(), value);
  EXPECT_EQ(b.begin(), b.end());
}
