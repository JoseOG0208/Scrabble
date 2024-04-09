#ifndef SISTEMA_H
#define SISTEMA_H

#include "Titulo.h"
#include "Cancion.h"
#include "AVLTree.h"
#include "AVLTree.hxx"

class Sistema {
private:
    AVLTree<Titulo> porTitulo;
public:
    Sistema();
    AVLTree<Titulo> getPorTitulo();    
    bool agregarCancion(Cancion cancionAgregar);
    bool agregarPorTitulo(Cancion cancionAgregar);
    bool eliminarCancion(Cancion cancionEliminar);
    bool eliminarPorTitulo(Cancion cancionEliminar);
};


#endif