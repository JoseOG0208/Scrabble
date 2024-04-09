#ifndef AVLNODE_H
#define AVLNODE_H

template <class T>
class AVLNode {
  protected:
  T data;
  AVLNode <T> *leftChild;
  AVLNode <T> *rightChild;
  int height;

  public:
  AVLNode();
  AVLNode(T data);
  //~AVLNode();
  T& getData();
  void setData(T& val);
  AVLNode <T>* getLeftChild();
  AVLNode <T>* getRightChild();
  void setLeftChild(AVLNode <T> *left);
  void setRightChild(AVLNode <T> *right);
  void setHeight(int h);
  int getHeight();
};

#endif