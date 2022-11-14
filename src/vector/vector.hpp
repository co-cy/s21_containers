#ifndef CPPCONTAINERS_VECTOR_HPP
#define CPPCONTAINERS_VECTOR_HPP

#include <cstdio>
#include <initializer_list>

namespace s21 {

template <class T>
class vector {
 private:
  ///                 <----------Vector Member type---------->
  using value_type = T;
  using reference = T &;  // TODO Плохой вариант правило склейки ссылок
  using const_reference =
      const T &;  // TODO Плохой вариант правило склейки ссылок
  //  iterator
  //  const_iterator
  using size_type = std::size_t;

 public:
  ///                 <----------Vector Member functions---------->
  vector();
  vector(size_type n);
  vector(std::initializer_list<value_type> const &items);
  vector(const vector &v);
  vector(const vector &&v);
  ~vector();
  auto operator=(vector &&v);

  ///                 <----------Vector Element access---------->
  const_reference front();
  const_reference back();

  reference at(size_type pos);
  reference operator[](size_type pos);
  // iterator data();

  ///                 <----------Vector Iterators---------->
  // iterator begin();
  // iterator end();

  ///                 <----------Vector Capacity---------->
  bool empty();
  size_type size();
  size_type max_size();

  void reserve(size_type size);
  size_type capacity();
  void shrink_to_fit();

  ///                 <----------Vector Modifiers---------->
  void clear();
  //  iterator insert(iterator pos, const_reference value);
  //  void erase(iterator pos)
  void push_back(const_reference value);
  void pop_back();
  void swap(vector &other);
};

}  // namespace s21

#endif  // CPPCONTAINERS_VECTOR_HPP
