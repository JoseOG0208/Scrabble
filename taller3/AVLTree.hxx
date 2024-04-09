#ifndef __AVLTREE__HXX__
#define __AVLTREE__HXX__

#include "AVLTree.h"
#include <iostream>
#include <algorithm>

template<class T>
AVLTree<T>::AVLTree(){
    this->root = nullptr;
}

template<class T>
AVLTree<T>::AVLTree(T newRoot){
    AVLNode <T>* node = new AVLNode<T>;
    node->setData(newRoot);
    this->root = node; 
}

template<class T>
bool AVLTree<T>::empty(){
    return root == nullptr;
}

template<class T>
AVLNode<T>* AVLTree<T>::getRoot(){
    return this->root;
}

template<class T>
int AVLTree<T>::height(){
    if (this->empty()){
        return 0;
    }
    else{
        return this->height(this->getRoot());
    }
}

template<class T>
int AVLTree<T>::height(AVLNode<T>* node){
    //si el arbol esta vacio, retorno
    if (node == nullptr){
        return 0;
    }
    

    int leftHeight = height(node->getLeftChild());
    int rightHeight = height(node->getRightChild());
    return 1 + std::max(leftHeight, rightHeight); 
}

template<class T>
int AVLTree<T>::size(AVLNode<T>* node){
    if (this->empty()){
        return -1;
    }
    
    int leftSize = size(node->getLeftChild());
    int rightSize = size(node->getRightChild());
    return 1 + leftSize + rightSize; 
}

template<class T>
int AVLTree<T>::size(){
    if (this->empty()){
        return -1;
    }

    return size(this->getRoot()); 
}

template <class T>
int AVLTree<T>::balanceFactor(AVLNode<T>* node) {
  if (node == nullptr)
    return 0;
  return height(node -> getLeftChild()) - height(node -> getRightChild());
}

template <class T>
AVLNode <T>* AVLTree<T>::rightRotate(AVLNode<T> * y) {
  AVLNode<T>* x = y -> getLeftChild();
  AVLNode<T>* T2 = x -> getRightChild();

  // Rotación
  x -> setRightChild(y);
  y -> setLeftChild(T2);

  // Actualización de alturas
  y -> setHeight(std::max(height(y -> getLeftChild()), height(y -> getRightChild())) + 1);
  x -> setHeight(std::max(height(x -> getLeftChild()), height(x -> getRightChild())) + 1);

  return x;
}

template <class T>
AVLNode<T> * AVLTree<T>::leftRotate(AVLNode<T> * x) {
  AVLNode<T> * y = x -> getRightChild();
  AVLNode<T> * T2 = y -> getLeftChild();

  // Rotación
  y ->setLeftChild(x);
  x -> setRightChild(T2);

  // Actualización de alturas
  x -> setHeight(std::max(height(x -> getLeftChild()), height(x -> getRightChild())) + 1);
  y -> setHeight(std::max(height(y -> getLeftChild()), height(y -> getRightChild())) + 1);

  return y;
}

template <class T>
AVLNode<T> * AVLTree<T>::insertNode(AVLNode<T> * node, T val) {
  // Insertar nodo de forma normal (BST)
  if (node == nullptr) {
    AVLNode<T>* newNode = new AVLNode<T>(val);
    newNode -> setHeight(1);  
    return newNode;
  }
    

  if (val < node -> getData())
    node -> setLeftChild(insertNode(node -> getLeftChild(), val));
  else if (val > node -> getData())
    node -> setRightChild(insertNode(node -> getRightChild(), val));
  else // Valores duplicados no son permitidos en un árbol AVL
    return node;

  // Actualizar altura del nodo actual
  
  node -> setHeight(1 + std::max(height(node -> getLeftChild()), height(node -> getRightChild())));

  // Obtener el factor de equilibrio de este nodo
  int balance = balanceFactor(node);

  // Casos de desequilibrio
  // Caso Izquierda - Izquierda
  if (balance > 1 && val < node -> getLeftChild() -> getData())
    return rightRotate(node);

  // Caso Derecha - Derecha
  if (balance < -1 && val > node -> getRightChild() -> getData())
    return leftRotate(node);

  // Caso Izquierda - Derecha
  if (balance > 1 && val > node -> getLeftChild() -> getData()) {
    node -> setLeftChild(leftRotate(node -> getLeftChild()));  
    return rightRotate(node);
  }

  // Caso Derecha - Izquierda
  if (balance < -1 && val < node -> getRightChild() -> getData()) {
    node -> setRightChild(rightRotate(node -> getRightChild()));  
    return leftRotate(node);
  }

  // El nodo está equilibrado
  return node;
}
template <class T>
bool AVLTree<T>::insert(T val) {
  AVLNode<T>* oldRoot = root;
  root = insertNode(root, val);
  return oldRoot != root;
}

