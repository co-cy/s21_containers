#include "Tree.h"
using namespace std;

int main() {
  Tree<int> tree;
  tree.insert(1);
  tree.insert(12);
  tree.insert(-123);
  tree.insert(1234);
  
  tree.tree_print(nullptr);
  return 0;
}