#include "Diccionario.h"
#include <iostream>
#include <string> 
// Constructor por defecto
Diccionario::Diccionario() {}

// Constructor con parámetro
Diccionario::Diccionario(std::list<Palabra> palabras) {
    this->palabras = palabras;
}

// Getter para obtener las palabras
std::list<Palabra> Diccionario::getPalabras()  {
    return palabras;
}

// Setter para establecer las palabras
void Diccionario::setPalabras(std::list<Palabra> palabras) {
    this->palabras = palabras;
}

void Diccionario::agregarPalabra(Palabra palabra){
    palabras.push_back(palabra);
}

std::string Diccionario::imprimirPalabras(){
    std::string aux;
    for (Palabra p : palabras){
        aux += " " + p.imprimirLetras();
    }
    return aux;
};
