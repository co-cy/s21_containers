//
// Created by co_cy on 22.11.22.
//

#include "gtest/gtest.h"
#include "queue/queue.h"

template <typename T>
struct QueueEmptyTest : public testing::Test {
  using Queue = s21::queue<T>;
};

using QueueEmptyTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(QueueEmptyTest, QueueEmptyTypes);

TYPED_TEST(QueueEmptyTest, empty) {
  using Queue = typename TestFixture::Queue;
  EXPECT_TRUE(Queue().empty());
}

TYPED_TEST(QueueEmptyTest, size_n) {
  using Queue = typename TestFixture::Queue;
  EXPECT_TRUE(Queue(0U).empty());
  EXPECT_FALSE(Queue(1U).empty());
  EXPECT_FALSE(Queue(8U).empty());
}

TYPED_TEST(QueueEmptyTest, initializer_list) {
  using Queue = typename TestFixture::Queue;
  EXPECT_TRUE(Queue({}).empty());
  EXPECT_FALSE(Queue({TypeParam()}).empty());
  EXPECT_FALSE(Queue({TypeParam(), TypeParam(), TypeParam()}).empty());
}

TYPED_TEST(QueueEmptyTest, other_constructor) {
  using Queue = typename TestFixture::Queue;

  Queue tmp_1{{TypeParam(1)}};
  EXPECT_FALSE(tmp_1.empty());
  Queue tmp_2(tmp_1);
  EXPECT_FALSE(tmp_1.empty());
  EXPECT_FALSE(tmp_2.empty());
  Queue tmp_3(std::move(tmp_2));
  EXPECT_FALSE(tmp_3.empty());
  Queue tmp_4{{TypeParam(4)}};
  tmp_4 = std::move(tmp_3);
  EXPECT_FALSE(tmp_4.empty());
}
