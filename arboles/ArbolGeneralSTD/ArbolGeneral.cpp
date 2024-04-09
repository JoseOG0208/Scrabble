#include "ArbolGeneral.h"
#include <queue>

template <class T>
ArbolGeneral<T>::ArbolGeneral(){
  raiz = nullptr;
}

template <class T>
ArbolGeneral<T>::ArbolGeneral(T& val){
    raiz = val;
}

template <class T>
bool ArbolGeneral<T>::esVacio(){
    return raiz == nullptr;
}

template <class T>
NodoGeneral<T>* ArbolGeneral<T>::getRaiz(){
    return raiz;
}

template <class T>
void ArbolGeneral<T>::setRaiz(NodoGeneral<T>* nraiz){
    raiz = nraiz;
}

template <class T>
bool ArbolGeneral<T>::insertarNodo(T& padre, T& n){
    if ()
}


