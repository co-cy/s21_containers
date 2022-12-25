//
// Created by co_cy on 16.11.22.
//

#include <gtest/gtest.h>

#include "queue/queue.h"

template <typename T>
struct QueueSwapTest : public testing::Test {
  using Queue = s21::queue<T>;
};

using QueueSwapTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(QueueSwapTest, QueueSwapTypes);

TYPED_TEST(QueueSwapTest, empty) {
  using Queue = typename TestFixture::Queue;
  Queue a{};
  Queue b{};

  EXPECT_NO_THROW(a.swap(b));
  EXPECT_EQ(a.size(), 0);
  EXPECT_EQ(b.size(), 0);
}

TYPED_TEST(QueueSwapTest, one_item) {
  using Queue = typename TestFixture::Queue;
  Queue a(1U);
  Queue b(1U);

  EXPECT_NO_THROW(a.swap(b));
  EXPECT_EQ(a.size(), 1U);
  EXPECT_EQ(b.size(), 1U);
}

TYPED_TEST(QueueSwapTest, many_item) {
  using Queue = typename TestFixture::Queue;
  Queue a(8U);
  Queue b(16U);

  EXPECT_NO_THROW(a.swap(b));
  EXPECT_EQ(a.size(), 16U);
  EXPECT_EQ(b.size(), 8U);
}
