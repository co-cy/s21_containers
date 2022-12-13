#ifndef CPPCONTAINERS_TREE_H
#define CPPCONTAINERS_TREE_H

#include <iostream>

template <class T>
class Tree {
 public:
  class TreeIterator;

 public:
  using key_type = T;
  using value_type = key_type;
  // using referense =
  // using const_referense =
  using iterator = TreeIterator;
  // using const_iterator =
  using size_type = size_t;

 public:
  struct TreeNode {
    TreeNode *parent_;
    TreeNode *left_elem_;
    TreeNode *right_elem_;
    value_type value_;
    bool is_fake = 0;
    TreeNode()
        : parent_(nullptr),
          left_elem_(nullptr),
          right_elem_(nullptr),
          value_(value_type{}) {}
    TreeNode(const value_type &value)
        : parent_(nullptr),
          left_elem_(nullptr),
          right_elem_(nullptr),
          value_(value) {}
  };

  class TreeIterator {
   public:
    using iterator_category = std::bidirectional_iterator_tag;
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

   public:
    TreeNode *curr_node;

    TreeIterator() = delete;
    // TreeIterator(const TreeIterator &other) : curr_node(other.curr_node) {}
    TreeIterator(TreeNode *elem) : curr_node(elem) {}
    value_type &operator*() { return curr_node->value_; }
    bool operator==(const TreeIterator &other) const {
      return curr_node == other.curr_node;
    }
    bool operator!=(const TreeIterator &other) const {
      return curr_node != other.curr_node;
    }
    TreeIterator &operator++() {
      IteratorPlus();
      return *this;
    }

    TreeIterator operator++(int) {
      TreeNode *n = curr_node;
      IteratorPlus();
      return n;
    }

    TreeIterator &operator--() {
      IteratorMinus();
      return *this;
    }
    TreeIterator operator--(int) {
      TreeNode *n = curr_node;
      IteratorMinus();
      return n;
    }
  };

  TreeNode *root_node;
  TreeNode *fake;
  size_type tree_size;

  void DestroyNode(TreeNode *root) {
    if (root->left_elem_) DestroyNode(root->left_elem_);
    if (root->right_elem_) DestroyNode(root->right_elem_);
    delete root;
  }

  void root_is_fake() {
    fake->is_fake = 1;
    fake->parent_ = fake;
    fake->left_elem_ = fake;
    fake->right_elem_ = fake;
    root_node = fake;
    tree_size = 0;
  }

  void copy_tree(const TreeNode *other) {
    default_insert(other->value_);
    if (other->left_elem_)
    copy_tree(other->left_elem_);
    if (other->right_elem_)
    copy_tree(other->right_elem_);
  }

 public:
  Tree() {
    fake = new TreeNode();
  
    root_is_fake();
  }
  Tree(std::initializer_list<value_type> const &items) {
    fake = new TreeNode();
    root_is_fake();
    for (value_type value: items) {}
  }
  Tree(const Tree &other) {
    fake = new TreeNode();
    root_is_fake();
    copy_tree(other.root_node);
  }
  Tree(Tree &&other)
      : root_node(other.root_node),
        fake(other.fake),
        tree_size(other.tree_size) {
    other.root_node = nullptr;
    other.fake = nullptr;
    other.tree_size = 0;
  }
  ~Tree() {
    if (root_node!=fake)
      DestroyNode(root_node);
    delete fake;
  }

  Tree &operator=(Tree &&other) {
    root_node = other.root_node;
    fake = other.fake;
    tree_size = other.tree_size;
    other.root_node = nullptr;
    other.fake = nullptr;
    other.tree_size = 0;
    return *this;
  }


  void tree_print(TreeNode *root = nullptr) {
    if (root == nullptr) root = root_node;
    if (root->left_elem_) tree_print(root->left_elem_);
    std::cout << "value = " << root->value_ << std::endl;
    if (root->parent_ && root->parent_ != fake)
      std::cout << "parent = " << root->parent_->value_ << std::endl;
    if (root->left_elem_)
      std::cout << "left elem = " << root->left_elem_->value_ << std::endl;
    if (root->right_elem_)
      std::cout << "right elem = " << root->right_elem_->value_ << std::endl;
    std::cout << std::endl;
    if (root->right_elem_) tree_print(root->right_elem_);
  }

  void fake_print() {
    std::cout << "lvalue = " << fake->left_elem_->value_<<std::endl;
    std::cout << "rvalue = " << fake->right_elem_->value_<<std::endl;
    std::cout << "root of fake = " << fake->parent_->value_<<std::endl;
  }


  iterator begin() { return TreeIterator(fake->right_elem_); }
  iterator end() { return TreeIterator(fake); }

  bool empty() { return root_node == fake; }
  size_type size() { return tree_size; }
  size_type max_size();

  void clear() {
    if (!empty()) {
      DestroyNode(root_node);
    }
    root_is_fake();
  }
  std::pair<iterator, bool> insert(const value_type &value) {
    iterator iter = default_insert(value);
    return std::make_pair(iter, true);
  }

  void erase(iterator pos) {
    TreeNode *curr_pos = pos.curr_node;
    if (curr_pos == fake->left_elem_) {
      iterator buff = pos;
      buff--;
      fake->left_elem_ = buff.curr_node;
    } else if (curr_pos == fake->right_elem_) {
      iterator buff = pos;
      buff++;
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

  void swap(Tree &other) {
    std::swap(root_node,other.root_node);
    std::swap(fake, other.fake);
    std::swap(tree_size,other.tree_size);
  }

  void merge(Tree &other) {
    default_merge(other,other.root_node);
    DestroyNode(other.root_node);
    other.root_is_fake();
  }

  iterator find(const key_type &key) {
    TreeNode *sol = find_contains(key);
    if (sol == nullptr) return nullptr;
    return iterator(sol);
  }
  bool contains(const key_type &key) {
    TreeNode *sol = find_contains(key);
    if (sol == nullptr) return false;
    return true;
  }

 protected:
  void default_merge(Tree & other, TreeNode * item) {
    insert(item->value_);
    auto iter = iterator(item);
    other.erase(iter);
    if (item->right_elem_)
      default_merge(other,item->right_elem_);
    if (item->left_elem_)
      default_merge(other,item->left_elem_);
  }

  iterator default_insert(const value_type &value) {
    TreeNode *new_node = new TreeNode(value);
    if (root_node == fake) {
      root_node = new_node;
      fake->parent_ = new_node;
      fake->left_elem_ = new_node;
      fake->right_elem_ = new_node;
      new_node->parent_ = fake;
    } else {
      TreeNode *buff = root_node;
      while (1) {
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
        current = current->left_elem_;
      } else {
        current = current->right_elem_;
      }
    }
  }
};

#endif  // CPPCONTAINERS_TREE_H
