#include "Tree.h"
#include <vector>


template<typename T>
Tree<T>::Tree(T rootValue) {
    root = new TreeNode<T>(rootValue);
}

template<typename T>
Tree<T>::Tree() {
    root = new TreeNode<T>();
}

template<typename T>
Tree<T>::~Tree() {
    delete root;
}

template<typename T>
TreeNode<T>* Tree<T>::getRoot() {
    return root;
}

template<typename T>
void Tree<T>::addChild(TreeNode<T>* parent, T value) {
    TreeNode<T>* newNode = new TreeNode<T>(value);
    parent->children.push_back(newNode);
}

template<typename T>
void Tree<T>::traverse(TreeNode<T>* node) {
    if (node == nullptr)
        return;
    std::cout << node->data << " ";
    for (TreeNode<T>* child : node->children)
        traverse(child);
}

template<typename T>
void Tree<T>::traverse() {
    traverse(root);
}

template<typename T>
TreeNode<T>* Tree<T>::insert(TreeNode<T>* nodo, T data) {
    for (TreeNode<T>* n: nodo->getChildren()){
            if (n->getData() == data){
                return n;
            }
        }
    TreeNode<T>* nuevoNodo = new TreeNode<T>(data);
    nodo->getChildrenRef()->push_back(nuevoNodo);
    return nuevoNodo; 
}



