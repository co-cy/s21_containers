#ifndef CPPCONTAINERS_SET_H
#define CPPCONTAINERS_SET_H

#include <cstdio>
#include <initializer_list>

#include "../tree/Tree.h"

namespace s21 {

template <class Key>
class set : public Tree<Key>{
 private:
  ///                 <----------Set Member type---------->
  using Tree<Key>::Tree;
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;  // TODO Плохой вариант правило склейки ссылок
  using const_reference =
      const value_type &;  // TODO Плохой вариант правило склейки ссылок
  using iterator = typename Tree<key_type>::TreeIterator;
  //  const_iterator
  using size_type = std::size_t;

 public:
  ///                 <----------Set Member functions---------->

  set(std::initializer_list<value_type> const &items) {
    for (value_type value: items) {
      insert(value);
    }
  }

  ///                 <----------Set Iterators---------->

  ///                 <----------Set Capacity---------->

  ///                 <----------Set Modifiers---------->

  std::pair<iterator, bool> insert(const value_type& value) {
    if (!this->contains(value)) {
      iterator iter = this->default_insert(value);
      return std::make_pair(iter, true);
    }
    return std::make_pair(nullptr, false);
  }
  void merge(set &other) {
    merge_set(other,other.root_node);
  }

  ///                 <----------Set Lookup---------->

 protected:
  void merge_set(set & other, typename Tree<key_type>::TreeNode * item) {
    if (item->right_elem_)
      merge_set(other,item->right_elem_);
    if (item->left_elem_)
      merge_set(other,item->left_elem_);
    auto result = insert(item->value_);
    if (result.second) {
      auto iter = iterator(item);
      other.erase(iter);
    }
  }
};

}  // namespace s21

#endif  // CPPCONTAINERS_SET_H
