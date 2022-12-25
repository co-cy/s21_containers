//
// Created by co_cy on 04.12.22.
//

#include <gtest/gtest.h>

#include "vector/vector.h"

template <typename T>
struct VectorEraseTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorEraseTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorEraseTest, VectorEraseTypes);

TYPED_TEST(VectorEraseTest, empty) {
  using Vector = typename TestFixture::Vector;
  Vector vector{};

  EXPECT_EQ(vector.capacity(), 0);
  EXPECT_EQ(vector.size(), 0);

  EXPECT_NO_THROW(vector.erase(vector.begin()));
  EXPECT_NO_THROW(vector.erase(vector.end()));

  EXPECT_EQ(vector.capacity(), 0);
  EXPECT_EQ(vector.size(), 0);
}

TYPED_TEST(VectorEraseTest, one_item_first) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(91);
  Vector vector({kValue});

  EXPECT_EQ(vector.capacity(), 1);
  EXPECT_EQ(vector.size(), 1);

  EXPECT_NO_THROW(vector.erase(vector.begin()));

  EXPECT_EQ(vector.capacity(), 1);
  EXPECT_EQ(vector.size(), 0);
}

TYPED_TEST(VectorEraseTest, one_item_last) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(91);
  Vector vector({kValue});

  EXPECT_EQ(vector.capacity(), 1);
  EXPECT_EQ(vector.size(), 1);

  EXPECT_NO_THROW(vector.erase(vector.end() - 1));

  EXPECT_EQ(vector.capacity(), 1);
  EXPECT_EQ(vector.size(), 0);
}

TYPED_TEST(VectorEraseTest, many_item) {
  using Vector = typename TestFixture::Vector;
  TypeParam const kValue(82);
  Vector vector({TypeParam(), TypeParam(), kValue, TypeParam()});

  EXPECT_EQ(vector.capacity(), 4);
  EXPECT_EQ(vector.size(), 4);

  EXPECT_NO_THROW(vector.erase(vector.begin()));
  EXPECT_NO_THROW(vector.erase(vector.begin()));

  EXPECT_EQ(vector.capacity(), 4);
  EXPECT_EQ(vector.size(), 2);
  EXPECT_DOUBLE_EQ(*(vector.data()), kValue);
}
