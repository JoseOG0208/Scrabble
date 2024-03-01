#ifndef PROCESADORCOMANDOS_H   
#define PROCESADORCOMANDOS_H
#include <string>
#include "Diccionario.h"

 class ProcesadorComandos{
  public:  
    static Diccionario inicializarDiccionario(std::string rutaDiccionario);
    static Diccionario inicializarDiccionarioInverso(std::string rutaDiccionario);
    static int puntajePalabra(std::string palabra, std::list<Palabra> palabrasInversas, std::list<Palabra> palabrasNormales);
    static int calcularPuntaje(std::string palabra);
    static std::string enMayuscula(std::string palabra); 
    static bool validarPalabra(std::string palabra);

    //Métodos de Búsqueda de Palabras
    static void iniciarArbolDiccionario( std::string pathDiccionario);
    static void iniciarArbolDiccionarioInverso( std::string pathDiccionario);
    static void palabrasPorPrefijo( std::string prefijo);
    static void palabrasPorSufijo( std::string sufijo);

    //Métodos de Combinaciones de Letras
    static void grafoDePalabras();
    static void posiblesPalabras( std::string letras);
};

#endif