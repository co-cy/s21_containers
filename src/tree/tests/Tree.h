#include <iostream>

template <class T>
struct Node {
    Node<T> * parent_;
    Node<T> * leftElem_;
    Node<T> * rightElem_;
    T val;
    STree () : parent_(nullptr), leftElem_(nullptr), rightElem_(nullptrl);
};

template <class T, class Compare>
class Tree
{
private:
    Node<T> root;
    Node<T> fake; 
public:
    Tree(/* args */);
    ~Tree();
};
