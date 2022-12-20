//
// Created by co_cy on 04.12.22.
//

#include <gtest/gtest.h>

#include "vector/vector.h"

template <typename T>
struct VectorPopBackTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorPopBackTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorPopBackTest, VectorPopBackTypes);

TYPED_TEST(VectorPopBackTest, empty) {
  using Vector = typename TestFixture::Vector;
  Vector a{};

  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_DOUBLE_EQ(a.capacity(), 0);

  ASSERT_NO_THROW(a.pop_back());

  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_DOUBLE_EQ(a.capacity(), 0);
}

TYPED_TEST(VectorPopBackTest, size_n) {
  using Vector = typename TestFixture::Vector;
  Vector a(11);

  EXPECT_DOUBLE_EQ(a.size(), 11);
  EXPECT_DOUBLE_EQ(a.capacity(), 11);

  ASSERT_NO_THROW(a.pop_back());

  EXPECT_DOUBLE_EQ(a.size(), 10);
  EXPECT_DOUBLE_EQ(a.capacity(), 11);
}

TYPED_TEST(VectorPopBackTest, size_n_2) {
  using Vector = typename TestFixture::Vector;
  Vector a(1);

  EXPECT_DOUBLE_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.capacity(), 1);

  ASSERT_NO_THROW(a.pop_back());

  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_DOUBLE_EQ(a.capacity(), 1);
}
