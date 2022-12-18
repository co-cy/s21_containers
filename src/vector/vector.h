#ifndef CPPCONTAINERS_VECTOR_H
#define CPPCONTAINERS_VECTOR_H

#include <cstdio>
#include <initializer_list>
#include <limits>
#include <stdexcept>

namespace s21 {

template <class T>
class vector {
 public:
  ///                 <----------Vector Member type---------->
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator [[maybe_unused]] = const T *;
  using size_type = std::size_t;

 private:
  value_type *array_;
  size_type size_;
  size_type capacity_;

 public:
  ///                 <----------Vector Member functions---------->
  vector() : size_(0U), capacity_(0U), array_(new value_type[0U]) {}
  explicit vector(size_type n)
      : size_(n), capacity_(n), array_(new value_type[n]) {}
  vector(const vector &v)
      : size_(v.size_), capacity_(v.size_), array_(new value_type[v.size_]) {
    int index = -1;
    for (auto iter = v.begin(); iter != v.end(); ++iter) {
      array_[++index] = *iter;
    }
  }
  vector(std::initializer_list<value_type> const &items)
      : size_(items.size()),
        capacity_(items.size()),
        array_(new value_type[items.size()]) {
    int index = -1;
    for (auto item : items) {
      array_[++index] = item;
    }
  }
  vector(const vector &&v) noexcept
      : size_(v.size_), capacity_(v.capacity_), array_(v.array_) {
    v.size_ = 0;
    v.capacity_ = 0;
    v.array_ = new value_type[0U];
  }
  ~vector() { delete[] array_; }
  vector &operator=(vector &&v) noexcept {
    size_ = v.size_;
    v.size_ = 0;

    capacity_ = v.capacity_;
    v.capacity_ = 0;

    array_ = v.array_;
    v.array_ = new value_type[0U];

    return *this;
  }

  ///                 <----------Vector Element access---------->
  const_reference front() const noexcept { return array_[0]; }
  const_reference back() const noexcept { return array_[size_ - 1U]; }
  reference at(size_type pos) {
    if (pos >= size_) {
      throw std::out_of_range("Out of array range");
    }

    return array_[pos];
  }
  reference operator[](size_type pos) noexcept { return array_[pos]; }
  iterator data() noexcept { return array_; }

  ///                 <----------Vector Iterators---------->
  iterator begin() noexcept { return array_; }
  iterator end() noexcept { return array_ + size_; }

  ///                 <----------Vector Capacity---------->
  [[nodiscard]] bool empty() const noexcept { return size_ == 0U; }
  [[nodiscard]] size_type size() const noexcept { return size_; }
  [[nodiscard]] size_type max_size() const {
    return std::numeric_limits<size_type>::max() / sizeof(value_type) / 2U;
  }
  void reserve(size_type size) {
    if (size > capacity_) {
      auto new_array = new value_type[size];
      for (size_type i = 0U; i < size_ && i < size; ++i) {
        new_array[i] = std::move(array_[i]);
      }
      delete[] array_;

      array_ = std::move(new_array);
      capacity_ = size;
    }
  }
  [[nodiscard]] size_type capacity() const noexcept { return capacity_; }
  void shrink_to_fit() {
    if (size_ != capacity_) {
      auto new_array = new value_type[size_];
      for (size_type i = 0U; i < size_; ++i) {
        new_array[i] = std::move(array_[i]);
      }
      delete[] array_;

      array_ = std::move(new_array);
      capacity_ = size_;
    }
  }

  ///                 <----------Vector Modifiers---------->
  void clear() noexcept { size_ = 0U; }
  iterator insert(iterator pos, const_reference value) {
    size_type shift = pos - array_;

    if (size_ + 1U > capacity_) {
      if (capacity_ == 0U) {
        reserve(size_ + 1U);
      } else {
        reserve(2U * capacity_);
      }
    }

    for (auto i = shift + 1U; i < size_; ++i) {
      array_[i] = std::move(array_[i - 1U]);
    }

    ++size_;
    array_[shift] = value;

    return array_ + shift;
  }
  void erase(iterator pos) noexcept {
    for (auto i = pos; i != end(); ++i) {
      auto next = i + 1U;

      if (next != end()) {
        *i = std::move(*next);
      }
    }
    if (size_ > 0U) {
      --size_;
    }
  }
  void push_back(const_reference value) {
    if (size_ + 1U > capacity_) {
      if (capacity_ == 0U) {
        reserve(size_ + 1U);
      } else {
        reserve(2U * capacity_);
      }
    }

    ++size_;
    array_[size_ - 1U] = value;
  }
  void pop_back() noexcept {
    if (size_ > 0U) {
      --size_;
    }
  }
  void swap(vector &other) noexcept {
    std::swap(array_, other.array_);
    std::swap(capacity_, other.capacity_);
    std::swap(size_, other.size_);
  }
};

}  // namespace s21

#endif  // CPPCONTAINERS_VECTOR_H
