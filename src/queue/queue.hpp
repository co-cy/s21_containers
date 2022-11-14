#ifndef CPPCONTAINERS_QUEUE_HPP
#define CPPCONTAINERS_QUEUE_HPP

#include <cstdio>
#include <initializer_list>

namespace s21 {

template <class T>
class queue {
 private:
  ///                 <----------Queue Member type---------->
  using value_type = T;
  using reference = T &;  // TODO Плохой вариант правило склейки ссылок
  using const_reference =
      const T &;  // TODO Плохой вариант правило склейки ссылок
  using size_type = std::size_t;

 public:
  ///                 <----------Queue Member functions---------->
  queue();
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &q);
  queue(queue &&q);
  ~queue();
  auto operator=(queue &&q);

  ///                 <----------Queue Element access---------->
  const_reference front();
  const_reference back();

  ///                 <----------Queue Capacity---------->
  bool empty();
  size_type size();

  ///                 <----------Queue Modifiers---------->
  void push(const_reference value);
  void pop();
  void swap(queue &other);
};

}  // namespace s21

#endif  // CPPCONTAINERS_QUEUE_HPP
