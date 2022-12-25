#ifndef CPPCONTAINERS_TREE_H
#define CPPCONTAINERS_TREE_H

#include <iostream>
#include <limits>
#include <vector>

namespace s21 {

template <class T>
class tree {
 public:
  class TreeIterator;
  class TreeIteratorConst;

 public:
  using key_type = T;
  using value_type = key_type;
  using cosnt_value_type = const key_type;
  using iterator = TreeIterator;
  using const_iterator = TreeIteratorConst;
  using size_type = size_t;

 public:
  struct TreeNode {
    TreeNode *parent_;
    TreeNode *left_elem_;
    TreeNode *right_elem_;
    value_type value_;
    bool is_fake = false;

    explicit TreeNode()
        : parent_(nullptr),
          left_elem_(nullptr),
          right_elem_(nullptr),
          value_(value_type{}) {}
    explicit TreeNode(const value_type &value)
        : parent_(nullptr),
          left_elem_(nullptr),
          right_elem_(nullptr),
          value_(value) {}
  };

  class TreeIterator {
   public:
    using iterator_category = std::bidirectional_iterator_tag;

   public:
    TreeNode *curr_node;

    TreeIterator() = delete;

    explicit TreeIterator(TreeNode *elem) : curr_node(elem) {}

    value_type &operator*() noexcept { return curr_node->value_; }

    bool operator==(const TreeIterator &other) const noexcept {
      return curr_node == other.curr_node;
    }

    bool operator!=(const TreeIterator &other) const noexcept {
      return curr_node != other.curr_node;
    }

    TreeIterator &operator++() noexcept {
      IteratorPlus();
      return *this;
    }

    TreeIterator operator++(int) noexcept {
      iterator *n = this;
      IteratorPlus();
      return *n;
    }

    TreeIterator &operator--() noexcept {
      IteratorMinus();
      return *this;
    }

    TreeIterator operator--(int) noexcept {
      iterator *n = this;
      IteratorMinus();
      return *n;
    }

   private:
    void IteratorPlus() {
      if (curr_node->right_elem_) {
        curr_node = curr_node->right_elem_;
        while (curr_node->left_elem_) {
          curr_node = curr_node->left_elem_;
        }
      } else {
        TreeNode *buff = curr_node;
        curr_node = curr_node->parent_;
        while (buff == curr_node->right_elem_ && !curr_node->is_fake) {
          buff = curr_node;
          curr_node = curr_node->parent_;
        }
      }
    }
    void IteratorMinus() {
      if (curr_node->left_elem_) {
        curr_node = curr_node->left_elem_;
        while (curr_node->right_elem_) {
          curr_node = curr_node->right_elem_;
        }
      } else {
        TreeNode *buff = curr_node;
        curr_node = curr_node->parent_;
        while (buff == curr_node->left_elem_) {
          buff = curr_node;
          curr_node = curr_node->parent_;
        }
      }
    }
  };

  class TreeIteratorConst {
   public:
    using iterator_category = std::bidirectional_iterator_tag;

   public:
    TreeNode *curr_node;

    TreeIteratorConst() = delete;
    TreeIteratorConst(TreeIterator &it) : curr_node(it.curr_node) {}
    TreeIteratorConst(TreeIterator &&it) : curr_node(it.curr_node) {}
    explicit TreeIteratorConst(TreeNode *elem) : curr_node(elem) {}
    cosnt_value_type &operator*() noexcept { return curr_node->value_; }

    bool operator==(const TreeIterator &other) const noexcept {
      return curr_node == other.curr_node;
    }

    bool operator!=(const TreeIterator &other) const noexcept {
      return curr_node != other.curr_node;
    }

    TreeIteratorConst &operator++() noexcept {
      IteratorPlus();
      return *this;
    }

    TreeIteratorConst operator++(int) noexcept {
      iterator *n = this;
      IteratorPlus();
      return *n;
    }

    TreeIteratorConst &operator--() noexcept {
      IteratorMinus();
      return *this;
    }

    TreeIteratorConst operator--(int) noexcept {
      iterator *n = this;
      IteratorMinus();
      return *n;
    };

