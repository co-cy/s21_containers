#ifndef CPPCONTAINERS_SET_H
#define CPPCONTAINERS_SET_H

#include <cstdio>
#include <initializer_list>

#include "../tree/tree.h"
#include "vector/vector.h"

namespace s21 {

template <class Key>
class set : public tree<Key> {
 private:
  ///                 <----------Set Member type---------->
  using tree<Key>::tree;
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename tree<key_type>::TreeIterator;
  using const_iterator = typename tree<value_type>::TreeIteratorConst;
  using size_type = std::size_t;

 public:
  ///                 <----------Set Member functions---------->

  set(std::initializer_list<value_type> const &items) : set() {
    for (value_type value : items) {
      insert(value);
    }
  }

  ///                 <----------Set Iterators---------->

  ///                 <----------Set Capacity---------->

  ///                 <----------Set Modifiers---------->

  std::pair<iterator, bool> insert(const value_type &value) override {
    return tree<key_type>::auto_insert(value, false);
  }
  void merge(set &other) { merge_set(other, other.ret_root()); }

  template <class... Args>
  std::vector<std::pair<iterator, bool>> emplace(Args &&...args) {
    std::vector<std::pair<iterator, bool>> res = {(insert(args))...};
    return res;
  }

  ///                 <----------Set Lookup---------->

 protected:
  void merge_set(set &other, typename tree<key_type>::TreeNode *item) {
    if (item->right_elem_) merge_set(other, item->right_elem_);
    if (item->left_elem_) merge_set(other, item->left_elem_);
    auto result = insert(item->value_);
    if (result.second) {
      auto iter = iterator(item);
      other.erase(iter);
    }
  }
};

}  // namespace s21

#endif  // CPPCONTAINERS_SET_H
