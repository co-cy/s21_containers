#ifndef CPPCONTAINERS_LIST_H
#define CPPCONTAINERS_LIST_H

#include <cstdio>
#include <initializer_list>
#include <limits>

#include "../node/node.h"

namespace s21 {
#include <iostream>

template <class T>
class list {
 public:
  ///                 <----------List Member type---------->
  using value_type = T;
  using reference [[maybe_unused]] = value_type &;
  using const_reference = const value_type &;
  using size_type = std::size_t;
  using iterator = NodeIterator<T>;
  using const_iterator = NodeIteratorConst<T>;
  using TNode = Node<value_type>;  // Template Node

 private:
  TNode *head_;
  size_type size_;

  void ClearNodes() noexcept {
    for (; size_ > 0U; --size_) {
      TNode *next_node = head_->tail;
      delete head_;
      head_ = next_node;
    }
    delete head_;
  }

 public:
  ///                 <----------List Functions---------->
  list() : head_(new TNode()), size_(0U){};
  explicit list(size_type n) : head_(new TNode()), size_(n) {
    for (; n > 0U; --n) {
      new TNode(head_);
    }
  };
  list(std::initializer_list<value_type> const &items)
      : head_(new TNode()), size_(items.size()) {
    TNode *node = head_;
    for (auto item : items) {
      node = new TNode(item, node);
    }
  };
  list(const list &l) : head_(new TNode()), size_(l.size_) {
    TNode *node = head_;
    for (auto item = l.begin(); item != l.end(); ++item) {
      node = new TNode(*item, node);
    }
  }
  list(list &&l) noexcept : head_(l.head_), size_(l.size_) {
    l.size_ = 0;
    l.head_ = new TNode();
  }
  list &operator=(list &&l) noexcept {
    ClearNodes();

    size_ = l.size_;
    head_ = l.head_;

    l.size_ = 0;
    l.head_ = new TNode();

    return *this;
  }
  ~list() { ClearNodes(); }

  ///                 <----------List Element access---------->
  [[nodiscard]] const_reference front() const noexcept {
    return head_->tail->value;
  }
  [[nodiscard]] const_reference back() const noexcept {
    return head_->head->value;
  }

  ///                 <----------List Iterators---------->
  iterator begin() noexcept { return iterator(head_->tail); }
  const_iterator begin() const noexcept { return const_iterator(head_->tail); }
  iterator end() noexcept { return iterator(head_); }
  const_iterator end() const noexcept { return const_iterator(head_); }

  ///                 <----------List Capacity---------->
  [[nodiscard]] bool empty() const noexcept { return size_ == 0U; };
  [[nodiscard]] size_type size() const noexcept { return size_; };
  [[nodiscard]] size_type max_size() const noexcept {
    return std::numeric_limits<size_type>::max() / sizeof(TNode) / 2U;
  };

  ///                 <----------List Modifiers---------->
  void clear() {
    ClearNodes();
    head_ = new TNode();
  };
  iterator insert(iterator pos, const_reference value) {
    new TNode(value, pos.head->head);
    ++size_;
    return --pos;
  }
  void erase(iterator pos) noexcept {
    if (size_ > 0U) {
      pos.head->DeAttach();
      delete pos.head;
      --size_;
    }
  }
  void push_back(const_reference value) {
    new TNode(value, head_->head);
    ++size_;
  }
  void pop_back() noexcept { erase(--end()); }
  void swap(list &other) noexcept {
    std::swap(head_, other.head_);
    std::swap(size_, other.size_);
  }
  void push_front(const_reference value) {
    new TNode(value, head_);
    ++size_;
  }
  void pop_front() noexcept { erase(begin()); }
  void merge(list &other) {
    if (this != &other) {
      auto this_it = begin();
      auto other_it = other.begin();
      auto this_end = end();
      auto other_end = other.end();

      while (this_it != this_end && other_it != other_end) {
        if (*this_it <= *other_it) {
          ++this_it;
        } else {
          TNode *node = other_it.head;
          ++other_it;

          ++size_;
          --other.size_;
          node->ReAttach(this_it.head->head);
        }
      }

      splice(end(), other);
    }
  }
  void splice(const_iterator pos, list &other) noexcept {
    if (this != &other && other.size_ > 0U) {
      auto cur_node = const_cast<TNode *>(pos.head)->head;

      other.head_->head->tail = cur_node->tail;
      other.head_->tail->head = cur_node;

      cur_node->tail->head = other.head_->head;
      cur_node->tail = other.head_->tail;

      size_ += other.size_;

      other.size_ = 0;
      other.head_->head = other.head_;
      other.head_->tail = other.head_;
    }
  }
  void reverse() noexcept {
    auto tmp_nodes = head_;
    do {
      auto next_node = tmp_nodes->tail;
      std::swap(tmp_nodes->tail, tmp_nodes->head);
      tmp_nodes = next_node;
    } while (tmp_nodes != head_);
  }
  void unique() noexcept {
    for (iterator last_it = begin(), cur_it = ++begin(); cur_it != end();) {
      if (*last_it == *cur_it) {
        erase(cur_it);
        cur_it = last_it + 1;
      } else {
        ++last_it;
        ++cur_it;
      }
    }
  }
  void sort() noexcept { InsertionSort(begin(), end()); }

  template <class... Args>
  iterator emplace(const_iterator pos, Args &&...args) {
    auto head = const_cast<TNode *>(pos.head)->head;

    for (auto item : {std::forward<Args>(args)...}) {
      head = new TNode(item, head);
    }

    size_ += sizeof...(args);
    return iterator(head);
  }

  template <class... Args>
  void emplace_back(Args &&...args) {
    emplace(end(), args...);
  }

  template <class... Args>
  void emplace_front(Args &&...args) {
    emplace(begin(), args...);
  }

 private:
  void InsertionSort(iterator start, iterator end) {
    for (iterator i = start + 1; i != end; ++i) {
      value_type &temp = i.head->value;
      iterator j = i - 1;
      iterator k = i;
      while (j.head->value > temp) {
        j.swap(k);
        if (j == start) {
          break;
        } else {
          --k;
          --j;
        }
      }
    }
  }
};

}  // namespace s21

#endif  // CPPCONTAINERS_LIST_H
