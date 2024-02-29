#include "Diccionario.h"
#include <iostream>
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

bool verificarPalabra(std::string palabra){
    for(int i = 0; i < palabra.length(); i++){
        if (!isalpha(palabra[i])){
            std::cout<<"La palabra contiene signos invalidos"<<std::endl;
            return false;  
        }
    }
    return true;
}