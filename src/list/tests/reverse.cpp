//
// Created by co_cy on 22.11.22.
//

#include <gtest/gtest.h>

#include "list/list.h"

template <class T>
struct ListReverseTest : public testing::Test {
  using List = s21::list<T>;
};

using ListReverseTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListReverseTest, ListReverseTypes);

TYPED_TEST(ListReverseTest, empty) {
  using List = typename TestFixture::List;
  List a{};

  EXPECT_NO_THROW(a.reverse());
  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_EQ(a.begin(), a.end());
}

TYPED_TEST(ListReverseTest, one_item) {
  using List = typename TestFixture::List;
  List a({TypeParam(1)});

  EXPECT_NO_THROW(a.reverse());
  EXPECT_DOUBLE_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(*a.begin(), TypeParam(1));
  EXPECT_DOUBLE_EQ(*(--a.end()), TypeParam(1));
}

TYPED_TEST(ListReverseTest, many_item) {
  using List = typename TestFixture::List;
  List a({TypeParam(1), TypeParam(2), TypeParam(3), TypeParam(4)});

  EXPECT_NO_THROW(a.reverse());
  EXPECT_DOUBLE_EQ(a.size(), 4);

  EXPECT_DOUBLE_EQ(a.front(), 4);
  EXPECT_DOUBLE_EQ(a.back(), 1);
  EXPECT_DOUBLE_EQ(*(a.begin()), 4);
  EXPECT_DOUBLE_EQ(*(--a.end()), 1);

  int k = 4;
  for (auto iter = a.begin(); iter != a.end(); ++iter, --k) {
    EXPECT_DOUBLE_EQ(*iter, TypeParam(k));
  }
}