#ifndef CPPCONTAINERS_SET_HPP
#define CPPCONTAINERS_SET_HPP

#include <cstdio>
#include <initializer_list>

namespace s21 {

template <class Key>
class set {
 private:
  ///                 <----------Set Member type---------->
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;  // TODO Плохой вариант правило склейки ссылок
  using const_reference =
      const value_type &;  // TODO Плохой вариант правило склейки ссылок
  //  iterator
  //  const_iterator
  using size_type = std::size_t;

 public:
  ///                 <----------Set Member functions---------->
  set();
  set(std::initializer_list<value_type> const &items);
  set(const set &s);
  set(set &&s);
  ~set();
  auto operator=(set &&s);

  ///                 <----------Set Iterators---------->
  // iterator begin();
  // iterator end();

  ///                 <----------Set Capacity---------->
  bool empty();
  size_type size();
  size_type max_size();

  ///                 <----------Set Modifiers---------->
  void clear();
  // std::pair<iterator, bool> insert(const value_type& value);
  // void erase(iterator pos);
  void swap(set &other);
  void merge(set &other);

  ///                 <----------Set Lookup---------->
  // iterator find(const Key& key);
  bool contains(const Key &key);
};

}  // namespace s21

#endif  // CPPCONTAINERS_SET_HPP
