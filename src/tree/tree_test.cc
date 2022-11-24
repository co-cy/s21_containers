#include "Tree.h"
using namespace std;

int main() {
  Tree<int> tree;
  tree.insert(1);
  tree.insert(-1);
  tree.insert(31);
  auto iter = tree.begin();
  cout << *iter << endl;
  ++iter;
  cout << *iter << endl;
  ++iter;
  cout << *iter << endl;
  --iter;
  cout << *iter << endl;
  --iter;
  cout << *iter << endl;

  // tree.tree_print();

  return 0;
}