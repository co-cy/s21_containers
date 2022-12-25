//
// Created by co_cy on 22.11.22.
//

#include <gtest/gtest.h>

#include "queue/queue.h"

template <class T>
struct QueuePushTest : public testing::Test {
  using Queue = s21::queue<T>;
};

using QueuePushTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(QueuePushTest, QueuePushTypes);

TYPED_TEST(QueuePushTest, empty) {
  using Queue = typename TestFixture::Queue;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  Queue a{};
  EXPECT_EQ(a.size(), 0);

  EXPECT_NO_THROW(a.push(value_1));
  EXPECT_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.front(), value_1);

  EXPECT_NO_THROW(a.push(value_2));
  EXPECT_EQ(a.size(), 2);
  EXPECT_DOUBLE_EQ(a.back(), value_2);

  EXPECT_NO_THROW(a.push(value_3));
  EXPECT_EQ(a.size(), 3);
  EXPECT_DOUBLE_EQ(a.back(), value_3);
}

TYPED_TEST(QueuePushTest, one_item) {
  using Queue = typename TestFixture::Queue;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  Queue a{{TypeParam()}};
  EXPECT_EQ(a.size(), 1);

  EXPECT_NO_THROW(a.push(value_1));
  EXPECT_EQ(a.size(), 2);
  EXPECT_DOUBLE_EQ(a.back(), value_1);

  EXPECT_NO_THROW(a.push(value_2));
  EXPECT_EQ(a.size(), 3);
  EXPECT_DOUBLE_EQ(a.back(), value_2);

  EXPECT_NO_THROW(a.push(value_3));
  EXPECT_EQ(a.size(), 4);
  EXPECT_DOUBLE_EQ(a.back(), value_3);
}

TYPED_TEST(QueuePushTest, many_item) {
  using Queue = typename TestFixture::Queue;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  Queue a{{TypeParam(), TypeParam(), TypeParam()}};
  EXPECT_EQ(a.size(), 3);

  EXPECT_NO_THROW(a.push(value_1));
  EXPECT_EQ(a.size(), 4);
  EXPECT_DOUBLE_EQ(a.back(), value_1);

  EXPECT_NO_THROW(a.push(value_2));
  EXPECT_EQ(a.size(), 5);
  EXPECT_DOUBLE_EQ(a.back(), value_2);

  EXPECT_NO_THROW(a.push(value_3));
  EXPECT_EQ(a.size(), 6);
  EXPECT_DOUBLE_EQ(a.back(), value_3);
}
