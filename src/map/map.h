#ifndef CPPCONTAINERS_MAP_H
#define CPPCONTAINERS_MAP_H

#include <cstdio>
#include <initializer_list>
#include <utility>

#include "../tree/Tree.h"

namespace s21 {

template <class Key, class T>
class map : public Tree<std::pair<Key,T>> {
 private:
  ///                 <----------Map Member type---------->
  using Tree<std::pair<Key,T>>::Tree;
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = typename Tree<value_type>::TreeIterator;
  using const_iterator = typename Tree<value_type>::TreeIteratorConst;
  using size_type = std::size_t;

 public:
  ///                 <----------Map Member functions---------->

  map(std::initializer_list<value_type> const& items) :map() {
    for (value_type value: items) {
      insert(value.first, value.second);
    }
  }

  ///                 <----------Map Element access---------->
  [[nodiscard]] mapped_type& at(const key_type& key) {
    auto sol = find_contains_map(key);
    if (!sol) throw std::out_of_range("There is no such key!");
    return sol->value_.second;
  }

  mapped_type& operator[](const key_type& key) {
    try {
      return at(key);
    } catch(...){
      value_type val = value_type(key, mapped_type());
      Tree<value_type>::default_insert(val);
      return at(key);

    }
  }

  ///                 <----------Map Iterators---------->

  ///                 <----------Map Capacity---------->

  ///                 <----------Map Modifiers---------->


  std::pair<iterator, bool> insert(const key_type& key, const mapped_type& obj) {
    if (contains(key))
      return std::make_pair(iterator(this->find_contains_map(key)), false);
    iterator iter = Tree<value_type>::default_insert(std::make_pair(key,obj));
    return std::make_pair(iter, true);
  }

  std::pair<iterator, bool> insert(const value_type& value) {
    return insert(value.first,value.second);
  }

  std::pair<iterator, bool> insert_or_assign(const key_type& key, const mapped_type& obj) {
    typename Tree<value_type>::TreeNode * a = find_contains_map(key);
    if (a) {
      a->value_ = std::make_pair(key, obj);
      return std::make_pair(iterator(a),true);
    }
    iterator iter = Tree<value_type>::default_insert(std::make_pair(key, obj));
    return std::make_pair(iter, true);
  }
  void merge(map& other) {
    merge_map(other, other.ret_root());
  }

  ///                 <----------Map Modifiers---------->
  [[nodiscard]] bool contains(const key_type& key) {
    if (find_contains_map(key)) return 1;
    return 0;
  }

  template<class... Args>
  std::vector<std::pair<iterator,bool>> emplace(Args&&... args){
    std::vector<std::pair<iterator,bool>> res = {(insert(args))...};
  return res;
  }


 private:
  typename Tree<value_type>::TreeNode * find_contains_map(const key_type& key) {
    if (this->empty()) return nullptr; 
    auto *current = Tree<value_type>::ret_root();
    while(1) {
      if (current == nullptr) {
        return nullptr;
      } else if (current->value_.first == key) {
        return current;
      } else if (current->value_.first > key) {
        current = current->left_elem_;
      } else {
        current = current->right_elem_;
      }
    }
  }

  void merge_map(map& other, typename Tree<value_type>::TreeNode * item) {
    if (item->right_elem_)
      merge_map(other,item->right_elem_);
    if (item->left_elem_)
      merge_map(other,item->left_elem_);
    auto result = insert(item->value_);
    if (result.second) {
      auto iter = iterator(item);
      other.erase(iter);
    }
  }

};

}  // namespace s21

#endif  // CPPCONTAINERS_MAP_H
