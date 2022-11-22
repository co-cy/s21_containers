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
      : size_(n), capacity_(2 * size_), array_(new value_type[capacity_]) {}
  vector(const vector &v)
      : size_(v.size_),
        capacity_(2 * size_),
        array_(new value_type[capacity_]) {
    int index = -1;
    for (auto iter = v.begin(); iter != v.end(); ++iter)
      array_[++index] = *iter;
  }
  vector(std::initializer_list<value_type> const &items)
      : size_(items.size()),
        capacity_(2 * size_),
        array_(new value_type[capacity_]) {
    int index = -1;
    for (auto item : items) array_[++index] = item;
  }
  vector(const vector &&v) noexcept
      : size_(v.size_),
        capacity_(2 * size_),
        array_(new value_type[capacity_]) {
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
    return array_[pos - 1];
  }
  reference operator[](size_type pos) { return array_[pos - 1]; }
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
      value_type new_array = new value_type[size];
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
      value_type new_array = new value_type[size_];
      for (size_type i = 0; i < size_; ++i) new_array[i] = array_[i];
      delete array_;

      array_ = new_array;
      capacity_ = size_;
    }
  }

  ///                 <----------Vector Modifiers---------->
  void clear() { size_ = 0; }
  iterator insert(iterator pos, const_reference value) {
    if (size_ + 1 >= capacity_) reserve(2 * (size_ + 1));

    for (auto i = pos + 1; i != end(); ++i) *i = *(i - 1);
    *pos = value;
    ++size_;
  }
  void erase(iterator pos) {
    for (auto i = pos; i != end(); ++i) *i = *(i + 1);
    --size_;
  }
  void push_back(const_reference value) {
    ++size_;
    if (size_ >= capacity_) reserve(2 * size_);

    array_[size_ - 2] = value;
  }
  void pop_back() { --size_; }
  void swap(vector &other) {
    std::swap(array_, other.array_);
    std::swap(capacity_, other.capacity_);
    std::swap(size_, other.size_);
  }
};

}  // namespace s21

#endif  // CPPCONTAINERS_VECTOR_H
