//
// Created by co_cy on 21.11.22.
//

#include "gtest/gtest.h"
#include "list/list.h"

template <typename T>
struct ListEraseTest : public testing::Test {
  using List = s21::list<T>;
};

using ListEraseTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListEraseTest, ListEraseTypes);

TYPED_TEST(ListEraseTest, empty) {
  using List = typename TestFixture::List;
  List a{};
  EXPECT_NO_THROW(a.erase(a.begin()));
  EXPECT_NO_THROW(a.erase(a.end()));
  EXPECT_EQ(a.size(), 0);
}

TYPED_TEST(ListEraseTest, one_item) {
  using List = typename TestFixture::List;
  List a({TypeParam()});

  EXPECT_NO_THROW(a.erase(a.begin()));
  EXPECT_EQ(a.size(), 0);
}

TYPED_TEST(ListEraseTest, many_item_1) {
  using List = typename TestFixture::List;
  List a({TypeParam(), TypeParam(), TypeParam()});

  EXPECT_NO_THROW(a.erase(a.begin()));
  EXPECT_EQ(a.size(), 2);
}

TYPED_TEST(ListEraseTest, many_item_2) {
  using List = typename TestFixture::List;
  TypeParam value(7);
  List a({TypeParam(), TypeParam(), value});
  auto iter = --a.end();
  auto iter_2 = iter;
  --iter_2;

  EXPECT_NO_THROW(a.erase(iter_2));
  EXPECT_EQ(*iter, value);
  EXPECT_EQ(a.size(), 2);
}
