#ifndef TREE_H
#define TREE_H

#include "treeNode.h"
#include <iostream>

template <typename T>
class Tree {
private:
    TreeNode<T>* root;

    void traverse(TreeNode<T>* node);

public:
    Tree(T rootValue);
    Tree();
    ~Tree();
    void addChild(TreeNode<T>* parent, T value);
    void traverse();
    TreeNode<T>* insert(TreeNode<T>*nodo, T data);
    bool contieneLetra(char c);
    TreeNode<T>* getRoot();

    
};
#include "Tree.hxx"
#endif // TREE_H
