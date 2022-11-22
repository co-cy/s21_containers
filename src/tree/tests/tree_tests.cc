#include <gtest/gtest.h>

#include "../Tree.h"

using namespace std;

TEST(test, TreeMain) {
    Tree<int> new_tree;
    new_tree.insert(1);
    new_tree.insert(3);
    new_tree.insert(-101);
    // new_tree.tree_print(new_tree.get_root());

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
    for (int i = 0; i < 5; i++) {
        new_tree.insert(rand() % 10 - 5);
    }
    auto iter = new_tree.begin();
    int buffer = *iter;
    cout <<new_tree.size()<<endl;
    ++iter;
    new_tree.tree_print(new_tree.get_root());
    while(iter != new_tree.end()) {
        ASSERT_TRUE(*iter > buffer);
        ++iter;
    }
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}