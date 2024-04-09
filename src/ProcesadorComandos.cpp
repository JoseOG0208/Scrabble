#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include "Diccionario.h"
#include "ProcesadorComandos.h"



Diccionario ProcesadorComandos::inicializarDiccionario(std::string rutaDiccionario) {
    std::ifstream archivo(rutaDiccionario);
    if (!archivo.is_open()){
            std::cerr << "El archivo diccionario.txt no existe o no puede ser leído." << rutaDiccionario << std::endl;
    }
    std::string palabra;
    Diccionario diccionarioNormal;
    while (std::getline(archivo, palabra)) {
        Palabra p(palabra);
        p.setPuntaje(p.calcularPuntaje());
        //std::cout<<p.imprimirLetras()<<std::endl;
        diccionarioNormal.agregarPalabra(p);
        //std::cout<<"La palabra "<< palabra <<" fue agragada correctamente"<<std::endl; 
    }
    
    // Cerrar el archivo
    archivo.close();
    std::cout << "Diccionario inicializado correctamente " << std::endl;
    return diccionarioNormal;
}


std::string ProcesadorComandos::enMayuscula(std::string palabra){
    std::string palabraMayuscula = palabra; 
    for (int i = 0; i < palabra.length(); i++){
        palabraMayuscula[i] = toupper(palabra[i]);
    }
    return palabraMayuscula; 
}

Diccionario ProcesadorComandos::inicializarDiccionarioInverso(std::string rutaDiccionario){ 
    std::ifstream archivo(rutaDiccionario);
    if (!archivo.is_open()){
            std::cerr << "El archivo "<<rutaDiccionario<<"no existe o no puede ser leido." << rutaDiccionario << std::endl;
    }
    std::string palabra;
    Diccionario diccionarioInverso;
    while (std::getline(archivo, palabra)) {
            Palabra p(palabra);
            p.setLetras(p.palabraInversa());
            p.setPuntaje(p.calcularPuntaje());
            diccionarioInverso.agregarPalabra(p);
            //std::cout<<"LLego "<<std::endl;
            p.imprimirLetras();
            //std::cout<<"La palabra "<< palabra <<" fue agregada correctamente"<<std::endl;  
    }
    // Cerrar el archivo
    archivo.close();
    std::cout << "Diccionario inicializado correctamente desde " << rutaDiccionario << std::endl;
    return diccionarioInverso;
}

void ProcesadorComandos::iniciarArbolDiccionario( std::string pathDiccionario){}
void ProcesadorComandos::iniciarArbolDiccionarioInverso( std::string pathDiccionario){}
void ProcesadorComandos::palabrasPorPrefijo( std::string prefijo){}
void ProcesadorComandos::palabrasPorSufijo( std::string sufijo){}

//Métodos de Combinaciones de Letras
void ProcesadorComandos::grafoDePalabras(){}
void ProcesadorComandos::posiblesPalabras( std::string letras){}
int ProcesadorComandos::puntajePalabra(std::string palabra, std::list<Palabra> palabrasInversas, std::list<Palabra> palabrasNormales){
    std::list<Palabra>::iterator it;
    std::string palabraMayuscula = enMayuscula(palabra);
    for (it = palabrasInversas.begin(); it != palabrasInversas.end(); ++it){
        if (it->stringPalabra() == palabraMayuscula){
            return it->getPuntaje();
        }
    }

    for (it = palabrasNormales.begin(); it != palabrasNormales.end(); ++it){
        if (it->stringPalabra() == palabraMayuscula){
            return it->getPuntaje();
        }
    }
    return 0;
}

 bool ProcesadorComandos::validarPalabra(std::string palabra){
    for(int i = 0; i < palabra.length(); i++){
        if (!isalpha(palabra[i])){
            return false;
        }
    }
    return true;
}