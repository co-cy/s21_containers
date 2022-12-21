//
// Created by co_cy on 22.11.22.
//

#include "gtest/gtest.h"
#include "queue/queue.h"

template <typename T>
struct QueueFrontTest : public testing::Test {
  using Queue = s21::queue<T>;
};

using QueueFrontTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(QueueFrontTest, QueueFrontTypes);

TYPED_TEST(QueueFrontTest, size_1) {
  using Queue = typename TestFixture::Queue;
  TypeParam value(88);
  Queue a{{value}};

  EXPECT_DOUBLE_EQ(a.front(), value);
}

TYPED_TEST(QueueFrontTest, size_2) {
  using Queue = typename TestFixture::Queue;
  TypeParam value(88);
  Queue a{{value, TypeParam(1)}};

  EXPECT_DOUBLE_EQ(a.front(), value);
}

TYPED_TEST(QueueFrontTest, size_3) {
  using Queue = typename TestFixture::Queue;
  TypeParam value(88);
  Queue a{{value, TypeParam(1), TypeParam(2)}};

  EXPECT_DOUBLE_EQ(a.front(), value);
}
