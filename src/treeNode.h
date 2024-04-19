#ifndef TREENODE_H
#define TREENODE_H

#include <list>

template <typename T>
class TreeNode {
public:
    T data;
    std::list<TreeNode<T>*> children;
    TreeNode(T value);
    TreeNode();
    ~TreeNode();
    std::list<TreeNode<T>*> getChildren();
    std::list<TreeNode<T>*>* getChildrenRef();
    
    T getData();
};
#include "treeNode.hxx"
#endif // TREENODE_H
