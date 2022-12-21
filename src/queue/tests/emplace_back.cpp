//
// Created by co_cy on 20.12.22.
//

#include <gtest/gtest.h>

#include "queue/queue.h"

template <typename T>
struct QueueEmplaceFrontTest : public testing::Test {
  using Queue = s21::queue<T>;
};

using QueueEmplaceFrontTypes = ::testing::Types<char, int, long double>;
TYPED_TEST_SUITE(QueueEmplaceFrontTest, QueueEmplaceFrontTypes);

TYPED_TEST(QueueEmplaceFrontTest, empty) {
  using Queue = typename TestFixture::Queue;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  Queue a{};

  EXPECT_NO_THROW((void)a.emplace_back(value_1));
  EXPECT_NO_THROW((void)a.emplace_back(value_2, value_3));
  EXPECT_EQ(a.size(), 3);

  EXPECT_DOUBLE_EQ(a.front(), value_1);
  EXPECT_DOUBLE_EQ(a.back(), value_3);
  EXPECT_NO_THROW(a.pop());
  EXPECT_EQ(a.size(), 2);
  EXPECT_DOUBLE_EQ(a.front(), value_2);
  EXPECT_DOUBLE_EQ(a.back(), value_3);
  EXPECT_NO_THROW(a.pop());
  EXPECT_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.front(), value_3);
  EXPECT_DOUBLE_EQ(a.back(), value_3);
  EXPECT_NO_THROW(a.pop());
  EXPECT_EQ(a.size(), 0);
}

TYPED_TEST(QueueEmplaceFrontTest, size_n) {
  using Queue = typename TestFixture::Queue;
  TypeParam value_1(1);
  TypeParam value_2(2);
  TypeParam value_3(3);

  Queue a(0U);
  EXPECT_NO_THROW((void)a.emplace_back(value_1));
  EXPECT_NO_THROW((void)a.emplace_back(value_2, value_3));
  EXPECT_EQ(a.size(), 3);

  EXPECT_DOUBLE_EQ(a.front(), value_1);
  EXPECT_DOUBLE_EQ(a.back(), value_3);
  EXPECT_NO_THROW(a.pop());
  EXPECT_EQ(a.size(), 2);
  EXPECT_DOUBLE_EQ(a.front(), value_2);
  EXPECT_DOUBLE_EQ(a.back(), value_3);
  EXPECT_NO_THROW(a.pop());
  EXPECT_EQ(a.size(), 1);
  EXPECT_DOUBLE_EQ(a.front(), value_3);
  EXPECT_DOUBLE_EQ(a.back(), value_3);
  EXPECT_NO_THROW(a.pop());
  EXPECT_EQ(a.size(), 0);

  Queue b(1U);
  EXPECT_NO_THROW((void)b.emplace_back(value_1));
  EXPECT_NO_THROW((void)b.emplace_back(value_2, value_3));
  EXPECT_EQ(b.size(), 4);

  EXPECT_DOUBLE_EQ(b.back(), value_3);
  EXPECT_NO_THROW(b.pop());
  EXPECT_EQ(b.size(), 3);
  EXPECT_DOUBLE_EQ(b.front(), value_1);
  EXPECT_DOUBLE_EQ(b.back(), value_3);
  EXPECT_NO_THROW(b.pop());
  EXPECT_EQ(b.size(), 2);
  EXPECT_DOUBLE_EQ(b.front(), value_2);
  EXPECT_DOUBLE_EQ(b.back(), value_3);
  EXPECT_NO_THROW(b.pop());
  EXPECT_EQ(b.size(), 1);
  EXPECT_DOUBLE_EQ(b.front(), value_3);
  EXPECT_DOUBLE_EQ(b.back(), value_3);
  EXPECT_NO_THROW(b.pop());
  EXPECT_EQ(b.size(), 0);

  Queue c(8U);
  EXPECT_NO_THROW((void)c.emplace_back(value_1));
  EXPECT_NO_THROW((void)c.emplace_back(value_2, value_3));
  EXPECT_EQ(c.size(), 11);

  EXPECT_DOUBLE_EQ(c.back(), value_3);
  for (size_t i = 0U; i < 8U; ++i) {
    EXPECT_NO_THROW(c.pop());
  }
  EXPECT_EQ(c.size(), 3);
  EXPECT_DOUBLE_EQ(c.front(), value_1);
  EXPECT_DOUBLE_EQ(c.back(), value_3);
  EXPECT_NO_THROW(c.pop());
  EXPECT_EQ(c.size(), 2);
  EXPECT_DOUBLE_EQ(c.front(), value_2);
  EXPECT_DOUBLE_EQ(c.back(), value_3);
  EXPECT_NO_THROW(c.pop());
  EXPECT_EQ(c.size(), 1);
  EXPECT_DOUBLE_EQ(c.front(), value_3);
  EXPECT_DOUBLE_EQ(c.back(), value_3);
  EXPECT_NO_THROW(c.pop());
  EXPECT_EQ(c.size(), 0);
}
