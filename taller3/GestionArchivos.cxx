#include "GestionArchivos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

void GestionArchivos::leerArchivoCanciones(std::string nombreArchivo, Sistema* sistema){
        std::ifstream archivo(nombreArchivo);
        if (!archivo.is_open()){
            std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
            return;
        }
        std::string linea;
        Cancion* cancionAgregar;
        while (std::getline(archivo, linea)) {
            cancionAgregar = procesarLineaCancion(linea);
            sistema->agregarPorTitulo(*cancionAgregar);
        }

        // Cerrar el archivo
        archivo.close();
}

Cancion* GestionArchivos::procesarLineaCancion(std::string linea){
    std::istringstream ss(linea);
    std::string dato;
    Cancion* c = new Cancion;
    std::getline(ss, dato, ','); c->setTitulo(dato);
    std::getline(ss, dato, ','); c->setAlbum(dato);
    std::getline(ss, dato, ','); c->setGenero(dato);
    std::getline(ss, dato, ','); c->setArtista(dato);
    return c;
}