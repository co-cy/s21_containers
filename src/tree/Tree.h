#ifndef CONTAINERS_TREE_H
#define CONTAINERS_TREE_H

#include <iostream>

template <class T>
class Tree {
   private:
    class TreeIterator;

   public:
    using key_type = T;
    using value_type = key_type;
    // using referense =
    // using const_referense =
    using iterator = TreeIterator;
    // using const_iterator =
    using size_type = size_t;

   private:
    struct TreeNode {
        TreeNode *parent_;
        TreeNode *left_elem_;
        TreeNode *right_elem_;
        value_type value_;
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

    class TreeIterator
        : public std::iterator<std::bidirectional_iterator_tag, T> {
       public:
        TreeNode *curr_node;

        TreeIterator() = delete;
        TreeIterator(const TreeIterator &other) : curr_node(other.curr_node) {}
        TreeIterator(TreeNode *elem) : curr_node(elem) {}
        value_type &operator*() { return curr_node->value_; }
        bool operator==(const TreeIterator &other) const {
            return curr_node == other.curr_node;
        }
        bool operator!=(const TreeIterator &other) const {
            return curr_node != other.curr_node;
        }
        TreeIterator &operator++() {
            if (curr_node->right_elem_) {
                curr_node = curr_node->right_elem_;
                while (curr_node->left_elem_) {
                    curr_node = curr_node->left_elem_;
                }
            } else {
                TreeNode *buff = curr_node;
                curr_node = curr_node->parent_;
                while (buff == curr_node->right_elem_) {
                    buff = curr_node;
                    curr_node = curr_node->parent_;
                }
            }
            return *this;
        }

        TreeIterator operator++(int) {
            TreeNode *n = curr_node;
            if (curr_node->right_elem_) {
                curr_node = curr_node->right_elem_;
                while (curr_node->left_elem_) {
                    curr_node = curr_node->left_elem_;
                }
            } else {
                TreeNode *buff = curr_node;
                curr_node = curr_node->parent;
                while (buff == curr_node->right_elem_) {
                    buff = curr_node;
                    curr_node = curr_node->parent;
                }
            }
            return n;
        }

        TreeIterator &operator--() {
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
            return *this;
        }
        TreeIterator operator--(int) {
            TreeNode *n = curr_node;
            if (curr_node->left_elem_) {
                curr_node = curr_node->left_elem_;
                while (curr_node->rigthElem_) {
                    curr_node = curr_node->right_elem_;
                }
            } else {
                TreeNode buff = curr_node;
                curr_node = curr_node->parent;
                while (buff == curr_node->left_elem_) {
                    buff = curr_node;
                    curr_node = curr_node->parent_;
                }
            }
            return n;
        }
    };

    TreeNode *root_node;
    TreeNode *fake;
    size_type tree_size;

    void DestroyNode(TreeNode *root) {
        // std::cout << "Destructor start"<<std::endl;
        if (root->left_elem_) DestroyNode(root_node->left_elem_);
        if (root->right_elem_) DestroyNode(root_node->right_elem_);
        delete root;
    }

   public:
    TreeNode *get_root() { return root_node; }
    void tree_print(TreeNode *root) {
        if (root->left_elem_) tree_print(root->left_elem_);
        std::cout << root->value_ << std::endl;
        if (root->right_elem_) tree_print(root->right_elem_);
    }

    Tree() {
        fake = new TreeNode();
        fake->parent_ = fake;
        fake->left_elem_ = fake;
        fake->parent_ = fake;
        root_node = fake;
        tree_size = 0;
    }
    Tree(std::initializer_list<value_type> const &items);
    Tree(const Tree &other) {}
    Tree(Tree &&other)
        : root_node(other.root_node),
          fake(other.fake),
          tree_size(other.tree_size) {
        other.root_node = nullptr;
        other.fake = nullptr;
        other.tree_size = 0;
    }

    ~Tree() {
        std::cout << "Destructor start"<<std::endl;
        DestroyNode(root_node);
        std::cout << "Destructor end"<<std::endl;
        delete fake;

    }

    // Tree &operator=(Tree &&other) { return *this; }

    iterator begin() { return TreeIterator(fake->right_elem_); }
    iterator end() { return TreeIterator(fake); }

    bool empty() { return root_node == fake; }
    size_type size() { return tree_size; }
    size_type max_size();  //-

    void clear() {
        if (!empty()) {
            DestroyNode(root_node);
        }
        fake->parent_ = fake;
        fake->left_elem_ = fake;
        fake->parent_ = fake;
        root_node = fake;
        tree_size = 0;
    }
    std::pair<iterator, bool> insert(const value_type &value) {
        TreeNode *new_node = new TreeNode(value);
        if (root_node == fake) {
            root_node = new_node;
            fake->parent_ = root_node;
            fake->left_elem_ = root_node;
            fake->right_elem_ = root_node;
            root_node->parent_ = fake;
        } else {
            TreeNode *buff = root_node;
            while (1) {
                if (buff->value_ > new_node->value_) {
                    if (buff->left_elem_) {
                        buff = buff->left_elem_;
                    } else {
                        buff->left_elem_ = new_node;
                        new_node->parent_ = buff;
                        if (fake->left_elem_->value_ > new_node->value_) {
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
                        if (fake->right_elem_->value_ < new_node->value_) {
                            fake->left_elem_ = new_node;
                        }
                        break;
                    }
                }
            }
        }
        tree_size++;
        return std::make_pair(TreeIterator(new_node), true);
    }
    void erase(iterator pos) {
        if (!pos.curr_node->left_elem_ && !pos.curr_node->right_elem_) {
            if (pos.curr_node == pos.curr_node->parent_->left_elem_) {
                pos.curr_node->parent_->left_elem_ = nullptr;
            } else {
                pos.curr_node->parent_->right_elem_ = nullptr;
            }
        } else if (!pos.curr_node->right_elem_) {
            if (pos.curr_node == pos.curr_node->parent_->left_elem_) {
                pos.curr_node->parent_->left_elem_ = pos.curr_node->left_elem_;
            } else {
                pos.curr_node->parent_->right_elem_ = pos.curr_node->left_elem_;
            }
        } else if (!pos.curr_node->left_elem_) {
            if (pos.curr_node == pos.curr_node->parent_->left_elem_) {
                pos.curr_node->parent_->left_elem_ = pos.curr_node->right_elem_;
            } else {
                pos.curr_node->parent_->right_elem_ =
                    pos.curr_node->right_elem_;
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
        tree_size--;
        delete pos.curr_node;
    }

    void swap(Tree &other);
    void merge(Tree &other);

    // iterator find(const Key &key);
    // bool contains(const Key &key);
};

#endif  // CONTAINERS_TREE_H
