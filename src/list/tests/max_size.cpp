//
// Created by Nana Daughterless on 11/15/22.
//

#include <gtest/gtest.h>

#include <list>

#include "list/list.h"

template <typename T>
struct ListMaxSizeTest : public testing::Test {
  using List = s21::list<T>;
  using SList = std::list<T>;
};

using ListMaxSizeTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListMaxSizeTest, ListMaxSizeTypes);

TYPED_TEST(ListMaxSizeTest, empty_list) {
  using List = typename TestFixture::List;
  using SList = typename TestFixture::SList;

  EXPECT_EQ(List().max_size(), SList().max_size());
}

TYPED_TEST(ListMaxSizeTest, size_n_list) {
  using List = typename TestFixture::List;
  using SList = typename TestFixture::SList;

  EXPECT_EQ(List(11).max_size(), SList(11).max_size());
}
