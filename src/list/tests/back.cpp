//
// Created by co_cy on 16.11.22.
//

#include "gtest/gtest.h"
#include "list/list.h"

template <typename T>
struct ListBackTest : public testing::Test {
  using List = s21::list<T>;
};

using ListBackTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListBackTest, ListBackTypes);

TYPED_TEST(ListBackTest, one_item) {
  using List = typename TestFixture::List;
  TypeParam value{110};
  EXPECT_DOUBLE_EQ(List({value}).back(), value);
}

TYPED_TEST(ListBackTest, many_item) {
  using List = typename TestFixture::List;
  TypeParam value{91};
  EXPECT_DOUBLE_EQ(List({TypeParam(), TypeParam(), value}).back(), value);
}
