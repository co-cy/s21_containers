#ifndef CPPCONTAINERS_STACK_HPP
#define CPPCONTAINERS_STACK_HPP

#include <cstdio>
#include <initializer_list>

namespace s21 {

template <class T>
class stack {
 private:
  ///                 <----------Stack Member type---------->
  using value_type = T;
  using reference = T &;  // TODO Плохой вариант правило склейки ссылок
  using const_reference =
      const T &;  // TODO Плохой вариант правило склейки ссылок
  using size_type = std::size_t;

 public:
  ///                 <----------Stack Member type---------->
  stack();
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &s);
  stack(stack &&s);
  ~stack();
  auto operator=(stack &&s);

  ///                 <----------Stack Element access---------->
  const_reference top();

  ///                 <----------Stack Capacity---------->
  bool empty();
  size_type size();

  ///                 <----------Stack Modifiers---------->
  void push(const_reference value);
  void pop();
  void swap(stack &other);
};

}  // namespace s21

#endif  // CPPCONTAINERS_STACK_HPP
