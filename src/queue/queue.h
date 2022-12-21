#ifndef CPPCONTAINERS_QUEUE_HPP
#define CPPCONTAINERS_QUEUE_HPP

#include <cstdio>
#include <initializer_list>

#include "list/list.h"

namespace s21 {

template <class T>
class queue : protected s21::list<T> {
 private:
  using super = s21::list<T>;
  ///                 <----------Queue Member type---------->
  using value_type = typename super::value_type;
  using reference = typename super::reference;
  using const_reference = typename super::const_reference;
  using size_type = typename super::size_type;

 public:
  ///                 <----------Queue Member functions---------->
  queue() : super(){};
  explicit queue(size_type n) : super(n){};
  queue(std::initializer_list<value_type> const &items) : super(items){};
  queue(const queue &s) : super(s) {}
  queue(queue &&s) noexcept : super(s) {}
  queue &operator=(queue &&s) noexcept {
    super::operator=(static_cast<super &&>(s));
    return *this;
  }
  ~queue() = default;

  ///                 <----------Queue Element access---------->
  using super::back;
  using super::front;

  ///                 <----------Queue Capacity---------->
  using super::empty;
  using super::size;

  ///                 <----------Queue Modifiers---------->
  void push(const_reference value) { super::push_back(value); };
  void pop() { super::pop_front(); };
  void swap(queue &s) noexcept { super::swap(static_cast<super &>(s)); }

  using super::emplace_back;
};

}  // namespace s21

#endif  // CPPCONTAINERS_QUEUE_HPP
