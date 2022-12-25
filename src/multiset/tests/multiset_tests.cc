#include <gtest/gtest.h>

#include "../multiset.h"

// using namespace s21;

TEST(test, ConstructorsList) {
  s21::multiset<int> new_multiset;

  std::initializer_list<int> items{1, 1, 1, 2, 1, 1, 1, 1, 3, 4};
  s21::multiset<int> my_multiset2(items);
  std::multiset<int> std_multiset2(items);
  auto my_iter = my_multiset2.begin();
  auto std_iter = std_multiset2.begin();
  while (my_iter != my_multiset2.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
  // s21::multiset<int>new_multiset4 = std::move(new_multiset3);
  // s21::multiset<int>new_multiset5 = new_multiset4;
}

TEST(test, ConstructorsList2) {
  std::initializer_list<int> items{2, 1, 2, 2};
  s21::multiset<int> my_multiset2(items);
  std::multiset<int> std_multiset2(items);
  auto my_iter = my_multiset2.begin();
  auto std_iter = std_multiset2.begin();
  while (my_iter != my_multiset2.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, ConstructorsCopy) {
  s21::multiset<int> new_multiset;

  std::initializer_list<int> items{2, 1, 3, 4};
  s21::multiset<int> my_multiset2(items);
  std::multiset<int> std_multiset2(items);

  s21::multiset<int> my_multiset3(my_multiset2);
  std::multiset<int> std_multiset3(std_multiset2);
  auto my_iter = my_multiset3.begin();
  auto std_iter = std_multiset3.begin();
  while (my_iter != my_multiset3.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }

  // s21::multiset<int>new_multiset5 = new_multiset4;
}

TEST(test, ConstructorsMove) {
  std::initializer_list<int> items{2, 1, 2, 2};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  s21::multiset<int> my_multiset2 = std::move(my_multiset);
  std::multiset<int> std_multiset2 = std::move(std_multiset);

  auto my_iter = my_multiset2.begin();
  auto std_iter = std_multiset2.begin();
  while (my_iter != my_multiset2.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, ConstructorsMove2) {
  std::initializer_list<int> items{2, 1, 2, 2};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  s21::multiset<int> my_multiset2 = my_multiset;
  std::multiset<int> std_multiset2 = std_multiset;

  auto my_iter = my_multiset2.begin();
  auto std_iter = std_multiset2.begin();
  while (my_iter != my_multiset2.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, IteratorTest) {
  std::initializer_list<int> items{1, 2, 3};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  while (my_iter != my_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, IteratorTestSolo) {
  std::initializer_list<int> items{2};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);

  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();

  while (my_iter != my_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, IteratorTestDoubleInc) {
  std::initializer_list<int> items{1, 2};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);

  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();

  while (my_iter != my_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, IteratorTestDoubleDec) {
  std::initializer_list<int> items{2, 1};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);

  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();

  while (my_iter != my_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, MinusIterator) {
  std::initializer_list<int> items{2, 1, 3, 34, 234, 231};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);

  auto my_iter = my_multiset.end();
  auto std_iter = std_multiset.end();

  while (my_iter != my_multiset.end()) {
    ++my_iter;
    ++std_iter;
    ASSERT_TRUE(*my_iter == *std_iter);
  }
}

TEST(test, MinusIteratorSolo) {
  std::initializer_list<int> items{2};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);

  auto my_iter = my_multiset.end();
  auto std_iter = std_multiset.end();

  while (my_iter != my_multiset.end()) {
    ++my_iter;
    ++std_iter;
    ASSERT_TRUE(*my_iter == *std_iter);
  }
}

TEST(test, MinusIteratorDuo1) {
  std::initializer_list<int> items{1, 2};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);

  auto my_iter = my_multiset.end();
  auto std_iter = std_multiset.end();

  while (my_iter != my_multiset.end()) {
    ++my_iter;
    ++std_iter;
    ASSERT_TRUE(*my_iter == *std_iter);
  }
}

TEST(test, MinusIteratorDuo2) {
  std::initializer_list<int> items{2, 1};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);

  auto my_iter = my_multiset.end();
  auto std_iter = std_multiset.end();

  while (my_iter != my_multiset.end()) {
    ++my_iter;
    ++std_iter;
    ASSERT_TRUE(*my_iter == *std_iter);
  }
}

TEST(test, Insert) {
  // std::initializer_list<int> items{1,5,3,2,};
  s21::multiset<int> my_multiset;
  std::multiset<int> std_multiset;
  my_multiset.insert(1);
  std_multiset.insert(1);
  my_multiset.insert(-1);
  std_multiset.insert(-1);
  my_multiset.insert(45);
  std_multiset.insert(45);
  my_multiset.insert(-24);
  std_multiset.insert(-24);
  my_multiset.insert(-24);
  std_multiset.insert(-24);
  my_multiset.insert(-24);
  std_multiset.insert(-24);
  my_multiset.insert(24);
  std_multiset.insert(24);
  my_multiset.insert(-24000);
  std_multiset.insert(-24000);
  my_multiset.insert(-2400);
  std_multiset.insert(-2400);
  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  while (std_iter != std_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, Erase1) {
  std::initializer_list<int> items{1, 5, 3, 2};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  ++std_iter;
  ++my_iter;
  ++std_iter;
  ++my_iter;
  std_multiset.erase(std_iter);
  my_multiset.erase(my_iter);
  my_iter = my_multiset.begin();
  std_iter = std_multiset.begin();
  while (std_iter != std_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, Erase2) {
  std::initializer_list<int> items{1, 5, 3, 4};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  ++std_iter;
  ++my_iter;
  ++std_iter;
  ++my_iter;
  std_multiset.erase(std_iter);
  my_multiset.erase(my_iter);
  my_iter = my_multiset.begin();
  std_iter = std_multiset.begin();
  while (std_iter != std_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, Erase3) {
  std::initializer_list<int> items{1, 5, 7, 6};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  ++std_iter;
  ++my_iter;
  ++std_iter;
  ++my_iter;
  ++std_iter;
  ++my_iter;
  std_multiset.erase(std_iter);
  my_multiset.erase(my_iter);
  my_iter = my_multiset.begin();
  std_iter = std_multiset.begin();
  while (std_iter != std_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, Erase4) {
  std::initializer_list<int> items{1, 5, 7, 8};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  ++std_iter;
  ++my_iter;
  ++std_iter;
  ++my_iter;
  std_multiset.erase(std_iter);
  my_multiset.erase(my_iter);
  my_iter = my_multiset.begin();
  std_iter = std_multiset.begin();
  while (std_iter != std_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, Erase5) {
  std::initializer_list<int> items{1, 5, 7, 6};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  std_multiset.erase(std_iter);
  my_multiset.erase(my_iter);
  my_iter = my_multiset.begin();
  std_iter = std_multiset.begin();
  while (std_iter != std_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, Erase6) {
  std::initializer_list<int> items{5, 1, 7, 6};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  std_multiset.erase(std_iter);
  my_multiset.erase(my_iter);
  my_iter = my_multiset.begin();
  std_iter = std_multiset.begin();
  while (std_iter != std_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, Erase7) {
  std::initializer_list<int> items{5};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  std_multiset.erase(std_iter);
  my_multiset.erase(my_iter);
  my_iter = my_multiset.begin();
  std_iter = std_multiset.begin();
  while (std_iter != std_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, Clear) {
  std::initializer_list<int> items{1, 5, 7, 6};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  my_multiset.clear();
  std_multiset.clear();
  ASSERT_TRUE(my_multiset.size() == 0);

  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  while (std_iter != std_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, Clear2) {
  s21::multiset<int> my_multiset;
  std::multiset<int> std_multiset;
  my_multiset.clear();
  std_multiset.clear();
  ASSERT_TRUE(my_multiset.size() == 0);

  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  while (std_iter != std_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, Swap) {
  std::initializer_list<int> items{1, 5, 7, 6};
  std::initializer_list<int> items2{17, 25, 57, 66, 34, 12, 5};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  s21::multiset<int> my_multiset2(items2);
  std::multiset<int> std_multiset2(items2);
  my_multiset.swap(my_multiset2);
  std_multiset.swap(std_multiset2);

  ASSERT_TRUE(my_multiset.size() == std_multiset.size());
  ASSERT_TRUE(my_multiset2.size() == std_multiset2.size());

  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  while (std_iter != std_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
  auto my_iter2 = my_multiset2.begin();
  auto std_iter2 = std_multiset2.begin();
  while (std_iter2 != std_multiset2.end()) {
    ASSERT_TRUE(*my_iter2 == *std_iter2);
    ++my_iter2;
    ++std_iter2;
  }
}

TEST(test, Find) {
  std::initializer_list<int> items{17, 25, 57, 66, 34, 12, 5};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  auto my_iter = my_multiset.find(66);
  auto std_iter = std_multiset.find(66);
  ASSERT_TRUE(*my_iter == *std_iter);
  my_iter = my_multiset.find(17);
  std_iter = std_multiset.find(17);
  ASSERT_TRUE(*my_iter == *std_iter);
  my_iter = my_multiset.find(25);
  std_iter = std_multiset.find(25);
  ASSERT_TRUE(*my_iter == *std_iter);
  my_iter = my_multiset.find(57);
  std_iter = std_multiset.find(57);
  ASSERT_TRUE(*my_iter == *std_iter);
  my_iter = my_multiset.find(34);
  std_iter = std_multiset.find(34);
  ASSERT_TRUE(*my_iter == *std_iter);
}

TEST(test, Contains) {
  std::initializer_list<int> items{17, 25, 57, 66, 34, 12, 5};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  bool my_cont = my_multiset.contains(17);
  ASSERT_TRUE(my_cont == true);
  my_cont = my_multiset.contains(18);
  ASSERT_TRUE(my_cont == false);
  my_cont = my_multiset.contains(25);
  ASSERT_TRUE(my_cont == true);
  my_cont = my_multiset.contains(57);
  ASSERT_TRUE(my_cont == true);
  my_cont = my_multiset.contains(5);
  ASSERT_TRUE(my_cont == true);
  my_cont = my_multiset.contains(13457);
  ASSERT_TRUE(my_cont == false);
  my_cont = my_multiset.contains(0);
  ASSERT_TRUE(my_cont == false);
}

TEST(test, Merge) {
  std::initializer_list<int> items{1, 2, 3};
  std::initializer_list<int> items2{4, 5, 6};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  s21::multiset<int> my_multiset2(items2);
  std::multiset<int> std_multiset2(items2);
  my_multiset.merge(my_multiset2);
  std_multiset.merge(std_multiset2);
  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  while (std_iter != std_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
  my_iter = my_multiset2.begin();
  std_iter = std_multiset2.begin();
  while (std_iter != std_multiset2.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, Merge2) {
  std::initializer_list<int> items{1, 2, 3};
  std::initializer_list<int> items2{1, 2, 3};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  s21::multiset<int> my_multiset2(items2);
  std::multiset<int> std_multiset2(items2);
  my_multiset.merge(my_multiset2);
  std_multiset.merge(std_multiset2);
  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  while (std_iter != std_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
  my_iter = my_multiset2.begin();
  std_iter = std_multiset2.begin();
  while (std_iter != std_multiset2.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, Merge3) {
  std::initializer_list<int> items{1, 2, 3};
  std::initializer_list<int> items2{2, 3, 543};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  s21::multiset<int> my_multiset2(items2);
  std::multiset<int> std_multiset2(items2);
  my_multiset.merge(my_multiset2);
  std_multiset.merge(std_multiset2);
  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  while (std_iter != std_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
  my_iter = my_multiset2.begin();
  std_iter = std_multiset2.begin();
  while (std_iter != std_multiset2.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, Merge4) {
  std::initializer_list<int> items{1, 2, 3};
  std::initializer_list<int> items2{44, 5, 6};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  s21::multiset<int> my_multiset2(items2);
  std::multiset<int> std_multiset2(items2);
  my_multiset.merge(my_multiset2);
  std_multiset.merge(std_multiset2);
  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  while (std_iter != std_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
  my_iter = my_multiset2.begin();
  std_iter = std_multiset2.begin();
  while (std_iter != std_multiset2.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}

TEST(test, Count) {
  std::initializer_list<int> items{1, 2, 2, 3, 3, 3, 3, 3, 3, 5, 2, 35, 463, 2};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);

  ASSERT_TRUE(my_multiset.count(2) == std_multiset.count(2));
  ASSERT_TRUE(my_multiset.count(3) == std_multiset.count(3));
  ASSERT_TRUE(my_multiset.count(1) == std_multiset.count(1));
  ASSERT_TRUE(my_multiset.count(33333) == std_multiset.count(33333));
}

TEST(test, equal_range) {
  std::initializer_list<int> items{1, 2, 2, 3, 3, 3, 3, 3, 3, 5, 2, 35, 463, 2};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);

  std::pair<s21::multiset<int>::TreeIterator, s21::multiset<int>::TreeIterator>
      my_pair = my_multiset.equal_range(2);
  std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator>
      std_pair = std_multiset.equal_range(2);

  auto my_iter = my_pair.first;
  auto std_iter = std_pair.first;

  while (my_iter != my_pair.second) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
  ASSERT_TRUE(*my_iter == *std_iter);

  my_iter = my_pair.first;
  std_iter = std_pair.first;

  while (std_iter != std_pair.second) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
  ASSERT_TRUE(*my_iter == *std_iter);
}

TEST(test, lower_bound) {
  std::initializer_list<int> items{10, 50, 30, 30, 60, 20, 23, 40};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);

  auto my_iter = my_multiset.lower_bound(30);
  auto std_iter = std_multiset.lower_bound(30);
  for (int i = 1; i < 61; i++) {
    my_iter = my_multiset.lower_bound(i);
    std_iter = std_multiset.lower_bound(i);
    ASSERT_TRUE(*my_iter == *std_iter);
  }
}

TEST(test, upper_bound) {
  std::initializer_list<int> items{10, 50, 30, 30, 60, 20, 23, 40};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);

  auto my_iter = my_multiset.upper_bound(30);
  auto std_iter = std_multiset.upper_bound(30);
  for (int i = 1; i < 60; i++) {
    my_iter = my_multiset.upper_bound(i);
    std_iter = std_multiset.upper_bound(i);
    ASSERT_TRUE(*my_iter == *std_iter);
  }
}

TEST(test, multisetEmplace) {
  std::initializer_list<int> items{1, 2, 3};
  std::initializer_list<int> items2{2, 3, 543};
  s21::multiset<int> my_multiset(items);
  std::multiset<int> std_multiset(items);
  std::multiset<int> std_multiset2(items2);
  std_multiset.merge(std_multiset2);
  my_multiset.emplace(2, 3, 543);
  auto my_iter = my_multiset.begin();
  auto std_iter = std_multiset.begin();
  while (std_iter != std_multiset.end()) {
    ASSERT_TRUE(*my_iter == *std_iter);
    ++my_iter;
    ++std_iter;
  }
}