//
// Created by Nana Daughterless on 11/15/22.
//

#ifndef CPPCONTAINERS_NODE_H
#define CPPCONTAINERS_NODE_H

#include <initializer_list>
#include <stdexcept>

namespace s21 {

template <class T>
struct Node {
  using value_type = T;
  using reference = value_type&;
  using TNode = Node<value_type>;

  TNode* head;
  TNode* tail;
  value_type data;

  explicit Node(TNode* head = nullptr, TNode* tail = nullptr)
      : head((head) ? head : this), tail((tail) ? tail : this), data() {}
  explicit Node(reference value, TNode* head = nullptr, TNode* tail = nullptr)
      : data(value), head((head) ? head : this), tail((tail) ? tail : this){};
};

template <class T>
class NodeIterator {
 public:
  using value_type = T;
  using TNode = Node<T>;

 private:
  // TODO(think) Может быть не очень удачным решением сделать её публичным
  TNode* head_node_;

 public:
  // Head -> end node (когда делается вставка, обнавляется последний элемент)
  // Tail -> first element
  NodeIterator() : head_node_(new TNode()) {}
  explicit NodeIterator(TNode* head_node) noexcept : head_node_(head_node) {}
  TNode* GetNode() { return head_node_; };
  NodeIterator<value_type>& operator++() noexcept {
    head_node_ = head_node_->tail;
    return *this;
  }
  NodeIterator<value_type>& operator--() noexcept {
    head_node_ = head_node_->head;
    return *this;
  }
  bool operator==(const NodeIterator<value_type>& other) const noexcept {
    TNode* this_head = head_node_;
    TNode* other_head = other.head_node_;

    while (this_head == other_head) {
      this_head = this_head->tail;
      other_head = other_head->tail;
      if (head_node_->head == this_head || other.head_node_->head == other_head)
        break;
    }

    return this_head == other_head;
  }
  bool operator!=(const NodeIterator<value_type>& other) const noexcept {
    return !(*this == other);
  }
  value_type operator*() const noexcept { return head_node_->tail->data; }
};

}  // namespace s21

#endif  // CPPCONTAINERS_NODE_H
