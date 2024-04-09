#ifndef TITULO_H
#define TITULO_H

#include <string>
#include <list>
#include "Cancion.h"

class Titulo {

protected:
    std::string titulo;
    std::list<Cancion> canciones;

public:
    std::string getTitulo();
    void setTitulo(std::string nuevoTitulo);
    std::list<Cancion> getCanciones();
    void setCanciones( std::list<Cancion> nuevasCanciones);
    friend bool operator<(Titulo titulo1, Titulo titulo2);
    friend bool operator>(Titulo titulo1, Titulo titulo2);

};

bool operator<(Titulo titulo1, Titulo titulo2);
bool operator>(Titulo titulo1, Titulo titulo2);

#endif