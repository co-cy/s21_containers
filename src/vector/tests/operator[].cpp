//
// Created by co_cy on 23.11.22.
//

#include <gtest/gtest.h>

#include "vector/vector.h"

template <typename T>
struct VectorOperatorGetTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorOperatorGetTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorOperatorGetTest, VectorOperatorGetTypes);

TYPED_TEST(VectorOperatorGetTest, one_item) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(11);
  Vector vector({kValue});

  EXPECT_DOUBLE_EQ(vector[0], kValue);
}

TYPED_TEST(VectorOperatorGetTest, many_item) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(33);
  Vector vector({TypeParam(), TypeParam(), kValue, TypeParam()});

  EXPECT_NO_THROW((void)vector[0]);
  EXPECT_NO_THROW((void)vector[1]);
  EXPECT_DOUBLE_EQ(vector[2], kValue);
  EXPECT_NO_THROW((void)vector[3]);
}

TYPED_TEST(VectorOperatorGetTest, many_item_first) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(10);
  Vector vector({kValue, TypeParam(), TypeParam(), TypeParam()});

  EXPECT_DOUBLE_EQ(vector[0], kValue);
  EXPECT_NO_THROW((void)vector[1]);
  EXPECT_NO_THROW((void)vector[2]);
  EXPECT_NO_THROW((void)vector[3]);
}

TYPED_TEST(VectorOperatorGetTest, many_item_last) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(19);
  Vector vector({TypeParam(), TypeParam(), TypeParam(), kValue});

  EXPECT_NO_THROW((void)vector[0]);
  EXPECT_NO_THROW((void)vector[1]);
  EXPECT_NO_THROW((void)vector[2]);
  EXPECT_DOUBLE_EQ(vector[3], kValue);
}
