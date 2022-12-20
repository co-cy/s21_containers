//
// Created by co_cy on 20.12.22.
//

#include <gtest/gtest.h>

#include "vector/vector.h"

template <typename T>
struct VectorEmplaceBackTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorEmplaceBackTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorEmplaceBackTest, VectorEmplaceBackTypes);

TYPED_TEST(VectorEmplaceBackTest, empty) {
  using Vector = typename TestFixture::Vector;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  Vector a{};

  EXPECT_NO_THROW((void)a.emplace_back(value_1));
  EXPECT_NO_THROW((void)a.emplace_back(value_2, value_3));

  EXPECT_DOUBLE_EQ(a[0], value_1);
  EXPECT_DOUBLE_EQ(a[1], value_2);
  EXPECT_DOUBLE_EQ(a[2], value_3);
}

TYPED_TEST(VectorEmplaceBackTest, size_n) {
  using Vector = typename TestFixture::Vector;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  Vector a(0);
  EXPECT_NO_THROW(a.emplace_back(value_1));
  EXPECT_NO_THROW(a.emplace_back(value_2, value_3));
  EXPECT_DOUBLE_EQ(a[0], value_1);
  EXPECT_DOUBLE_EQ(a[1], value_2);
  EXPECT_DOUBLE_EQ(a[2], value_3);

  Vector b(1);
  EXPECT_NO_THROW(b.emplace_back(value_1, value_2));
  EXPECT_NO_THROW(b.emplace_back(value_3));
  EXPECT_DOUBLE_EQ(b[1], value_1);
  EXPECT_DOUBLE_EQ(b[2], value_2);
  EXPECT_DOUBLE_EQ(b[3], value_3);

  Vector c(8);
  EXPECT_NO_THROW(c.emplace_back(value_1));
  EXPECT_NO_THROW(c.emplace_back(value_2, value_3));
  EXPECT_DOUBLE_EQ(c[8], value_1);
  EXPECT_DOUBLE_EQ(c[9], value_2);
  EXPECT_DOUBLE_EQ(c[10], value_3);
}
