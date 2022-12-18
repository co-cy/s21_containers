//
// Created by co_cy on 22.11.22.
//

#include <gtest/gtest.h>

#include "queue/queue.h"

template <typename T>
struct QueueConstructorTest : public testing::Test {
  using Queue = s21::queue<T>;
};

using QueueConstructorTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(QueueConstructorTest, QueueConstructorTypes);

TYPED_TEST(QueueConstructorTest, empty) {
  using queue = typename TestFixture::Queue;
  ASSERT_NO_THROW(queue());
}

TYPED_TEST(QueueConstructorTest, size_n) {
  using queue = typename TestFixture::Queue;
  ASSERT_NO_THROW(queue(0));
  ASSERT_NO_THROW(queue(1));
  ASSERT_NO_THROW(queue(8));
}

TYPED_TEST(QueueConstructorTest, initializer_list) {
  using queue = typename TestFixture::Queue;
  ASSERT_NO_THROW(queue({}));
  ASSERT_NO_THROW(queue({TypeParam()}));
  ASSERT_NO_THROW(queue({TypeParam(), TypeParam(), TypeParam()}));
}
