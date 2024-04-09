#ifndef AVLTREE_H
#define AVLTREE_H

#include "AVLNode.h"
template <class T>

class AVLTree {

protected:
  AVLNode<T> *root;

public:
  AVLTree();
  AVLTree(T newRoot);
  bool empty();
  AVLNode<T>* getRoot();
  int height();
  int height(AVLNode<T> *node);
  int size(AVLNode<T> *node);
  int size();
  int balanceFactor(AVLNode<T> *node);
  AVLNode<T> *rightRotate(AVLNode<T> *y);
  AVLNode<T> *leftRotate(AVLNode<T> *x);
  AVLNode<T> *insertNode(AVLNode<T> *node, T val);
  bool insert(T val);
  AVLNode<T>* minValueNode(AVLNode<T>* node);
  AVLNode<T>* deleteNode(AVLNode<T>* root, T val);
  void deleteNode(T val);
  bool search(T val, AVLNode<T>* node);
  bool search(T val);
  void preOrder();
  void preOrder(AVLNode<T>* node);
  void inOrder(AVLNode<T>* node);
  void inOrder();
  void posOrder();
  void posOrder(AVLNode<T>* node); 
  void levelOrder();
  void levelOrder(AVLNode<T>* node);
  void currentLevel(AVLNode<T>* root, int level);

};
 #include "AVLTree.hxx"
#endif