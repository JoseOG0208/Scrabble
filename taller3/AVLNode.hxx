#ifndef __AVLNODE__HXX__
#define __AVLNODE__HXX__

#include "AVLNode.h"

template<class T>

AVLNode<T>::AVLNode()
{
  this->leftChild = nullptr;
  this->rightChild = nullptr;
}

template<class T>
AVLNode<T>::AVLNode(T value)
{
  this->data = value;
  this->leftChild = nullptr;
  this->rightChild = nullptr;
}

template<class T>
T& AVLNode<T>::getData(){
  return this->data;
}

template<class T>
void AVLNode<T>::setData(T& val){
  this->data = val;
}

template<class T>
AVLNode <T>* AVLNode<T>::getLeftChild(){
  return this->leftChild;
}

template<class T>
AVLNode <T>* AVLNode<T>::getRightChild(){
  return this->rightChild;
}

template<class T>
void AVLNode<T>::setLeftChild(AVLNode <T> *left){
  this->leftChild = left;
}

template<class T>
void AVLNode<T>::setRightChild(AVLNode <T> *right){
  this->rightChild = right;
}

template<class T>
int AVLNode<T>::getHeight(){
  return this->height;
}

template<class T>
void AVLNode<T>::setHeight(int h){
  this->height = h;
}

#include "AVLNode.hxx"
#endif