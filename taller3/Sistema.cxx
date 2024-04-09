#include <iostream>
#include "Sistema.h"
#include "Cancion.h"
#include "AVLTree.hxx"
#include "AVLTree.h"
#include "AVLNode.h"
#include "AVLNode.hxx"
#include "Titulo.h"


Sistema::Sistema(){}

AVLTree<Titulo> Sistema::getPorTitulo(){
    return this->porTitulo; 
}
bool Sistema::agregarCancion (Cancion cancionAgregar){
   return agregarPorTitulo(cancionAgregar);
}

bool Sistema::agregarPorTitulo(Cancion cancion){
    Titulo t; 
    t.setTitulo(cancion.getTitulo());
    t.getCanciones().push_back(cancion);
    return porTitulo.insert(t);
}

bool Sistema:: eliminarCancion(Cancion cancionEliminar){
    return eliminarPorTitulo(cancionEliminar);
}

bool Sistema::eliminarPorTitulo(Cancion cancionEliminar){
    
}