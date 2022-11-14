#ifndef CPPCONTAINERS_LIST_H
#define CPPCONTAINERS_LIST_H

#include <cstdio>
#include <initializer_list>

namespace s21 {

template <class T>
class list {
 private:
  ///                 <----------List Member type---------->
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  //  iterator
  //  const_iterator
  using size_type = std::size_t;

 public:
  ///                 <----------List Functions---------->
  list();
  list(size_type n);
  list(std::initializer_list<value_type> const &items);
  list(const list &l);
  list(list &&l);
  ~list();
  auto operator=(list &&l);

  ///                 <----------List Element access---------->
  const_reference front();
  const_reference back();

  ///                 <----------List Iterators---------->
  const_reference begin();
  const_reference end();

  ///                 <----------List Capacity---------->
  bool empty();
  size_type size();
  size_type max_size();

  ///                 <----------List Modifiers---------->
  void clear();
  //  iterator insert(iterator pos, const_reference value);
  //  void erase(iterator pos)
  void push_back(const_reference value);
  void pop_back();

  void swap(list &other);

  void push_front(const_reference value);
  void pop_front();
  void merge(list &other);
  //  void splice(const_iterator pos, list& other);
  void reverse();
  void unique();
  void sort();
};

}  // namespace s21

#endif  // CPPCONTAINERS_LIST_H
