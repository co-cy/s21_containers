//
// Created by co_cy on 21.12.22.
//

#include <gtest/gtest.h>

#include "list/list.h"

template <typename T>
struct ListSortTest : public testing::Test {
  using List = s21::list<T>;
};

using ListSortTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListSortTest, ListSortTypes);

TYPED_TEST(ListSortTest, empty) {
  using List = typename TestFixture::List;
  List a{};

  a.sort();
  EXPECT_EQ(a.size(), 0);
}

TYPED_TEST(ListSortTest, size_1) {
  using List = typename TestFixture::List;
  TypeParam value_1(1);

  List a({value_1});
  a.sort();

  EXPECT_DOUBLE_EQ(*(a.begin() + 0), value_1);
  EXPECT_EQ(a.size(), 1);
}

TYPED_TEST(ListSortTest, size_2) {
  using List = typename TestFixture::List;
  TypeParam value_1(1);
  TypeParam value_2(2);

  List a({value_2, value_1});
  a.sort();

  EXPECT_DOUBLE_EQ(*(a.begin() + 0), value_1);
  EXPECT_DOUBLE_EQ(*(a.begin() + 1), value_2);
  EXPECT_EQ(a.size(), 2);
}

TYPED_TEST(ListSortTest, size_10) {
  using List = typename TestFixture::List;

  List a{};
  for (size_t i = 0U; i < 10U; ++i) {
    if (i % 2U == 0U) {
      if (i % 3U == 0U) {
        a.emplace_front(TypeParam(i));
      } else {
        a.emplace_back(TypeParam(i));
      }
    } else {
      if (i % 3U == 0U) {
        a.emplace_back(TypeParam(i));
      } else {
        a.emplace_front(TypeParam(i));
      }
    }
  }
  a.sort();

  size_t i = 0U;
  for (auto iterator = a.begin(); iterator != a.end(); ++iterator) {
    EXPECT_DOUBLE_EQ(iterator.head->value, TypeParam(i++));
  }
}

TYPED_TEST(ListSortTest, size_100) {
  using List = typename TestFixture::List;

  List a{};
  for (size_t i = 0U; i < 100U; ++i) {
    if (i % 2U == 0U) {
      if (i % 3U == 0U) {
        a.emplace_front(TypeParam(i));
      } else {
        a.emplace_back(TypeParam(i));
      }
    } else {
      if (i % 3U == 0U) {
        a.emplace_back(TypeParam(i));
      } else {
        a.emplace_front(TypeParam(i));
      }
    }
  }
  a.sort();

  size_t i = 0U;
  for (auto iterator = a.begin(); iterator != a.end(); ++iterator) {
    EXPECT_DOUBLE_EQ(iterator.head->value, TypeParam(i++));
  }
}