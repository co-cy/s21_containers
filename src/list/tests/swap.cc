//
// Created by co_cy on 16.11.22.
//

#include <gtest/gtest.h>

#include "list/list.h"

template <typename T>
struct ListSwapTest : public testing::Test {
  using List = s21::list<T>;
};

using ListSwapTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListSwapTest, ListSwapTypes);

TYPED_TEST(ListSwapTest, empty) {
  using List = typename TestFixture::List;
  List a{};
  List b{};

  EXPECT_NO_THROW(a.swap(b));
  EXPECT_EQ(a.size(), 0);
  EXPECT_EQ(b.size(), 0);
  EXPECT_EQ(a.begin(), a.end());
  EXPECT_EQ(b.begin(), b.end());
}

TYPED_TEST(ListSwapTest, one_item) {
  using List = typename TestFixture::List;
  List a(1);
  List b(1);

  EXPECT_NO_THROW(a.swap(b));
  EXPECT_EQ(a.size(), 1);
  EXPECT_EQ(b.size(), 1);
  EXPECT_NE(a.begin(), a.end());
  EXPECT_NE(b.begin(), b.end());
}

TYPED_TEST(ListSwapTest, many_item) {
  using List = typename TestFixture::List;
  List a(8);
  List b(16);

  EXPECT_NO_THROW(a.swap(b));
  EXPECT_EQ(a.size(), 16);
  EXPECT_EQ(b.size(), 8);
  EXPECT_NE(a.begin(), a.end());
  EXPECT_NE(b.begin(), b.end());
}
