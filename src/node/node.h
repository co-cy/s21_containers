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
  using const_reference = const value_type&;
  using TNode = Node<value_type>;

  TNode* head;  // Голова это Родительский блок (элемент слева)
  TNode* tail;  // Хвост это дочерний блок (элемент справа)
  value_type value;

  explicit Node(TNode* node = nullptr)
      : head(node ? node : this), tail(node ? node->tail : this), value() {
    if (node) {
      node->tail->head = this;
      node->tail = this;
    }
  }
  explicit Node(const_reference value, TNode* node = nullptr)
      : head(node ? node : this), tail(node ? node->tail : this), value(value) {
    if (node) {
      node->tail->head = this;
      node->tail = this;
    }
  }
  explicit Node(value_type&& value, TNode* node = nullptr)
      : head(node ? node : this), tail(node ? node->tail : this), value(value) {
    if (node) {
      node->tail->head = this;
      node->tail = this;
    }
  }

  void ReAttach(TNode* node) {
    head->tail = tail;
    tail->head = head;

    node->tail->head = this;
    tail = node->tail;
    node->tail = this;
    head = node;
  }

  void DeAttach() {
    tail->head = head;
    head->tail = tail;
  }
};

template <class T>
struct NodeIterator {
  using reference = T&;
  using TNode = Node<T>;

  TNode* head;

  NodeIterator() : head(nullptr){};
  explicit NodeIterator(TNode* head_node) : head(head_node) {}

  NodeIterator& operator++() noexcept {
    head = head->tail;
    return *this;
  }
  NodeIterator operator+(int k) noexcept {
    auto new_head = head;
    for (; k > 0; --k) {
      new_head = new_head->tail;
    }
    return NodeIterator(new_head);
  }
  NodeIterator& operator--() noexcept {
    head = head->head;
    return *this;
  }
  NodeIterator operator-(int k) noexcept {
    auto new_head = head;
    for (; k > 0; --k) {
      new_head = new_head->head;
    }
    return NodeIterator(new_head);
  }
  void swap(NodeIterator& other) {
    other.head->ReAttach(head->head);

    std::swap(head, other.head);
  }
  bool operator==(const NodeIterator& other) const noexcept {
    return head == other.head;
  }
  bool operator!=(const NodeIterator& other) const noexcept {
    return head != other.head;
  }
  reference operator*() noexcept { return head->value; }
};

template <class T>
struct NodeIteratorConst {
  using const_reference = const T&;
  using TNode = const Node<T>;

  TNode* head;

  NodeIteratorConst() : head(nullptr){};
  NodeIteratorConst(NodeIterator<T>& it) : head(it.head) {}
  NodeIteratorConst(NodeIterator<T>&& it) : head(it.head) {}
  explicit NodeIteratorConst(const TNode* head_node) : head(head_node) {}

  NodeIteratorConst& operator++() noexcept {
    head = head->tail;
    return *this;
  }
  NodeIteratorConst operator+(int k) noexcept {
    auto new_head = head;
    for (; k > 0; --k) {
      new_head = new_head->tail;
    }
    return NodeIteratorConst(new_head);
  }
  NodeIteratorConst& operator--() noexcept {
    head = head->head;
    return *this;
  }
  NodeIteratorConst operator-(int k) noexcept {
    auto new_head = head;
    for (; k > 0; --k) {
      new_head = new_head->head;
    }
    return NodeIteratorConst(new_head);
  }
  bool operator==(const NodeIteratorConst& other) const noexcept {
    return head == other.head;
  }
  bool operator!=(const NodeIteratorConst& other) const noexcept {
    return head != other.head;
  }
  const_reference operator*() const noexcept { return head->value; }
};

}  // namespace s21

#endif  // CPPCONTAINERS_NODE_H
