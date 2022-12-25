#ifndef CPPCONTAINERS_MULTISET_H
#define CPPCONTAINERS_MULTISET_H

#include <cstdio>
#include <initializer_list>

#include "../tree/tree.h"
#include "vector/vector.h"

namespace s21 {

template <class Key>
class multiset : public tree<Key> {
 private:
  ///                 <----------Set Member type---------->
  using tree<Key>::tree;

  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = typename tree<key_type>::TreeIterator;
  using const_iterator = typename tree<value_type>::TreeIteratorConst;
  using size_type = std::size_t;

 public:
  ///                 <----------Multiset Member functions---------->

  multiset(std::initializer_list<value_type> const& items) : multiset() {
    for (value_type value : items) {
      tree<Key>::default_insert(value);
    }
  }
  ///                 <----------Multiset Iterators---------->

  ///                 <----------Multiset Capacity---------->

  ///                 <----------Multiset Modifiers---------->

  [[nodiscard]] size_type count(const key_type& key) {
    auto iter = tree<Key>::find(key);
    if (iter == iterator(nullptr)) return 0;
    size_type count = 0;
    key_type k = *iter;
    do {
      ++count;
      ++iter;
    } while (k == *iter);
    return count;
  }

  [[nodiscard]] std::pair<iterator, iterator> equal_range(const key_type& key) {
    auto iter_begin = tree<Key>::find(key);
    auto iter = iter_begin;
    key_type k = *iter;
    do {
      ++iter;
    } while (k == *iter);
    --iter;
    return std::make_pair(iter_begin, iter);
  }

  [[nodiscard]] iterator upper_bound(const key_type& key) {
    auto node = this->find_contains(key);
    iterator sol = iterator(node);
    while (*sol <= key && sol != this->end()) ++sol;
    return sol;
  }

  [[nodiscard]] iterator lower_bound(const key_type& key) {
    auto node = this->find_contains(key);
    iterator sol = iterator(node);
    if (node->value_ < key && sol != this->end()) ++sol;
    return sol;
  }

  template <class... Args>
  std::vector<std::pair<iterator, bool>> emplace(Args&&... args) {
    std::vector<std::pair<iterator, bool>> res = {
        (tree<value_type>::insert(args))...};
    return res;
  }
};
}  // namespace s21

#endif  // CPPCONTAINERS_MULTISET_H