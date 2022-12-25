//
// Created by co_cy on 21.12.22.
//
#include "gtest/gtest.h"
#include "list/list.h"

template <typename T>
struct ListSpliceTest : public testing::Test {
  using List = s21::list<T>;
};

using ListConstructTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListSpliceTest, ListConstructTypes);

TYPED_TEST(ListSpliceTest, empty) {
  using List = typename TestFixture::List;

  List a{};
  List b{};

  EXPECT_NO_THROW(a.splice(a.begin(), b));
  EXPECT_EQ(a.size(), 0);
  EXPECT_EQ(b.size(), 0);

  EXPECT_NO_THROW(a.splice(a.end(), b));
  EXPECT_EQ(a.size(), 0);
  EXPECT_EQ(b.size(), 0);
}

TYPED_TEST(ListSpliceTest, size_0_1) {
  using List = typename TestFixture::List;
  TypeParam value(1);

  List a{};
  List b{{value}};

  EXPECT_NO_THROW(a.splice(a.end(), b));
  EXPECT_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.front(), value);

  EXPECT_EQ(b.size(), 0);
}

TYPED_TEST(ListSpliceTest, size_1_0) {
  using List = typename TestFixture::List;
  TypeParam value(1);

  List a{{value}};
  List b{};

  EXPECT_NO_THROW(a.splice(a.begin(), b));
  EXPECT_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.front(), value);

  EXPECT_EQ(b.size(), 0);

  EXPECT_NO_THROW(a.splice(a.end(), b));
  EXPECT_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.front(), value);

  EXPECT_EQ(b.size(), 0);
}

TYPED_TEST(ListSpliceTest, size_1_1) {
  using List = typename TestFixture::List;
  TypeParam value_1(1);
  TypeParam value_2(2);

  List a{{value_1}};
  List b{{value_2}};

  EXPECT_NO_THROW(a.splice(a.begin(), b));
  EXPECT_EQ(a.size(), 2);
  EXPECT_DOUBLE_EQ(a.front(), value_2);
  EXPECT_DOUBLE_EQ(*(a.begin() + 1), value_1);

  EXPECT_EQ(b.size(), 0);
}

TYPED_TEST(ListSpliceTest, size_0_3) {
  using List = typename TestFixture::List;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  List a{};
  List b{{value_1, value_2, value_3}};

  EXPECT_NO_THROW(a.splice(a.begin(), b));
  EXPECT_EQ(a.size(), 3);
  EXPECT_DOUBLE_EQ(a.front(), value_1);
  EXPECT_DOUBLE_EQ(*(a.begin() + 1), value_2);
  EXPECT_DOUBLE_EQ(*(a.begin() + 2), value_3);

  EXPECT_EQ(b.size(), 0);
}

TYPED_TEST(ListSpliceTest, size_3_3) {
  using List = typename TestFixture::List;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);
  TypeParam value_4(4);
  TypeParam value_5(5);
  TypeParam value_6(6);

  List a{{value_1, value_3, value_5}};
  List b{{value_2, value_4, value_6}};

  EXPECT_NO_THROW(a.splice(a.begin() + 2, b));
  EXPECT_EQ(a.size(), 6);
  EXPECT_DOUBLE_EQ(a.front(), value_1);
  EXPECT_DOUBLE_EQ(*(a.begin() + 1), value_3);
  EXPECT_DOUBLE_EQ(*(a.begin() + 2), value_2);
  EXPECT_DOUBLE_EQ(*(a.begin() + 3), value_4);
  EXPECT_DOUBLE_EQ(*(a.begin() + 4), value_6);
  EXPECT_DOUBLE_EQ(*(a.begin() + 5), value_5);

  EXPECT_EQ(b.size(), 0);
}

TYPED_TEST(ListSpliceTest, size_3_2) {
  using List = typename TestFixture::List;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);
  TypeParam value_4(4);
  TypeParam value_5(5);

  List a{{value_1, value_3, value_5}};
  List b{{value_2, value_4}};

  EXPECT_NO_THROW(a.splice(a.begin() + 1, b));
  EXPECT_EQ(a.size(), 5);
  EXPECT_DOUBLE_EQ(a.front(), value_1);
  EXPECT_DOUBLE_EQ(*(a.begin() + 1), value_2);
  EXPECT_DOUBLE_EQ(*(a.begin() + 2), value_4);
  EXPECT_DOUBLE_EQ(*(a.begin() + 3), value_3);
  EXPECT_DOUBLE_EQ(*(a.begin() + 4), value_5);

  EXPECT_EQ(b.size(), 0);
}