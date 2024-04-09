#include "Cancion.h"



int Cancion::contador = 0;
// ructor por defecto
Cancion::Cancion() {
    id = contador++;
    titulo = "";
    album = "";
    genero = "";
    artista = "";
}

// ructor con parámetros
Cancion::Cancion(std::string titulo,  std::string album,  std::string genero,  std::string artista) {
    id = ++contador;
    this->titulo = titulo;
    this->album = album;
    this->genero = genero;
    this->artista = artista;
}

// Getters
int Cancion::getId()  {
    return id;
}

std::string Cancion::getTitulo()  {
    return titulo;
}

std::string Cancion::getAlbum()  {
    return album;
}

std::string Cancion::getGenero()  {
    return genero;
}

std::string Cancion::getArtista()  {
    return artista;
}

// Setters
void Cancion::setId(int id) {
    this->id = id;
}

void Cancion::setTitulo( std::string titulo) {
    this->titulo = titulo;
}

void Cancion::setAlbum( std::string album) {
    this->album = album;
}

void Cancion::setGenero( std::string genero) {
    this->genero = genero;
}

void Cancion::setArtista( std::string artista) {
    this->artista = artista;
}
