//
// Created by co_cy on 21.11.22.
//

#include "gtest/gtest.h"
#include "list/list.h"

template <typename T>
struct ListInsertTest : public testing::Test {
  using List = s21::list<T>;
};

using ListInsertTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListInsertTest, ListInsertTypes);

TYPED_TEST(ListInsertTest, empty) {
  using List = typename TestFixture::List;
  List a{};
  typename List::iterator iter;
  const TypeParam kValue(16);

  EXPECT_NO_THROW(iter = a.insert(a.begin(), kValue));
  EXPECT_DOUBLE_EQ(*iter, kValue);
  EXPECT_DOUBLE_EQ(*a.begin(), kValue);
  EXPECT_EQ(a.size(), 1);
}

TYPED_TEST(ListInsertTest, one_item) {
  using List = typename TestFixture::List;
  List a({TypeParam()});
  typename List::iterator iter;
  const TypeParam kValue(13);

  EXPECT_NO_THROW(iter = a.insert(a.begin(), kValue));
  EXPECT_DOUBLE_EQ(*iter, kValue);
  EXPECT_DOUBLE_EQ(*a.begin(), kValue);
  EXPECT_EQ(a.size(), 2);
}

TYPED_TEST(ListInsertTest, many_item) {
  using List = typename TestFixture::List;
  List a({TypeParam(), TypeParam(), TypeParam()});
  typename List::iterator iter;
  const TypeParam kValue(13);

  EXPECT_NO_THROW(iter = a.insert(a.begin(), kValue));
  EXPECT_DOUBLE_EQ(*iter, kValue);
  EXPECT_DOUBLE_EQ(*a.begin(), kValue);
  EXPECT_EQ(a.size(), 4);
}

TYPED_TEST(ListInsertTest, empty_insert_end) {
  using List = typename TestFixture::List;
  List a{};
  typename List::iterator iter;
  const TypeParam kValue(16);

  EXPECT_NO_THROW(iter = a.insert(a.end(), kValue));
  EXPECT_DOUBLE_EQ(*iter, kValue);
  EXPECT_DOUBLE_EQ(*(--a.end()), kValue);
  EXPECT_EQ(a.size(), 1);
}

TYPED_TEST(ListInsertTest, one_item_insert_end) {
  using List = typename TestFixture::List;
  List a({TypeParam()});
  typename List::iterator iter;
  const TypeParam kValue(78);

  EXPECT_NO_THROW(iter = a.insert(a.end(), kValue));
  EXPECT_DOUBLE_EQ(*iter, kValue);
  EXPECT_DOUBLE_EQ(*(--a.end()), kValue);
  EXPECT_EQ(a.size(), 2);
}

TYPED_TEST(ListInsertTest, many_item_insert_end) {
  using List = typename TestFixture::List;
  List a({TypeParam(), TypeParam(), TypeParam()});
  typename List::iterator iter;
  const TypeParam kValue(99);

  EXPECT_NO_THROW(iter = a.insert(a.end(), kValue));
  EXPECT_DOUBLE_EQ(*iter, kValue);
  EXPECT_DOUBLE_EQ(*(--a.end()), kValue);
  EXPECT_EQ(a.size(), 4);
}

TYPED_TEST(ListInsertTest, many_item_insert_middle) {
  using List = typename TestFixture::List;
  List a({TypeParam(), TypeParam(), TypeParam()});
  typename List::iterator iter = a.begin();
  typename List::iterator iter_2;
  ++iter;
  ++iter;
  const TypeParam kValue(69);

  EXPECT_NO_THROW(iter_2 = a.insert(iter, kValue));
  EXPECT_DOUBLE_EQ(*(--iter), kValue);
  EXPECT_DOUBLE_EQ(*iter_2, kValue);
  EXPECT_EQ(a.size(), 4);
}
