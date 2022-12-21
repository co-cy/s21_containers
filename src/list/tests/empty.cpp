//
// Created by Nana Daughterless on 11/15/22.
//

#include "gtest/gtest.h"
#include "list/list.h"

template <typename T>
struct ListEmptyTest : public testing::Test {
  using List = s21::list<T>;
};

using ListEmptyTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListEmptyTest, ListEmptyTypes);

TYPED_TEST(ListEmptyTest, empty_list) {
  using List = typename TestFixture::List;
  EXPECT_TRUE(List().empty());
}

TYPED_TEST(ListEmptyTest, not_empty_list) {
  using List = typename TestFixture::List;
  EXPECT_TRUE(List(0).empty());
  EXPECT_TRUE(List({}).empty());
  EXPECT_FALSE(List(4).empty());
  EXPECT_FALSE(List({TypeParam()}).empty());
}

TYPED_TEST(ListEmptyTest, cleared_list) {
  using List = typename TestFixture::List;
  List a = List(0U);
  a.clear();
  ASSERT_TRUE(a.empty());

  a = List({});
  a.clear();
  ASSERT_TRUE(a.empty());

  a = List(4U);
  a.clear();
  ASSERT_TRUE(a.empty());

  a = List({TypeParam(), TypeParam(), TypeParam()});
  a.clear();
  ASSERT_TRUE(a.empty());
}
