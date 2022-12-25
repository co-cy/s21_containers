//
// Created by Nana Daughterless on 11/15/22.
//

#include "gtest/gtest.h"
#include "list/list.h"

template <typename T>
struct ListConstructorTest : public testing::Test {
  using List = s21::list<T>;
};

using ListConstructTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(ListConstructorTest, ListConstructTypes);

TYPED_TEST(ListConstructorTest, empty) {
  using List = typename TestFixture::List;
  ASSERT_NO_THROW(List());
}

TYPED_TEST(ListConstructorTest, size_n) {
  using List = typename TestFixture::List;
  ASSERT_NO_THROW(List(0U));
  ASSERT_NO_THROW(List(1U));
  ASSERT_NO_THROW(List(8U));
}

TYPED_TEST(ListConstructorTest, initializer_list) {
  using List = typename TestFixture::List;
  ASSERT_NO_THROW(List({}));
  ASSERT_NO_THROW(List({TypeParam()}));
  ASSERT_NO_THROW(List({TypeParam(), TypeParam(), TypeParam()}));
}

TYPED_TEST(ListConstructorTest, other_constructor) {
  using List = typename TestFixture::List;

  ASSERT_NO_THROW({
    List tmp_1{{TypeParam(1)}};
    List tmp_2(tmp_1);
    List tmp_3(std::move(tmp_2));
    List tmp_4{{TypeParam(4)}};
    tmp_4 = std::move(tmp_3);
  });
}