#ifndef LETRA_H   
#define LETRA_H


class Letra {

    int puntaje;
    char valor; 
    std::string palabra;
    int puntajePalabra;

public:
    Letra();
    Letra (char v);
    int getPuntaje();
    void setPuntaje(int puntaje);
    char getValor(); 
    void setValor(char v); 
    int calcularPuntaje (char v); 
    void setPalabraPuntaje(int n);
    int getPuntajePalabra();
    void setPalabra(std::string palabra);
    bool verificarValor();
    std::string getPalabra();
    friend bool operator==(Letra letra1, Letra letra2);
};

 bool operator==(Letra letra1, Letra letra2);
#include "Letra.cpp"
#endif