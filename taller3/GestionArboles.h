#ifndef GESTIONARBOLES_H   
#define GESTIONARBOLES_H
#include <string>
#include "cancion.h"
#include "AVLTree.h"

 class GestionArboles{
  public:  
    
    static bool agregarCancion(AVLNode<Cancion>* raizArbol, Cancion cancionAgregar);
    static bool eliminarCancion(AVLNode<Cancion>* raizArbol);
    static bool buscarPorTitulo(std::string tituloBuscar);
    static bool buscarPorArtista(std::string artistaBuscar);
    static bool buscarPorGenero(std::string generoBuscar);
    static bool buscarPorAlbum(std::string albumBuscar);
};

#endif