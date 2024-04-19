#ifndef DICCIONARIO_H   
#define DICCIONARIO_H
#include <List>
#include <String>
#include"Palabra.h"

class Diccionario {
    std::list <Palabra> palabras;

public:
    Diccionario();
    Diccionario (std::list <Palabra> palabras);
    std::list <Palabra> getPalabras();
    void setPalabras(std::list <Palabra> palabras);
    void agregarPalabra(Palabra palabra);
    std::string imprimirPalabras();
};
#include "Diccionario.cpp"
#endif