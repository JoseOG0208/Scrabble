#ifndef PROCESADORCOMANDOS_H   
#define PROCESADORCOMANDOS_H
#include <string>
#include "Diccionario.h"

 class ProcesadorComandos{
  public:  
    static Diccionario inicializarDiccionario(std::string rutaDiccionario);
    static void inicializarDiccionarioInverso(std::string rutaDiccionario);
    static void puntajePalabra(std::string palabra);
    static bool verificarPalabra(std::string palabra);
    static int calcularPuntaje(std::string palabra);
    static std::string enMinuscula(std::string palabra); 

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