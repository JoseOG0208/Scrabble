#ifndef PROCESADORCOMANDOS_H   
#define PROCESADORCOMANDOS_H
#include <string>
#include "Diccionario.h"
#include "Tree.h"

 class ProcesadorComandos{
  public:  
    static Diccionario inicializarDiccionario(std::string rutaDiccionario);
    static Diccionario inicializarDiccionarioInverso(std::string rutaDiccionario);
    static int puntajePalabra(std::string palabra, std::list<Palabra> palabrasInversas, std::list<Palabra> palabrasNormales);
    static int calcularPuntaje(std::string palabra);
    static std::string enMayuscula(std::string palabra); 
    static bool validarPalabra(std::string palabra);

    //Métodos de Búsqueda de Palabras
    static void iniciarArbolDiccionario(std::string pathDiccionario, Tree<Letra>* arbolNormal);
    static void iniciarArbolDiccionarioInverso( std::string pathDiccionario, Tree<Letra>* arbolNormal);
    static void buscarPalabrasPorPrefijo(TreeNode<Letra>* root, std::string prefijo, std::list<std::string> palabrasEncontradas);
    static void palabrasPorSufijo( std::string sufijo, TreeNode<Letra>* root);

    //Métodos de Combinaciones de Letras
    static void grafoDePalabras();
    static void posiblesPalabras( std::string letras);

    static void insertarPalabraArbol(std::string palabra, Tree<Letra>* arbolNormal);
    static void pruebaPalabrasPrefijo(std::string prefijo, TreeNode<Letra>* root);
    static TreeNode<Letra>* buscarNodo(TreeNode<Letra>* nodo, char c);
    static void recorrerHojas(TreeNode<Letra>* nodo);
    static void recorrerHojasInverso(TreeNode<Letra>* nodo);
};
#include "ProcesadorComandos.cpp"
#endif