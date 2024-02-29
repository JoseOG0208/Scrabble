#ifndef Diccionario_H   
#define Diccionario_H
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
    bool verificarPalabra(std::string palabra);

};

#endif