#ifndef CPPCONTAINERS_LIST_H
#define CPPCONTAINERS_LIST_H

#include <cstdio>
#include <initializer_list>
#include "../node/node.h"
#include <limits>

namespace s21 {

template <class T>
class list {
 public:
  ///                 <----------List Member type---------->
  using value_type = T;
  using reference [[maybe_unused]] = value_type &;
  using const_reference = const value_type &;
  using size_type = std::size_t;
  using iterator = NodeIterator<T>;
  using const_iterator = NodeIterator<const T>;
  using TNode = Node<value_type>;  // Template Node

 private:
  TNode *head_node_;
  size_type size_;
  void ClearNodes() {
    if (head_node_) {
      head_node_->head->tail = nullptr;
      while (head_node_) {
        TNode *next_node = head_node_->tail;
        delete head_node_;
        head_node_ = next_node;
      }
    }
  }

 public:
  ///                 <----------List Functions---------->
  list() : head_node_(new TNode()), size_(0){};
  explicit list(size_type n) : head_node_(new TNode()), size_(n) {
    if (n <= 0) return;

    do {
      // head_node_->head -> last_elem
      // head_node_ -> end
      //
      auto *new_node = new TNode(head_node_->head, head_node_);
      head_node_->head->tail = new_node;
      head_node_->head = new_node;
    } while (--n);
  };
  list(std::initializer_list<value_type> const &items)
      : head_node_(new TNode()), size_(items.size()) {
    for (auto item : items) {
      auto new_node = new TNode(item, head_node_->head, head_node_);
      head_node_->head->tail = new_node;
      head_node_->head = new_node;
    }
  };
  list(const list &l) : head_node_(new TNode()), size_(l.size_) {
    for (iterator item = l.begin(); item != l.end(); ++item) {
      auto new_node = new TNode(*item, head_node_->head, head_node_);
      head_node_->tail->tail = new_node;
      head_node_->head = new_node;
    }
  }
  list(list &&l) noexcept : size_(l.size_), head_node_(l.head_node_) {
    l.size_ = 0;
    l.head_node_ = nullptr;
  }
  ~list() { ClearNodes(); }
  list &operator=(list &&l) noexcept {
    ClearNodes();

    size_ = l.size_;
    head_node_ = l.head_node_;

    l.size_ = 0;
    l.head_node_ = nullptr;

    return *this;
  }

  ///                 <----------List Element access---------->
  [[nodiscard]] const_reference front() const noexcept {
    return head_node_->tail->data;
  }
  [[nodiscard]] const_reference back() const noexcept {
    return head_node_->head->data;
  }

  ///                 <----------List Iterators---------->
  iterator begin() noexcept { return iterator(head_node_->tail); }
  iterator end() noexcept { return iterator(head_node_); }

  ///                 <----------List Capacity---------->
  [[nodiscard]] bool empty() const noexcept { return !size_; };
  [[nodiscard]] size_type size() const noexcept { return size_; };
  [[nodiscard]] size_type max_size() const noexcept {
    return std::numeric_limits<size_type>::max() / sizeof(TNode) / 2;
  };

  ///                 <----------List Modifiers---------->
  void clear() {
    ClearNodes();

    head_node_ = new TNode();
    size_ = 0;
  };
  iterator insert(iterator pos, const_reference value) {
    auto new_node = new TNode(value, pos.GetNode()->head, pos.GetNode());
    pos.GetNode()->head->tail = new_node;
    pos.GetNode()->head = new_node;

    ++size_;

    return --pos;
  }
  void erase(iterator pos) {
    if (size_) {
      pos.GetNode()->tail->head = pos.GetNode()->head;
      pos.GetNode()->head->tail = pos.GetNode()->tail;
      delete pos.GetNode();

      --size_;
    }
  }
  void push_back(const_reference value) noexcept {
    auto new_node = new TNode(value, head_node_->head, head_node_);
    head_node_->head->tail = new_node;
    head_node_->head = new_node;

    ++size_;
  }
  void pop_back() noexcept {
    if (size()) {
      TNode *end = head_node_->head;

      head_node_->head = end->head;
      end->head->tail = head_node_;

      delete end;  // указываем
      --size_;
    }
  }
  void swap(list &other) noexcept {
    std::swap(head_node_, other.head_node_);
    std::swap(size_, other.size_);
  }
  void push_front(const_reference value) noexcept {
    auto new_node = new TNode(value, head_node_, head_node_->tail);
    head_node_->tail->head = new_node;
    head_node_->tail = new_node;

    ++size_;
  }
  void pop_front() noexcept {
    if (size()) {
      TNode *front = head_node_->tail;

      head_node_->tail = front->tail;
      front->tail->head = head_node_;

      delete front;  // указываем
      --size_;
    }
  }
  void merge(list &other) {
    if (*this != other) {
      if (!size()) {
        auto this_front = begin();
        auto this_end = end();

        for (auto other_front = other.begin(); other_front != other.end();) {
          if (this_front == this_end) {
            push_back(*other_front);
          } else if (*this_front < *other_front) {
            ++this_front;
          } else {
            insert(this_front, *other_front);
            ++other_front;
          }
        }
      }
      size_ += other.size();
      if (other.size()) other.clear();
    }
  }
  void splice(const_iterator pos, list &other) {
    TNode *cur_node = pos.GetNode();
    if (*this != other) {
      for (auto other_front = other.begin(); other_front != other.end();
           ++other_front) {
        other_front.GetNode()->head = cur_node;
        other_front.GetNode()->tail = cur_node->tail;

        cur_node->tail->head = other_front;
        cur_node->tail = other_front;

        cur_node = other_front.GetNode();
        ++size_;
      }
    }
  }
  void reverse() {
    auto tmp_nodes = head_node_;
    do {
      auto next_node = tmp_nodes->tail;
      std::swap(tmp_nodes->tail, tmp_nodes->head);
      tmp_nodes = next_node;
    } while (tmp_nodes != head_node_);
  }
  void unique() {
    for (auto last_iter = begin(), iter_node = ++begin(); iter_node != end();) {
      if (*(last_iter) == *iter_node) {
        TNode *remove_node = iter_node.GetNode();
        ++iter_node;

        remove_node->head->tail = remove_node->tail;
        remove_node->tail->head = remove_node->head;
        delete remove_node;

        --size_;
      } else {
        ++last_iter;
        ++iter_node;
      }
    }
  }
  void sort();
};

}  // namespace s21

#endif  // CPPCONTAINERS_LIST_H
