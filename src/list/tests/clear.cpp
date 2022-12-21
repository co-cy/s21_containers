//
// Created by co_cy on 16.11.22.
//

#include "gtest/gtest.h"
#include "list/list.h"

template <typename T>
struct ListClearTest : public testing::Test {
  using List = s21::list<T>;
};

using ListClearTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListClearTest, ListClearTypes);

TYPED_TEST(ListClearTest, empty_list) {
  using List = typename TestFixture::List;
  List a{};
  EXPECT_NO_THROW(a.clear());
  EXPECT_EQ(a.size(), 0);
  EXPECT_TRUE(a.begin() == a.end());
}

TYPED_TEST(ListClearTest, size_n_list) {
  using List = typename TestFixture::List;
  List a(0U);
  EXPECT_NO_THROW(a.clear());
  EXPECT_EQ(a.size(), 0);
  EXPECT_TRUE(a.begin() == a.end());

  a = List(4U);
  EXPECT_NO_THROW(a.clear());
  EXPECT_EQ(a.size(), 0);
  EXPECT_TRUE(a.begin() == a.end());

  a = List(16U);
  EXPECT_NO_THROW(a.clear());
  EXPECT_EQ(a.size(), 0);
  EXPECT_TRUE(a.begin() == a.end());
}
