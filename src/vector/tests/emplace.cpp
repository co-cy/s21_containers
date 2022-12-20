//
// Created by co_cy on 20.12.22.
//

#include <gtest/gtest.h>

#include "vector/vector.h"

template <typename T>
struct VectorEmplaceTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorEmplaceTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorEmplaceTest, VectorEmplaceTypes);

TYPED_TEST(VectorEmplaceTest, empty) {
  using Vector = typename TestFixture::Vector;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  Vector a{};

  EXPECT_NO_THROW((void)a.emplace(a.begin(), value_1));
  EXPECT_NO_THROW((void)a.emplace(a.end(), value_2, value_3));

  EXPECT_DOUBLE_EQ(a[0], value_1);
  EXPECT_DOUBLE_EQ(a[1], value_2);
  EXPECT_DOUBLE_EQ(a[2], value_3);
}

TYPED_TEST(VectorEmplaceTest, size_n) {
  using Vector = typename TestFixture::Vector;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  Vector a(0);
  EXPECT_NO_THROW(a.emplace(a.begin(), value_1, value_2));
  EXPECT_NO_THROW(a.emplace(a.end(), value_3));
  EXPECT_DOUBLE_EQ(a[0], value_1);
  EXPECT_DOUBLE_EQ(a[1], value_2);
  EXPECT_DOUBLE_EQ(a[2], value_3);

  Vector b(1);
  EXPECT_NO_THROW(b.emplace(b.begin(), value_1, value_2));
  EXPECT_NO_THROW(b.emplace(b.end(), value_3));
  EXPECT_DOUBLE_EQ(b[0], value_1);
  EXPECT_DOUBLE_EQ(b[1], value_2);
  EXPECT_DOUBLE_EQ(b[3], value_3);

  Vector c(8);
  EXPECT_NO_THROW(c.emplace(c.begin() + 4, value_1, value_2));
  EXPECT_NO_THROW(c.emplace(c.begin(), value_3));
  EXPECT_DOUBLE_EQ(c[5], value_1);
  EXPECT_DOUBLE_EQ(c[6], value_2);
  EXPECT_DOUBLE_EQ(c[0], value_3);
}
