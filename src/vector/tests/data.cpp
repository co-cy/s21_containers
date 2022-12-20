//
// Created by co_cy on 04.12.22.
//

#include <gtest/gtest.h>

#include "vector/vector.h"

template <typename T>
struct VectorDataTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorDataTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorDataTest, VectorDataTypes);

TYPED_TEST(VectorDataTest, one_item) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(11);
  Vector vector({kValue});

  EXPECT_EQ(vector.data(), vector.begin());
  EXPECT_DOUBLE_EQ(*(vector.data()), kValue);
}

TYPED_TEST(VectorDataTest, many_item) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(33);
  Vector vector({TypeParam(), TypeParam(), kValue, TypeParam()});

  EXPECT_EQ(vector.data(), vector.begin());
  EXPECT_DOUBLE_EQ(*(vector.data() + 2), kValue);
}

TYPED_TEST(VectorDataTest, many_item_first) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(10);
  Vector vector({kValue, TypeParam(), TypeParam(), TypeParam()});

  EXPECT_EQ(vector.data(), vector.begin());

  EXPECT_DOUBLE_EQ(*(vector.data()), kValue);
  EXPECT_NO_THROW((void)*(vector.data() + 1));
  EXPECT_NO_THROW((void)*(vector.data() + 2));
  EXPECT_NO_THROW((void)*(vector.data() + 3));
}

TYPED_TEST(VectorDataTest, many_item_last) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(19);
  Vector vector({TypeParam(), TypeParam(), TypeParam(), kValue});

  EXPECT_EQ(vector.data(), vector.begin());

  EXPECT_NO_THROW((void)*(vector.data()));
  EXPECT_NO_THROW((void)*(vector.data() + 1));
  EXPECT_NO_THROW((void)*(vector.data() + 2));
  EXPECT_DOUBLE_EQ(*(vector.data() + 3), kValue);
}
