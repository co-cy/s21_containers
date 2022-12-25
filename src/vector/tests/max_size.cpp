//
// Created by co_cy on 04.12.22.
//

#include <gtest/gtest.h>

#include <list>

#include "vector/vector.h"

template <typename T>
struct VectorMaxSizeTest : public testing::Test {
  using Vector = s21::vector<T>;
  using SVector = std::vector<T>;
};

using VectorMaxSizeTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorMaxSizeTest, VectorMaxSizeTypes);

TYPED_TEST(VectorMaxSizeTest, empty_list) {
  using Vector = typename TestFixture::Vector;
  using SVector = typename TestFixture::SVector;

  EXPECT_EQ(Vector().max_size(), SVector().max_size());
}

TYPED_TEST(VectorMaxSizeTest, size_n_list) {
  using Vector = typename TestFixture::Vector;
  using SVector = typename TestFixture::SVector;

  EXPECT_EQ(Vector(11).max_size(), SVector(11).max_size());
}
