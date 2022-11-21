//
// Created by co_cy on 16.11.22.
//

#include "gtest/gtest.h"
#include "list/list.h"

template <typename T>
struct ListFrontTest : public testing::Test {
  using List = s21::list<T>;
};

using ListFrontTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListFrontTest, ListFrontTypes);

TYPED_TEST(ListFrontTest, empty_list) {
  using List = typename TestFixture::List;
  EXPECT_NO_THROW((void)List().front());
}

TYPED_TEST(ListFrontTest, one_item) {
  using List = typename TestFixture::List;
  TypeParam value{110};
  EXPECT_DOUBLE_EQ(List({value}).front(), value);
}

TYPED_TEST(ListFrontTest, many_item) {
  using List = typename TestFixture::List;
  TypeParam value{33};
  EXPECT_DOUBLE_EQ(List({value, TypeParam(), TypeParam()}).front(), value);
}
