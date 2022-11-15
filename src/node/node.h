//
// Created by Nana Daughterless on 11/15/22.
//

#ifndef CPPCONTAINERS_NODE_H
#define CPPCONTAINERS_NODE_H

#include "../abstract/abstract.h"

#include <initializer_list>
#include <stdexcept>

namespace s21 {

template<class T>
class Node : public Abstract<T> {
  using typename Abstract<T>::value_type;
  using typename Abstract<T>::size_type;
  using Self = Node<value_type>;

 private:
  Self* head_;
  Self* tail_;
  value_type data_;
 public:
  explicit Node(Self* head = nullptr, Self* tail = nullptr): head_(head), tail_(tail), data_() {};
  explicit Node(Self& value, Self* head = nullptr, Self* tail = nullptr): data_(value), head_(head), tail_(tail) {};
  ~Node() {
      delete tail_;
  };
};

}  // namespace s21

#endif  // CPPCONTAINERS_NODE_H
