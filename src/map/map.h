#ifndef CPPCONTAINERS_MAP_H
#define CPPCONTAINERS_MAP_H

#include <cstdio>
#include <initializer_list>
#include <utility>

namespace s21 {

template <class Key, class T>
class map {
 private:
  ///                 <----------Map Member type---------->
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  //  iterator
  //  const_iterator
  using size_type = std::size_t;

 public:
  ///                 <----------Map Member functions---------->
  map();
  map(std::initializer_list<value_type> const& items);
  map(const map& m);
  map(map&& m);
  ~map();
  auto operator=(map&& m);

  ///                 <----------Map Element access---------->
  T& at(const Key& key);
  T& operator[](const Key& key);

  ///                 <----------Map Iterators---------->
  //  iterator begin();
  //  iterator end();

  ///                 <----------Map Capacity---------->
  bool empty();
  size_type size();
  size_type max_size();

  ///                 <----------Map Modifiers---------->
  void clear();
  //  std::pair<iterator, bool> insert(const value_type& value);
  //  std::pair<iterator, bool> insert(const Key& key, const T& obj)
  //  std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
  //  void erase(iterator pos)
  void swap(map& other);
  void merge(map& other);

  ///                 <----------Map Modifiers---------->
  bool contains(const Key& key);
};

}  // namespace s21

#endif  // CPPCONTAINERS_MAP_H
