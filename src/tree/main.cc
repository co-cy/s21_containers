#include "Tree.h"
using namespace std;

int main() {
  Tree<int> tree;
  tree.insert(1);
  tree.insert(12);
  tree.insert(-123);
  tree.insert(1234);
  
  tree.tree_print(nullptr);
  Tree<int> tree2(tree);
  tree2.tree_print(nullptr);

  initializer_list<int> into = {1,2,3};
  Tree<int> tree3(into);

  tree3.tree_print(nullptr);

  tree.swap(tree3);

  tree.tree_print(nullptr);


  return 0;
}