   private:
    void IteratorPlus() {
      if (curr_node->right_elem_) {
        curr_node = curr_node->right_elem_;
        while (curr_node->left_elem_) {
          curr_node = curr_node->left_elem_;
        }
      } else {
        TreeNode *buff = curr_node;
        curr_node = curr_node->parent_;
        while (buff == curr_node->right_elem_ && !curr_node->is_fake) {
          buff = curr_node;
          curr_node = curr_node->parent_;
        }
      }
    }
    void IteratorMinus() {
      if (curr_node->left_elem_) {
        curr_node = curr_node->left_elem_;
        while (curr_node->right_elem_) {
          curr_node = curr_node->right_elem_;
        }
      } else {
        TreeNode *buff = curr_node;
        curr_node = curr_node->parent_;
        while (buff == curr_node->left_elem_) {
          buff = curr_node;
          curr_node = curr_node->parent_;
        }
      }
    }
  };

 private:
  TreeNode *root_node;
  TreeNode *fake;
  size_type tree_size;

 public:
  tree() : fake(new TreeNode()), tree_size(0) { root_is_fake(); }

  tree(const tree &other) : tree() { copy_tree(other.root_node); }

  tree(tree &&other) noexcept
      : root_node(other.root_node),
        fake(other.fake),
        tree_size(other.tree_size) {
    other.root_node = nullptr;
    other.fake = nullptr;
    other.tree_size = 0;
  }

  ~tree() {
    if (root_node != fake) destroy_node(root_node);
    delete fake;
  }

  tree &operator=(tree &&other) noexcept {
    root_node = other.root_node;
    fake = other.fake;
    tree_size = other.tree_size;

    other.root_node = nullptr;
    other.fake = nullptr;
    other.tree_size = 0;

    return *this;
  }

  [[nodiscard]] iterator begin() noexcept {
    return TreeIterator(fake->right_elem_);
  }
  [[nodiscard]] iterator end() noexcept { return TreeIterator(fake); }

  [[nodiscard]] const_iterator begin() const noexcept {
    return TreeIteratorConst(fake->right_elem_);
  }
  [[nodiscard]] const_iterator end() const noexcept {
    return TreeIteratorConst(fake);
  }

  [[nodiscard]] bool empty() const noexcept { return root_node == fake; }
  [[nodiscard]] size_type size() const noexcept { return tree_size; }
  [[nodiscard]] size_type max_size() const noexcept {
    return std::numeric_limits<size_type>::max() / sizeof(TreeNode) / 2;
  };

  void clear() {
    if (!empty()) {
      destroy_node(root_node);
      root_is_fake();
    }
  }

  virtual std::pair<iterator, bool> insert(const value_type &value) {
    return auto_insert(value, true);
  }

  void erase(iterator pos) noexcept {
    TreeNode *curr_pos = pos.curr_node;
    if (curr_pos == fake->left_elem_) {
      iterator buff = pos;
      --buff;
      fake->left_elem_ = buff.curr_node;
    } else if (curr_pos == fake->right_elem_) {
      iterator buff = pos;
      ++buff;
      fake->right_elem_ = buff.curr_node;
    }
    if (!curr_pos->left_elem_ && !curr_pos->right_elem_) {
      if (curr_pos->parent_ == fake) {
        root_is_fake();
      } else if (curr_pos == curr_pos->parent_->left_elem_) {
        curr_pos->parent_->left_elem_ = nullptr;
      } else {
        curr_pos->parent_->right_elem_ = nullptr;
      }
    } else if (!curr_pos->right_elem_) {
      if (curr_pos->parent_ == fake) {
        fake->parent_ = curr_pos->left_elem_;
        curr_pos->left_elem_->parent_ = fake;
        root_node = curr_pos->left_elem_;
      } else if (curr_pos == curr_pos->parent_->left_elem_) {
        curr_pos->parent_->left_elem_ = curr_pos->left_elem_;
        curr_pos->left_elem_->parent_ = curr_pos->parent_;
      } else {
        curr_pos->parent_->right_elem_ = curr_pos->left_elem_;
        curr_pos->left_elem_->parent_ = curr_pos->parent_;
      }
    } else if (!curr_pos->left_elem_) {
      if (curr_pos->parent_ == fake) {
        fake->parent_ = curr_pos->right_elem_;
        curr_pos->right_elem_->parent_ = fake;
        root_node = curr_pos->right_elem_;
      } else if (curr_pos == curr_pos->parent_->left_elem_) {
        curr_pos->parent_->left_elem_ = curr_pos->right_elem_;
        curr_pos->right_elem_->parent_ = curr_pos->parent_;

      } else {
        curr_pos->parent_->right_elem_ = curr_pos->right_elem_;
        curr_pos->right_elem_->parent_ = curr_pos->parent_;
      }
    } else {
      iterator buff = pos;
      ++pos;
      std::swap(buff.curr_node->value_, pos.curr_node->value_);
      if (buff.curr_node->right_elem_ == pos.curr_node) {
        buff.curr_node->right_elem_ = pos.curr_node->right_elem_;
      } else {
        pos.curr_node->parent_->left_elem_ = pos.curr_node->right_elem_;
      }
    }
    --tree_size;
    delete pos.curr_node;
  }

