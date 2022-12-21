//
// Created by co_cy on 22.11.22.
//

#include "gtest/gtest.h"
#include "queue/queue.h"

template <typename T>
struct QueueBackTest : public testing::Test {
  using Queue = s21::queue<T>;
};

using QueueBackTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(QueueBackTest, QueueBackTypes);

TYPED_TEST(QueueBackTest, size_1) {
  using Queue = typename TestFixture::Queue;
  TypeParam value(88);
  Queue a{{value}};

  EXPECT_DOUBLE_EQ(a.back(), value);
}

TYPED_TEST(QueueBackTest, size_2) {
  using Queue = typename TestFixture::Queue;
  TypeParam value(88);
  Queue a{{TypeParam(1), value}};

  EXPECT_DOUBLE_EQ(a.back(), value);
}

TYPED_TEST(QueueBackTest, size_3) {
  using Queue = typename TestFixture::Queue;
  TypeParam value(88);
  Queue a{{TypeParam(1), TypeParam(2), value}};

  EXPECT_DOUBLE_EQ(a.back(), value);
}
