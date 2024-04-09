#include "NodoGeneral.h"

//Constructor
template <class T>

NodoGeneral<T>::NodoGeneral() {}

template <class T>

NodoGeneral<T>::~NodoGeneral() {}

template <class T>
T& NodoGeneral<T>::getDato(){
    return dato; 
}

template <class T>
void NodoGeneral<T>::setDato(T& val){
    dato = val;
}
template <class T>
void NodoGeneral<T>::limpiarLista(){
    for (auto& nodo : desc) {
        delete nodo;
    }
    desc.clear();
}
template <class T>
void NodoGeneral<T>::adicionarDesc(T& nval){
    NodoGeneral<T>* nuevoNodo = new NodoGeneral<T>();
    nuevoNodo->setDato(nval);
    desc.push_back(nuevoNodo);
}
template <class T>
void NodoGeneral<T>::eliminarDesc(T& val){
     for (auto it = desc.begin(); it != desc.end(); ++it) {
        if ((*it)->getDato() == val) {
            delete *it;
            desc.erase(it);
            break;
        }
    } 
}

template <class T>
int NodoGeneral<T>::getId(){
    return id;
}

template <class T>
void NodoGeneral<T>::setId(int nuevoId){
    id = nuevoId;
}