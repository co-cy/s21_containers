#ifndef CPPCONTAINERS_MULTISET_H
#define CPPCONTAINERS_MULTISET_H

#include <cstdio>
#include <initializer_list>

#include "../tree/Tree.h"

namespace s21 {

template <class Key>
class multiset : public Tree<Key>{

 private:
  ///                 <----------Set Member type---------->
  using Tree<Key>::Tree;

  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;  // TODO Плохой вариант правило склейки ссылок
  using const_reference = const value_type &;  // TODO Плохой вариант правило склейки ссылок
  using iterator = typename Tree<key_type>::TreeIterator;
  //  const_iterator
  using size_type = std::size_t;

 public:
  ///                 <----------Multiset Member functions---------->

  multiset(std::initializer_list<value_type> const &items) {
    for (value_type value: items) {
      Tree<Key>::insert(value);
    }    
  }

  ///                 <----------Multiset Iterators---------->

  ///                 <----------Multiset Capacity---------->

  ///                 <----------Multiset Modifiers---------->

    size_type count(const key_type& key) {
      auto iter = Tree<Key>::find(key);
      if (iter == nullptr) return 0;
      size_type count = 0;
      key_type k = *iter;
      do {
        ++count;
        ++iter;
      } while (k == *iter);
      return count;
    }
    
    std::pair<iterator,iterator> equal_range(const key_type& key) {
      auto iter_begin = Tree<Key>::find(key);
      auto iter = iter_begin;
      key_type k = *iter;
      do {
        ++iter;
      } while(k == *iter);
      --iter;
      return std::make_pair(iter_begin,iter);
    }
};
}

#endif  // CPPCONTAINERS_MULTISET_H