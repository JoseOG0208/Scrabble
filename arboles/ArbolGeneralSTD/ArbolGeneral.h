#ifndef ARBOLGENERAL_H   
#define ARBOLGENERAL_H
#include <List>
#include "NodoGeneral.h"

template <class T>
class ArbolGeneral {
protected:
NodoGeneral<T>* raiz;

public:
ArbolGeneral();
ArbolGeneral(T& val);
~ArbolGeneral();
bool esVacio();
NodoGeneral<T>* getRaiz();
void setRaiz(NodoGeneral<T>* nraiz);
bool insertarNodo(T& padre, T& n);
bool eliminarNodo(T& n);
bool buscar(T& n);
unsigned int altura(...);
unsigned int tamano(...);
void preOrden(...);
void posOrden(...);
void nivelOrden(...);
};


#endif