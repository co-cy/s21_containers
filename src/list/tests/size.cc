//
// Created by Nana Daughterless on 11/15/22.
//

#include "gtest/gtest.h"
#include "list/list.h"

template <typename T>
struct ListSizeTest : public testing::Test {
  using List = s21::list<T>;
};

using ListSizeTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListSizeTest, ListSizeTypes);

TYPED_TEST(ListSizeTest, empty) {
  using List = typename TestFixture::List;
  EXPECT_EQ(List().size(), 0);
}

TYPED_TEST(ListSizeTest, size_n) {
  using List = typename TestFixture::List;
  EXPECT_EQ(List(0).size(), 0);
  EXPECT_EQ(List(1).size(), 1);
  EXPECT_EQ(List(8).size(), 8);
}

TYPED_TEST(ListSizeTest, initializer_list) {
  using List = typename TestFixture::List;
  EXPECT_EQ(List({}).size(), 0);
  EXPECT_EQ(List({TypeParam()}).size(), 1);
  EXPECT_EQ(List({TypeParam(), TypeParam(), TypeParam()}).size(), 3);
}
