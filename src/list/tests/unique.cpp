//
// Created by co_cy on 22.11.22.
//

#include <gtest/gtest.h>

#include "list/list.h"

template <class T>
struct ListUniqueTest : public testing::Test {
  using List = s21::list<T>;
};

using ListUniqueTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListUniqueTest, ListUniqueTypes);

TYPED_TEST(ListUniqueTest, empty) {
  using List = typename TestFixture::List;
  List a{};

  EXPECT_NO_THROW(a.unique());
  EXPECT_DOUBLE_EQ(a.size(), 0);
  EXPECT_EQ(a.begin(), a.end());
}

TYPED_TEST(ListUniqueTest, one_item) {
  using List = typename TestFixture::List;
  List a({TypeParam(1)});

  EXPECT_NO_THROW(a.unique());
  EXPECT_DOUBLE_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.front(), TypeParam(1));
}

TYPED_TEST(ListUniqueTest, many_item_1) {
  using List = typename TestFixture::List;
  List a({TypeParam(1), TypeParam(1), TypeParam(1)});

  EXPECT_NO_THROW(a.unique());
  EXPECT_DOUBLE_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.front(), TypeParam(1));
}

TYPED_TEST(ListUniqueTest, many_item_2) {
  using List = typename TestFixture::List;
  List a(
      {TypeParam(1), TypeParam(1), TypeParam(2), TypeParam(1), TypeParam(1)});
  TypeParam b[] = {1, 2, 1};

  EXPECT_NO_THROW(a.unique());
  EXPECT_DOUBLE_EQ(a.size(), 3);
  int i = 0;
  for (auto iter = a.begin(); iter != a.end(); ++iter, ++i) {
    EXPECT_DOUBLE_EQ(b[i], *iter);
  }
}

TYPED_TEST(ListUniqueTest, many_item_3) {
  using List = typename TestFixture::List;
  List a(
      {TypeParam(1), TypeParam(2), TypeParam(3), TypeParam(3), TypeParam(3)});
  TypeParam b[] = {1, 2, 3};

  EXPECT_NO_THROW(a.unique());
  EXPECT_DOUBLE_EQ(a.size(), 3);
  int i = 0;
  for (auto iter = a.begin(); iter != a.end(); ++iter, ++i) {
    EXPECT_DOUBLE_EQ(b[i], *iter);
  }
}

TYPED_TEST(ListUniqueTest, many_item_4) {
  using List = typename TestFixture::List;
  List a({TypeParam(1), TypeParam(1), TypeParam(1), TypeParam(2), TypeParam(3),
          TypeParam(3), TypeParam(3)});
  TypeParam b[] = {1, 2, 3};

  EXPECT_NO_THROW(a.unique());
  EXPECT_DOUBLE_EQ(a.size(), 3);
  int i = 0;
  for (auto iter = a.begin(); iter != a.end(); ++iter, ++i) {
    EXPECT_DOUBLE_EQ(b[i], *iter);
  }
}

TYPED_TEST(ListUniqueTest, many_item_5) {
  using List = typename TestFixture::List;
  List a({TypeParam(1), TypeParam(1), TypeParam(1), TypeParam(2), TypeParam(2),
          TypeParam(2), TypeParam(3), TypeParam(3), TypeParam(3)});
  TypeParam b[] = {1, 2, 3};

  EXPECT_NO_THROW(a.unique());
  EXPECT_DOUBLE_EQ(a.size(), 3);
  int i = 0;
  for (auto iter = a.begin(); iter != a.end(); ++iter, ++i) {
    EXPECT_DOUBLE_EQ(b[i], *iter);
  }
}

TYPED_TEST(ListUniqueTest, many_item_6) {
  using List = typename TestFixture::List;
  List a(
      {TypeParam(1), TypeParam(1), TypeParam(1), TypeParam(2), TypeParam(3)});
  TypeParam b[] = {1, 2, 3};

  EXPECT_NO_THROW(a.unique());
  EXPECT_DOUBLE_EQ(a.size(), 3);
  int i = 0;
  for (auto iter = a.begin(); iter != a.end(); ++iter, ++i) {
    EXPECT_DOUBLE_EQ(b[i], *iter);
  }
}

TYPED_TEST(ListUniqueTest, many_item_7) {
  using List = typename TestFixture::List;
  List a({TypeParam(1), TypeParam(2), TypeParam(3)});
  TypeParam b[] = {1, 2, 3};

  EXPECT_NO_THROW(a.unique());
  EXPECT_DOUBLE_EQ(a.size(), 3);
  int i = 0;
  for (auto iter = a.begin(); iter != a.end(); ++iter, ++i) {
    EXPECT_DOUBLE_EQ(b[i], *iter);
  }
}
