#ifndef CPPCONTAINERS_LIST_H
#define CPPCONTAINERS_LIST_H

#include <cstdio>
#include <initializer_list>
#include "../node/node.h"
#include "../abstract/abstract.h"
#include <limits>

namespace s21 {

template<class T>
class ListIterator: Abstract<T> {
 private:
  using typename Abstract<T>::value_type;
  using TNode = Node<value_type>; // Template Node

  TNode * head_node_;
 public:
  explicit ListIterator(TNode* head) noexcept: head_node_(head) {};
};

template<class T>
class ListConstIterator;


template <class T>
class list: Abstract<T> {
 private:
  ///                 <----------List Member type---------->
  using typename Abstract<T>::value_type;
  using typename Abstract<T>::size_type;
  using typename Abstract<T>::reference;
  using typename Abstract<T>::const_reference;
  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;
  using TNode = Node<value_type>; // Template Node

  TNode * head_node_;
  size_type size_;
 public:
  ///                 <----------List Functions---------->
  list() noexcept: head_node_(nullptr), size_(0) {};
  explicit list(size_type n): size_(n) {
    if (n < 0)
      throw std::bad_alloc();

    TNode * cur_head = nullptr;
    TNode ** cur_tail = &head_node_;
    while (--n) {
      try {
        auto new_tail = new TNode(cur_head);
        // TODO может можно вынести ?
        // <-------------------------------->
        cur_head = new_tail;

        *cur_tail = new_tail;
        cur_tail = &(new_tail->tail_);
        // <-------------------------------->
      } catch (const std::bad_alloc& error) {
        // TODO (free if error)
        throw error;
      }
    }
  };
  list(std::initializer_list<value_type> const &items): size_(items.size()) {
    TNode * cur_head = nullptr;
    TNode ** cur_tail = &head_node_;
    for (auto item : items) {
      try {
        auto new_tail = new TNode(item, cur_head);
        // TODO может можно вынести ?
        // <-------------------------------->
        cur_head = new_tail;

        *cur_tail = new_tail;
        cur_tail = &(new_tail->tail_);
        // <-------------------------------->
      } catch (const std::bad_alloc& error) {
        // TODO (free if error)
        throw error;
      }
    }
  };
  list(const list &l): size_(l.size_) {
    TNode * cur_head = nullptr;
    TNode ** cur_tail = &head_node_;
    for (iterator item = l.begin(); item != l.end(); ++item) {
      try {
        auto new_tail = new TNode(*item, cur_head);
        // TODO может можно вынести ?
        // <-------------------------------->
        cur_head = new_tail;

        *cur_tail = new_tail;
        cur_tail = &(new_tail->tail_);
        // <-------------------------------->
      } catch (const std::bad_alloc& error) {
        // TODO (free if error)
        throw error;
      }
    }
  }
  list(list &&l) noexcept : size_(l.size_), head_node_(l.head_node_) {
    l.size_ = 0;
    l.head_node_ = nullptr;
  }
  ~list() {
    delete head_node_;
  }
  list& operator=(list &&l) noexcept {
    delete head_node_;

    size_ = l.size_;
    head_node_ = l.head_node_;

    l.size_ = 0;
    l.head_node_ = nullptr;

    return *this;
  }

  ///                 <----------List Element access---------->
  [[nodiscard]] const_reference front() const{
    if (empty())
      throw std::logic_error("Список пуст");
    return head_node_->data_;
  }
  const_reference back();

  ///                 <----------List Iterators---------->
  const_reference begin();
  const_reference end();

  ///                 <----------List Capacity---------->
  [[nodiscard]] bool empty() const noexcept {return !size_; };
  [[nodiscard]] size_type size() const noexcept { return size_; };
  [[nodiscard]] size_type max_size() const noexcept {return std::numeric_limits<size_type>::max() / sizeof(TNode) / 2;};

  ///                 <----------List Modifiers---------->
  void clear() {
      size_ = 0;

      delete head_node_;
      head_node_ = nullptr;
  };
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();

  void swap(list &other) noexcept {
    std::swap(head_node_, other.head_node_);
    std::swap(size_, other.size_);
  }

  void push_front(const_reference value);
  void pop_front();
  void merge(list &other);
  void splice(const_iterator pos, list& other);
  void reverse();
  void unique();
  void sort();
};

}  // namespace s21

#endif  // CPPCONTAINERS_LIST_H
