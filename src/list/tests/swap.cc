//
// Created by co_cy on 16.11.22.
//

#include <gtest/gtest.h>

#include "list/list.h"

TEST(listSwapTest, check_n_list_char) {
  s21::list<char> a(1);
  s21::list<char> b(10);

  EXPECT_NO_THROW(a.swap(b));
  EXPECT_EQ(a.size(), 10);
  EXPECT_EQ(b.size(), 1);

  // TODO check elements
}