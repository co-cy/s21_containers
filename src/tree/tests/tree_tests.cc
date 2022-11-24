#include <gtest/gtest.h>

#include "../Tree.h"

using namespace std;

TEST(test, TreeMain) {
  Tree<int> new_tree;
  new_tree.insert(1);
  new_tree.insert(3);
  new_tree.insert(-101);
  // new_tree.tree_print(nullptr);

  auto a = new_tree.begin();
  ASSERT_TRUE(*a == -101);
  ++a;
  ASSERT_TRUE(*a == 1);
  --a;
  ASSERT_TRUE(*a == -101);
  --a;

  auto b = new_tree.end();
  --b;
  ASSERT_TRUE(*b == 3);
  --b;
  ASSERT_TRUE(*b == 1);
  --b;
  ASSERT_TRUE(*b == -101);
}

TEST(test, TreeInsertErace) {
  Tree<int> new_tree;
  new_tree.insert(1);
  new_tree.insert(3);
  new_tree.insert(-101);
  auto a = new_tree.begin();
  // new_tree.tree_print(new_tree.get_root());
  ASSERT_TRUE(*a == -101);
  ++a;
  ASSERT_TRUE(*a == 1);
  ++a;
  new_tree.erase(a);
  // new_tree.tree_print(new_tree.get_root());
  auto b = new_tree.begin();
  ASSERT_TRUE(*b == -101);
  ++b;
  ASSERT_TRUE(*b == 1);
}

TEST(test, TreeInsertErace2) {
  Tree<int> new_tree;
  new_tree.insert(1);
  new_tree.insert(3);
  new_tree.insert(-101);
  auto a = new_tree.begin();
  // new_tree.tree_print(new_tree.get_root());
  ASSERT_TRUE(*a == -101);
  ++a;
  ASSERT_TRUE(*a == 1);
  new_tree.erase(a);
  // new_tree.tree_print(new_tree.get_root());
  auto b = new_tree.begin();
  ASSERT_TRUE(*b == -101);
  // cout << endl << endl << *b << endl << endl;
  ++b;
  ASSERT_TRUE(*b == 3);
  // cout << "OK1" << endl << endl;
}

TEST(test, TreeInsertErace3) {
  Tree<int> new_tree;
  new_tree.insert(1);
  new_tree.insert(3);
  new_tree.insert(-101);
  auto a = new_tree.begin();
  // new_tree.tree_print(new_tree.get_root());
  ASSERT_TRUE(*a == -101);
  ++a;
  ASSERT_TRUE(*a == 1);
  new_tree.erase(a);
  // new_tree.tree_print(new_tree.get_root());
  auto b = new_tree.begin();
  ASSERT_TRUE(*b == -101);
  ++b;
  ASSERT_TRUE(*b == 3);
}

TEST(test, TreeInsertHard) {
  Tree<int> new_tree;
  for (int i = 0; i < 50; i++) {
    new_tree.insert(rand() % 10 - 5);
  }
  auto iter = new_tree.begin();
  int buffer = *iter;
  //   cout << new_tree.size() << endl;
  ++iter;
  //   new_tree.tree_print(nullptr);
  while (iter != new_tree.end()) {
    ASSERT_TRUE(*iter >= buffer);
    ASSERT_EQ(new_tree.size(), 50);
    buffer = *iter;
    ++iter;
  }
}

TEST(test, TreeErace) {
  Tree<int> new_tree;
  new_tree.insert(0);
  new_tree.insert(-1);
  new_tree.insert(1);
  new_tree.insert(2);
  // new_tree.tree_print(nullptr);
  auto iter = new_tree.begin();
  EXPECT_EQ(*iter, -1);
  new_tree.erase(iter);
  cout<<"ok1"<<endl;
  auto iter2 = new_tree.begin();
  cout<<"ok2"<<endl;

  EXPECT_EQ(*iter2, 0);
  cout<<"ok3 "<< *iter2<<endl;

  auto iter3 = new_tree.end();
  iter3--;
  new_tree.erase(iter3);
  cout << "ok3.1"<<endl;
auto iter4 = new_tree.end();
  cout << "ok4.0"<<endl;

  iter4--;
  cout<<"ok4 "<< *iter4<<endl;
  EXPECT_EQ(*iter4, 1);




}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}