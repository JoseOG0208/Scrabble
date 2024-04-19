#ifndef PALABRA_H   
#define PALABRA_H
#include <List>
#include "Letra.h"
#include <string>
class Palabra {
    std::list <Letra> letras;
    int puntaje;

 public:   
    Palabra();
    Palabra(std::list<Letra> _letras);
    Palabra(std::string cadena);
    void setLetras(std::list<Letra> _letras);
    std::list<Letra> getLetras();
    int getPuntaje();
    void setPuntaje(int puntaje);
    std::list<Letra>palabraInversa(); 
    int calcularPuntaje();
    void agregarLetra(Letra l);
    std::string imprimirLetras();
    std::string stringPalabra();
};

#include "Palabra.cpp"
#endif