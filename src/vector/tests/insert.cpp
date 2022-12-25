//
// Created by co_cy on 04.12.22.
//

#include <gtest/gtest.h>

#include "vector/vector.h"

template <typename T>
struct VectorInsertTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorInsertTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorInsertTest, VectorInsertTypes);

TYPED_TEST(VectorInsertTest, empty) {
  using Vector = typename TestFixture::Vector;
  Vector a{};

  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_DOUBLE_EQ(a.capacity(), 0);

  TypeParam value{13};
  typename Vector::iterator iter = nullptr;

  ASSERT_NO_THROW(iter = a.insert(a.begin(), value));
  EXPECT_EQ(iter, a.begin());
  EXPECT_DOUBLE_EQ(*iter, value);
  EXPECT_DOUBLE_EQ(*iter, a.front());

  EXPECT_DOUBLE_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.capacity(), 1);
  EXPECT_EQ(iter, a.data());
}

TYPED_TEST(VectorInsertTest, size_n) {
  using Vector = typename TestFixture::Vector;
  Vector a(13);

  EXPECT_DOUBLE_EQ(a.size(), 13);
  EXPECT_DOUBLE_EQ(a.capacity(), 13);

  TypeParam value{26};
  typename Vector::iterator iter = nullptr;

  ASSERT_NO_THROW(iter = a.insert(a.begin(), value));
  EXPECT_EQ(iter, a.begin());
  EXPECT_DOUBLE_EQ(*iter, value);
  EXPECT_DOUBLE_EQ(*iter, a.front());

  EXPECT_DOUBLE_EQ(a.size(), 14);
  EXPECT_DOUBLE_EQ(a.capacity(), 26);
  EXPECT_EQ(iter, a.data());
}

TYPED_TEST(VectorInsertTest, initializer_list) {
  using Vector = typename TestFixture::Vector;
  Vector a(13);

  EXPECT_DOUBLE_EQ(a.size(), 13);
  EXPECT_DOUBLE_EQ(a.capacity(), 13);

  TypeParam value{98};
  typename Vector::iterator iter = nullptr;

  ASSERT_NO_THROW(iter = a.insert(a.end(), value));
  EXPECT_DOUBLE_EQ(*iter, value);
  EXPECT_DOUBLE_EQ(*iter, a.back());

  EXPECT_DOUBLE_EQ(a.size(), 14);
  EXPECT_DOUBLE_EQ(a.capacity(), 26);
}
