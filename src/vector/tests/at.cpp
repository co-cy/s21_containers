//
// Created by co_cy on 23.11.22.
//

#include <gtest/gtest.h>

#include "vector/vector.h"

template <typename T>
struct VectorAtTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorAtTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorAtTest, VectorAtTypes);

TYPED_TEST(VectorAtTest, empty) {
  using Vector = typename TestFixture::Vector;
  Vector vector{};

  EXPECT_ANY_THROW((void)vector.at(0U));
  EXPECT_ANY_THROW((void)vector.at(1U));
}

TYPED_TEST(VectorAtTest, one_item) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(11);
  Vector vector({kValue});

  EXPECT_DOUBLE_EQ(vector.at(0), kValue);
  EXPECT_ANY_THROW((void)vector.at(1U));
}

TYPED_TEST(VectorAtTest, many_item) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(33);
  Vector vector({TypeParam(), TypeParam(), kValue, TypeParam()});

  EXPECT_NO_THROW((void)vector.at(0));
  EXPECT_NO_THROW((void)vector.at(1));
  EXPECT_DOUBLE_EQ(vector.at(2), kValue);
  EXPECT_NO_THROW((void)vector.at(3));

  EXPECT_ANY_THROW((void)vector.at(4));
  EXPECT_ANY_THROW((void)vector.at(1000000));
}

TYPED_TEST(VectorAtTest, many_item_first) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(10);
  Vector vector({kValue, TypeParam(), TypeParam(), TypeParam()});

  EXPECT_DOUBLE_EQ(vector.at(0), kValue);
  EXPECT_NO_THROW((void)vector.at(1));
  EXPECT_NO_THROW((void)vector.at(2));
  EXPECT_NO_THROW((void)vector.at(3));

  EXPECT_ANY_THROW((void)vector.at(4));
  EXPECT_ANY_THROW((void)vector.at(1000000));
}

TYPED_TEST(VectorAtTest, many_item_last) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(19);
  Vector vector({TypeParam(), TypeParam(), TypeParam(), kValue});

  EXPECT_NO_THROW((void)vector.at(0));
  EXPECT_NO_THROW((void)vector.at(1));
  EXPECT_NO_THROW((void)vector.at(2));
  EXPECT_DOUBLE_EQ(vector.at(3), kValue);

  EXPECT_ANY_THROW((void)vector.at(4));
  EXPECT_ANY_THROW((void)vector.at(1000000));
}
