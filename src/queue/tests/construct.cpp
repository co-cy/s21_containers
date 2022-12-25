//
// Created by co_cy on 22.11.22.
//

#include "gtest/gtest.h"
#include "queue/queue.h"

template <typename T>
struct QueueConstructorTest : public testing::Test {
  using Queue = s21::queue<T>;
};

using QueueConstructorTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(QueueConstructorTest, QueueConstructorTypes);

TYPED_TEST(QueueConstructorTest, empty) {
  using Queue = typename TestFixture::Queue;
  ASSERT_NO_THROW(Queue());
}

TYPED_TEST(QueueConstructorTest, size_n) {
  using Queue = typename TestFixture::Queue;
  ASSERT_NO_THROW(Queue(0U));
  ASSERT_NO_THROW(Queue(1U));
  ASSERT_NO_THROW(Queue(8U));
}

TYPED_TEST(QueueConstructorTest, initializer_list) {
  using Queue = typename TestFixture::Queue;
  ASSERT_NO_THROW(Queue({}));
  ASSERT_NO_THROW(Queue({TypeParam()}));
  ASSERT_NO_THROW(Queue({TypeParam(), TypeParam(), TypeParam()}));
}

TYPED_TEST(QueueConstructorTest, other_constructor) {
  using Queue = typename TestFixture::Queue;

  ASSERT_NO_THROW({
    Queue tmp_1{{TypeParam(1)}};
    Queue tmp_2(tmp_1);
    Queue tmp_3(std::move(tmp_2));
    Queue tmp_4{{TypeParam(4)}};
    tmp_4 = std::move(tmp_3);
  });
}
