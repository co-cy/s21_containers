#ifndef CPPCONTAINERS_STACK_HPP
#define CPPCONTAINERS_STACK_HPP

#include <cstdio>
#include <initializer_list>

#include "list/list.h"

namespace s21 {

template <class T>
class stack : protected s21::list<T> {
 private:
  using super = s21::list<T>;
  ///                 <----------Stack Member type---------->
  using value_type = typename super::value_type;
  using reference = typename super::reference;
  using const_reference = typename super::const_reference;
  using size_type = typename super::size_type;

 public:
  ///                 <----------Stack Member type---------->
  using super::super;

  ///                 <----------Stack Element access---------->
  [[nodiscard]] const_reference top() const noexcept { return super::front(); };

  ///                 <----------Stack Capacity---------->
  using super::empty;
  using super::size;

  ///                 <----------Stack Modifiers---------->
  void push(const_reference value) { super::push_front(value); };
  void pop() noexcept { super::pop_front(); };
  void swap(stack &s) noexcept { super::swap(static_cast<super &>(s)); }

  using super::emplace_front;
};

}  // namespace s21

#endif  // CPPCONTAINERS_STACK_HPP
