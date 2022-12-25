//
// Created by co_cy on 22.11.22.
//

#include "gtest/gtest.h"
#include "queue/queue.h"

template <typename T>
struct QueueSizeTest : public testing::Test {
  using Queue = s21::queue<T>;
};

using QueueSizeTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(QueueSizeTest, QueueSizeTypes);

TYPED_TEST(QueueSizeTest, empty) {
  using Queue = typename TestFixture::Queue;
  EXPECT_EQ(Queue().size(), 0);
}

TYPED_TEST(QueueSizeTest, size_n) {
  using Queue = typename TestFixture::Queue;
  EXPECT_EQ(Queue(0U).size(), 0);
  EXPECT_EQ(Queue(1U).size(), 1);
  EXPECT_EQ(Queue(8U).size(), 8);
}

TYPED_TEST(QueueSizeTest, initializer_list) {
  using Queue = typename TestFixture::Queue;
  EXPECT_EQ(Queue({}).size(), 0);
  EXPECT_EQ(Queue({TypeParam()}).size(), 1);
  EXPECT_EQ(Queue({TypeParam(), TypeParam(), TypeParam()}).size(), 3);
}

TYPED_TEST(QueueSizeTest, other_constructor) {
  using Queue = typename TestFixture::Queue;

  Queue tmp_1{{TypeParam(1)}};
  EXPECT_EQ(tmp_1.size(), 1);
  Queue tmp_2(tmp_1);
  EXPECT_EQ(tmp_1.size(), 1);
  EXPECT_EQ(tmp_2.size(), 1);
  Queue tmp_3(std::move(tmp_2));
  EXPECT_EQ(tmp_3.size(), 1);
  Queue tmp_4{{TypeParam(4)}};
  EXPECT_EQ(tmp_4.size(), 1);
  tmp_4 = std::move(tmp_3);
  EXPECT_EQ(tmp_4.size(), 1);
}
