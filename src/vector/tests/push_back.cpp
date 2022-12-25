//
// Created by co_cy on 04.12.22.
//

#include <gtest/gtest.h>

#include "vector/vector.h"

template <typename T>
struct VectorPushBackTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorPushBackTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorPushBackTest, VectorPushBackTypes);

TYPED_TEST(VectorPushBackTest, empty) {
  using Vector = typename TestFixture::Vector;
  Vector a{};

  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_DOUBLE_EQ(a.capacity(), 0);

  TypeParam value{32};

  ASSERT_NO_THROW(a.push_back(value));
  EXPECT_DOUBLE_EQ(a.back(), value);

  EXPECT_DOUBLE_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.capacity(), 1);
}

TYPED_TEST(VectorPushBackTest, size_n) {
  using Vector = typename TestFixture::Vector;
  Vector a(81);

  EXPECT_DOUBLE_EQ(a.size(), 81);
  EXPECT_DOUBLE_EQ(a.capacity(), 81);

  TypeParam value{34};

  ASSERT_NO_THROW(a.push_back(value));
  EXPECT_DOUBLE_EQ(a.back(), value);

  EXPECT_DOUBLE_EQ(a.size(), 82);
  EXPECT_DOUBLE_EQ(a.capacity(), 162);
}

TYPED_TEST(VectorPushBackTest, size_n_2) {
  using Vector = typename TestFixture::Vector;
  Vector a(3);

  EXPECT_DOUBLE_EQ(a.size(), 3);
  EXPECT_DOUBLE_EQ(a.capacity(), 3);

  TypeParam value{35};

  ASSERT_NO_THROW(a.push_back(value));
  EXPECT_DOUBLE_EQ(a.back(), value);

  EXPECT_DOUBLE_EQ(a.size(), 4);
  EXPECT_DOUBLE_EQ(a.capacity(), 6);
}