  void swap(tree &other) noexcept {
    std::swap(root_node, other.root_node);
    std::swap(fake, other.fake);
    std::swap(tree_size, other.tree_size);
  }

  void merge(tree &other) { default_merge(other, other.root_node); }

  iterator find(const key_type &key) noexcept {
    TreeNode *sol = find_contains(key);
    if (sol->value_ != key) return iterator(nullptr);
    return iterator(sol);
  }

  [[nodiscard]] bool contains(const key_type &key) noexcept {
    TreeNode *sol = find_contains(key);
    return !(!sol || sol->value_ != key);
  }

 protected:
  std::pair<iterator, bool> auto_insert(const value_type &value, bool multi) {
    if (!multi && contains(value)) {
      iterator find_sol = find(value);
      return std::make_pair(find_sol, false);
    }
    iterator iter = default_insert(value);
    return std::make_pair(iter, true);
  }

  void default_merge(tree &other, TreeNode *item) {
    if (item->right_elem_) default_merge(other, item->right_elem_);
    if (item->left_elem_) default_merge(other, item->left_elem_);
    insert(item->value_);
    auto iter = iterator(item);
    other.erase(iter);
  }

  iterator default_insert(const value_type &value) {
    auto *new_node = new TreeNode(value);
    if (root_node == fake) {
      root_node = new_node;
      fake->parent_ = new_node;
      fake->left_elem_ = new_node;
      fake->right_elem_ = new_node;
      new_node->parent_ = fake;
    } else {
      TreeNode *buff = root_node;
      while (true) {
        if (buff->value_ > new_node->value_) {
          if (buff->left_elem_) {
            buff = buff->left_elem_;
          } else {
            buff->left_elem_ = new_node;
            new_node->parent_ = buff;
            if (fake->right_elem_->value_ > new_node->value_) {
              fake->right_elem_ = new_node;
            }
            break;
          }
        } else {
          if (buff->right_elem_) {
            buff = buff->right_elem_;
          } else {
            buff->right_elem_ = new_node;
            new_node->parent_ = buff;
            if (fake->left_elem_->value_ < new_node->value_) {
              fake->left_elem_ = new_node;
            }
            break;
          }
        }
      }
    }
    ++tree_size;
    return TreeIterator(new_node);
  }

  TreeNode *find_contains(const key_type &key) {
    if (empty()) return nullptr;
    TreeNode *current = root_node;
    while (true) {
      if (current == nullptr) {
        return nullptr;
      } else if (current->value_ == key) {
        return current;
      } else if (current->value_ > key) {
        if (!current->left_elem_) return current;
        current = current->left_elem_;
      } else {
        if (!current->right_elem_) return current;
        current = current->right_elem_;
      }
    }
  }

  void destroy_node(TreeNode *root) {
    if (root->left_elem_) destroy_node(root->left_elem_);
    if (root->right_elem_) destroy_node(root->right_elem_);
    delete root;
  }

  void root_is_fake() {
    fake->is_fake = true;

    fake->parent_ = fake;
    fake->left_elem_ = fake;
    fake->right_elem_ = fake;
    root_node = fake;
    tree_size = 0;
  }

  void copy_tree(const TreeNode *other) {
    default_insert(other->value_);
    if (other->left_elem_) copy_tree(other->left_elem_);
    if (other->right_elem_) copy_tree(other->right_elem_);
  }

  TreeNode *ret_root() noexcept { return root_node; }
};

}  // namespace s21

#endif  // CPPCONTAINERS_TREE_H
