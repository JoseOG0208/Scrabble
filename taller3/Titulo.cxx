#include "Titulo.h"




bool operator<(Titulo titulo1, Titulo titulo2) {
    return titulo1.getTitulo() < titulo2.getTitulo();
}

bool operator>(Titulo titulo1, Titulo titulo2) {
    return titulo1.getTitulo() > titulo2.getTitulo();
}


// Getter para el título
std::string Titulo::getTitulo()  {
    return titulo;
}

// Setter para el título
void Titulo::setTitulo(std::string nuevoTitulo) {
    titulo = nuevoTitulo;
}

// Getter para la lista de canciones
std::list<Cancion> Titulo::getCanciones()  {
    return canciones;
}

// Setter para la lista de canciones
void Titulo::setCanciones( std::list<Cancion> nuevasCanciones) {
    canciones = nuevasCanciones;
}




