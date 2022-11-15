//
// Created by Nana Daughterless on 11/15/22.
//

#ifndef CPPCONTAINERS_ABSTRACT_H
#define CPPCONTAINERS_ABSTRACT_H

#include <cstdio>

namespace s21 {

template<class T>
class Abstract {
 protected:
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = std::size_t;
};

}  // namespace s21

#endif  // CPPCONTAINERS_ABSTRACT_H
