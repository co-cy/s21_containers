//
// Created by co_cy on 22.11.22.
//

#include <gtest/gtest.h>

#include "queue/queue.h"

template <class T>
struct QueuePopTest : public testing::Test {
  using Queue = s21::queue<T>;
};

using QueuePopTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(QueuePopTest, QueuePopTypes);

TYPED_TEST(QueuePopTest, empty) {
  using Queue = typename TestFixture::Queue;

  Queue a{};
  EXPECT_NO_THROW(a.pop());
}

TYPED_TEST(QueuePopTest, one_item) {
  using Queue = typename TestFixture::Queue;
  TypeParam value_1(1);

  Queue a{{value_1}};
  EXPECT_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.front(), value_1);
  EXPECT_NO_THROW(a.pop());
  EXPECT_EQ(a.size(), 0);
}

TYPED_TEST(QueuePopTest, many_item) {
  using Queue = typename TestFixture::Queue;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  Queue a{{value_1, value_2, value_3}};
  EXPECT_EQ(a.size(), 3);
  EXPECT_DOUBLE_EQ(a.front(), value_1);

  EXPECT_NO_THROW(a.pop());
  EXPECT_EQ(a.size(), 2);
  EXPECT_DOUBLE_EQ(a.front(), value_2);

  EXPECT_NO_THROW(a.pop());
  EXPECT_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.front(), value_3);

  EXPECT_NO_THROW(a.pop());
  EXPECT_EQ(a.size(), 0);
}
