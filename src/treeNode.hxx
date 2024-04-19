#include "treeNode.h"

template<typename T>
TreeNode<T>::TreeNode(T value) : data(value) {}

template<typename T>
TreeNode<T>::TreeNode(): data(), children(std::list<TreeNode<T>*>()){}


template<typename T>
TreeNode<T>::~TreeNode() {
    for (TreeNode* child : children)
        delete child;
}


template<typename T>
std::list<TreeNode<T>*> TreeNode<T>::getChildren() {
    return children;
}

template<typename T>
std::list<TreeNode<T>*>* TreeNode<T>::getChildrenRef() {
        return &children;
}

template<typename T>
T TreeNode<T>::getData() {
    return this->data;
}