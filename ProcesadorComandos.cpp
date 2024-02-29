#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <unordered_map>
#include <cctype>
#include "Diccionario.h"
#include "ProcesadorComandos.h"
#include "Palabra.h"



    Diccionario inicializarDiccionario( std::string rutaDiccionario) {
    std::ifstream archivo(rutaDiccionario);
    if (!archivo.is_open()){
            std::cerr << "El archivo diccionario.txt no existe o no puede ser leído." << rutaDiccionario << std::endl;
    }
    std::string palabra;
    Diccionario diccionarioNormal;
    while (std::getline(archivo, palabra)) {
        if (ProcesadorComandos::verificarPalabra(palabra)){
            Palabra p(palabra); 
            diccionarioNormal.agregarPalabra(p);
            std::cout<<"Se agrego correctamente"<<std::endl; 
        }
        else{
            std::cout<<"La palabra: "<<palabra<<" no se agrego ya que contiene algun caracter invalido"<<std::endl;  
        }
    }
    
    // Cerrar el archivo
    archivo.close();
    std::cout << "Diccionario inicializado correctamente desde " << rutaDiccionario << std::endl;
    return diccionarioNormal;
}


bool verificarPalabra(std::string palabra){
    for(int i = 0; i < palabra.length(); i++){
        if (!isalpha(palabra[i])){
            std::cout<<palabra[i]<<std::endl;
            return false;  
        }
    }
    return true;
}


std::string enMinuscula(std::string palabra){
    std::string palabraMinuscula; 
    for (int i = 0; i < palabra.length(); i++){
        palabraMinuscula[i] = tolower(palabra[i]);
    }
    return palabraMinuscula; 
}