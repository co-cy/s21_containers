//
// Created by co_cy on 22.11.22.
//

#include <gtest/gtest.h>

#include "vector/vector.h"

template <typename T>
struct VectorConstructorTest : public testing::Test {
  using Vector = s21::vector<T>;
};

using VectorConstructTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(VectorConstructorTest, VectorConstructTypes);

TYPED_TEST(VectorConstructorTest, empty) {
  using Vector = typename TestFixture::Vector;
  ASSERT_NO_THROW(Vector());
}

TYPED_TEST(VectorConstructorTest, size_n) {
  using Vector = typename TestFixture::Vector;
  ASSERT_NO_THROW(Vector(0));
  ASSERT_NO_THROW(Vector(1));
  ASSERT_NO_THROW(Vector(8));
}

TYPED_TEST(VectorConstructorTest, initializer_list) {
  using Vector = typename TestFixture::Vector;
  ASSERT_NO_THROW(Vector({}));
  ASSERT_NO_THROW(Vector({TypeParam()}));
  ASSERT_NO_THROW(Vector({TypeParam(), TypeParam(), TypeParam()}));
}
