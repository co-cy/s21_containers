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
  vector() : size_(0), capacity_(0), array_(new value_type[0]) {}
  explicit vector(size_type n)
      : size_(n), capacity_(n), array_(new value_type[n]) {}
  vector(const vector &v)
      : size_(v.size_), capacity_(v.size_), array_(new value_type[v.size_]) {
    int index = -1;
    for (auto iter = v.begin(); iter != v.end(); ++iter)
      array_[++index] = *iter;
  }
  vector(std::initializer_list<value_type> const &items)
      : size_(items.size()),
        capacity_(items.size()),
        array_(new value_type[items.size()]) {
    int index = -1;
    for (auto item : items) array_[++index] = item;
  }
  vector(const vector &&v) noexcept
      : size_(v.size_), capacity_(v.capacity_), array_(v.array_) {
    v.size_ = 0;
    v.capacity_ = 0;
    v.array_ = nullptr;
  }
  ~vector() { delete[] array_; }
  vector &operator=(vector &&v) noexcept {
    size_ = v.size_;
    v.size_ = 0;

    capacity_ = v.capacity_;
    v.capacity_ = 0;

    array_ = v.array_;
    v.array_ = nullptr;

    return *this;
  }

  ///                 <----------Vector Element access---------->
  const_reference front() { return array_[0]; }
  const_reference back() { return array_[size_ - 1]; }
  reference at(size_type pos) {
    if (pos >= size_) throw std::out_of_range("Out of array range");
    return array_[pos];
  }
  reference operator[](size_type pos) { return array_[pos]; }
  iterator data() { return array_; }

  ///                 <----------Vector Iterators---------->
  iterator begin() { return array_; }
  iterator end() { return array_ + size_; }

  ///                 <----------Vector Capacity---------->
  bool empty() { return !size_; }
  size_type size() { return size_; }
  size_type max_size() {
    return std::numeric_limits<size_type>::max() / sizeof(value_type) / 2;
  }
  void reserve(size_type size) {
    if (size > capacity_) {
      auto new_array = new value_type[size];
      for (size_type i = 0; i < size_ && i < size; ++i)
        new_array[i] = array_[i];
      delete array_;

      array_ = new_array;
      capacity_ = size;
    }
  }
  size_type capacity() { return capacity_; }
  void shrink_to_fit() {
    if (size_ != capacity_) {
      auto new_array = new value_type[size_];
      for (size_type i = 0; i < size_; ++i) new_array[i] = array_[i];
      delete array_;

      array_ = new_array;
      capacity_ = size_;
    }
  }

  ///                 <----------Vector Modifiers---------->
  void clear() { size_ = 0; }
  iterator insert(iterator pos, const_reference value) {
    size_type shift = pos - array_;

    if (size_ + 1 > capacity_) {
      if (!capacity_)
        reserve(size_ + 1);
      else
        reserve(2 * capacity_);
    }

    for (auto i = shift + 1; i < size_; ++i) array_[i] = array_[i - 1];

    ++size_;
    array_[shift] = value;

    return array_ + shift;
  }
  void erase(iterator pos) {
    for (auto i = pos; i != end(); ++i) *i = *(i + 1);
    if (size_) --size_;
  }
  void push_back(const_reference value) {
    if (size_ + 1 > capacity_) {
      if (!capacity_)
        reserve(size_ + 1);
      else
        reserve(2 * capacity_);
    }

    ++size_;
    array_[size_ - 1] = value;
  }
  void pop_back() {
    if (size_) --size_;
  }
  void swap(vector &other) {
    std::swap(array_, other.array_);
    std::swap(capacity_, other.capacity_);
    std::swap(size_, other.size_);
  }
};

}  // namespace s21

#endif  // CPPCONTAINERS_VECTOR_H