template <typename T>
AVLNode<T>* AVLTree<T>::minValueNode(AVLNode<T>* node) {
    AVLNode<T>* current = node;
    while (current->getLeftChild() != nullptr)
        current = current->getLeftChild();
    return current;
}

template <typename T>
AVLNode<T>* AVLTree<T>::deleteNode(AVLNode<T>* root, T val) {
    if (root == nullptr)
        return root;

    if (val < root->getData())
        root->setLeftChild(deleteNode(root->getLeftChild(), val));
    else if (val > root->getData())
        root->setRightChild(deleteNode(root->getRightChild(), val));
    else {
        if (root->getLeftChild() == nullptr || root->getRightChild() == nullptr) {
            AVLNode<T>* temp = root->getLeftChild() ? root->getLeftChild() : root->getRightChild();

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;

            delete temp;
        } else {
            AVLNode<T>* temp = minValueNode(root->getRightChild());
            root->setData(temp->getData());
            root->setRightChild(deleteNode(root->getRightChild(), temp->getData()));  
        }
    }

    if (root == nullptr)
        return root;

    root->setHeight(1 + std::max(height(root->getLeftChild()), height(root->getRightChild())));

    int balance = balanceFactor(root);

    if (balance > 1 && balanceFactor(root->getLeftChild()) >= 0)
        return rightRotate(root);

    if (balance > 1 && balanceFactor(root->getLeftChild()) < 0) {
        root->setLeftChild(leftRotate(root->getLeftChild()));
        return rightRotate(root);
    }

    if (balance < -1 && balanceFactor(root->getRightChild()) <= 0)
        return leftRotate(root);

    if (balance < -1 && balanceFactor(root->getRightChild()) > 0) {
        root->setRightChild(rightRotate(root->getRightChild()));
        return leftRotate(root);
    }

    return root;
}

template <typename T>
void AVLTree<T>::deleteNode(T val) {
        //AVLNode<T>* oldRoot = root;
        root = deleteNode(root, val);
}

template <typename T>
bool AVLTree<T>::search(T val, AVLNode<T>* node) {
    if (node == nullptr)
        return false;
    if (val == node->getData())
        return true;
    if (val < node->getData())
        return search(val, node->getLeftChild());
    else
        return search(val, node->getRightChild());
}

template <typename T>
bool AVLTree<T>::search(T val) {
    return search(val, root);
}

template <typename T>
void AVLTree<T>::preOrder(AVLNode<T>* node) {
    //caso base, que la raiz sea nula 
    if (node == nullptr){
        return;
    }
    std::cout<<node -> getData()<<" ";
    preOrder(node->getLeftChild());
    preOrder(node->getRightChild());
}

template <typename T>
void AVLTree<T>::preOrder(){
    preOrder(this->root);
}

template <typename T>
void  AVLTree<T>::posOrder(AVLNode<T>* node){
    if (node == nullptr)
        return;
 
    // First recur on left subtree
    posOrder(node->getLeftChild());
 
    // Then recur on right subtree
    posOrder(node->getRightChild());
 
    // Now deal with the node
    std::cout << node->getData() << " ";
}

template <typename T>
void AVLTree<T>::posOrder(){
    posOrder(this->root);
}
template <typename T>
void AVLTree<T>::inOrder(AVLNode<T>* node){
    if (node == nullptr){
        return;
    }
    inOrder(node->getLeftChild());
    std::cout<<node->getData()<<" ";
    inOrder(node->getRightChild()); 
}

template <typename T>
void AVLTree<T>::inOrder(){
    inOrder(this->root);
}

template <typename T>
void AVLTree<T>::levelOrder(AVLNode<T>* node){
    int h = height(node);
    for(int i = 1; i <= h; i++){
        currentLevel(node, i);
    }
}

template <typename T>
void AVLTree<T>::levelOrder(){
    levelOrder(root);
}

template <typename T>
void AVLTree<T>::currentLevel(AVLNode<T>* node, int level){
    if (root == NULL)
        return;
    if (level == 1)
        std::cout << node->getData()<< " ";
    else if (level > 1) {
        currentLevel(node->getLeftChild(), level - 1);
        currentLevel(node->getRightChild(), level - 1);
    }
}


#endif
