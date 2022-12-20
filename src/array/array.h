//
// Created by co_cy on 19.12.22.
//

#ifndef CPPCONTAINERS_ARRAY_H
#define CPPCONTAINERS_ARRAY_H

#include <initializer_list>

namespace s21 {

template <class T, std::size_t N>
class array {
 public:
  ///                 <----------Array Modifiers---------->
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator [[maybe_unused]] = const T *;
  using size_type = std::size_t;

 private:
  value_type data_[N];

 public:
  ///                 <----------Array Member functions---------->
  constexpr array() noexcept = default;
  constexpr array(std::initializer_list<value_type> const &items) {
    if (items.size() > N) {
      throw std::logic_error("error: too many initializers");
    }

    for (size_type i = 0U; i < N; ++i) {
      data_[i] = items.begin()[i];
    }
  };
  constexpr array(const array &a) {
    for (size_type i = 0U; i < N; ++i) {
      data_[i] = a[i];
    }
  }
  constexpr array(array &&a) noexcept {
    auto iter = data_;
    for (auto &item : a) {
      *(iter++) = std::move(item);
    }
  };
  constexpr array &operator=(array &&a) noexcept {
    for (size_type i = 0U; i < N; ++i) {
      data_[i] = std::move(a[i]);
    }
    return *this;
  };
  ~array() = default;

  ///                 <----------Array Element access---------->
  [[nodiscard]] constexpr reference at(size_type pos) {
    if (pos >= N) {
      throw std::out_of_range("Out of range");
    }
    return data_[pos];
  }
  [[nodiscard]] constexpr reference operator[](size_type pos) {
    return data_[pos];
  }
  [[nodiscard]] constexpr const_reference operator[](size_type pos) const {
    return data_[pos];
  }
  [[nodiscard]] constexpr const_reference front() const { return *data_; };
  [[nodiscard]] constexpr const_reference back() const {
    return data_[N - 1U];
  };
  [[nodiscard]] constexpr iterator data() noexcept { return data_; };

  ///                 <----------Array Iterators---------->
  [[nodiscard]] constexpr iterator begin() noexcept { return data_; };
  [[nodiscard]] constexpr iterator end() noexcept { return data_ + N; };

  ///                 <----------Array Capacity---------->
  [[nodiscard]] constexpr bool empty() const noexcept { return N == 0U; };
  [[nodiscard]] constexpr size_type size() const noexcept { return N; };
  [[nodiscard]] constexpr size_type max_size() const noexcept { return N; };

  ///                 <----------Array Member functions---------->
  constexpr void swap(array &other) noexcept {
    for (size_type i = 0U; i < N; ++i) {
      std::swap(data_[i], other.data_[i]);
    }
  }
  constexpr void fill(const_reference value) {
    for (auto &item : data_) {
      item = value;
    }
  }
};

}  // namespace s21

#endif  // CPPCONTAINERS_ARRAY_H
