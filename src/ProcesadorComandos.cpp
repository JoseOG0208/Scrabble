#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <algorithm>
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

void ProcesadorComandos::iniciarArbolDiccionario(std::string rutaDiccionario, Tree<Letra>* arbolInverso){
     std::ifstream archivo(rutaDiccionario);
    if (!archivo.is_open()){
            std::cerr << "El archivo "<<rutaDiccionario<<" no existe o no puede ser leido." << rutaDiccionario << std::endl;
    }
    std::string palabra;
    while (std::getline(archivo, palabra)) {
        insertarPalabraArbol(palabra, arbolInverso);
    }
    // Cerrar el archivo
    archivo.close();
    //std::cout << "Diccionario inicializado correctamente desde " << rutaDiccionario << std::endl;
}

void ProcesadorComandos::insertarPalabraArbol(std::string palabra, Tree<Letra>* arbol){
    //recorrer la palabra 
    TreeNode<Letra>* nodo = arbol->getRoot();
    int contador = 1;
    for (char c : palabra){
        Letra l(c);
        if (contador == palabra.length()){
            Palabra p(palabra);
            p.setPuntaje(p.calcularPuntaje());
            l.setPalabraPuntaje(p.getPuntaje());
            l.setPalabra(palabra);
        }
        nodo = arbol->insert(nodo, l);
        contador++;
    }
    //por cada letra crear una Letra
    //insertar en el arbol la Letra.
}
void ProcesadorComandos::iniciarArbolDiccionarioInverso(std::string rutaDiccionario, Tree<Letra>* arbolInverso){
    std::ifstream archivo(rutaDiccionario);
    if (!archivo.is_open()){
            std::cerr << "El archivo "<<rutaDiccionario<<" no existe o no puede ser leido." << rutaDiccionario << std::endl;
    }
    std::string palabra;
    while (std::getline(archivo, palabra)) {
        std::reverse(palabra.begin(), palabra.end());
        insertarPalabraArbol(palabra, arbolInverso);
    }
    // Cerrar el archivo
    archivo.close();
}

void ProcesadorComandos::buscarPalabrasPorPrefijo(TreeNode<Letra>* root, std::string prefijo, std::list<std::string> palabrasEncontradas){
    //pararme en la raiz
    //recorrer la lista de el nodo, 
    if (root == nullptr) {
        return;
    }
  // Recorrer el subárbol a partir del nodo correspondiente al prefijo
    TreeNode<Letra>* nodoActual = root;
    prefijo = enMayuscula(prefijo); 
    for (char letra: prefijo){
        bool encontrado = false;
        std::list<TreeNode<Letra>*>* listaHijos = nodoActual->getChildrenRef();
        
        for (auto it = (*listaHijos).begin(); it != (*listaHijos).end(); ++it){
            if((*it)->getData().getValor() == letra){
                nodoActual = *it;
                encontrado = true;
                break;
            }
        }
        if(!encontrado){
            std::cout<<"No se encontro el prefijo completo"<<std::endl;
            return;
        }
    }

    if (!nodoActual->getData().getPalabra().empty()) {
        palabrasEncontradas.push_back(prefijo);
    }
    for (TreeNode<Letra>* n: nodoActual->getChildren()){
        std::string palabraCompleta = prefijo + n->getData().getValor();
        buscarPalabrasPorPrefijo(n, palabraCompleta, palabrasEncontradas);
    }
    for (std::string palabra: palabrasEncontradas){
        Palabra p(palabra);
        p.setPuntaje(p.calcularPuntaje());
        std::cout<<"palabra: "<<palabra<<"Puntaje: "<<p.getPuntaje()<<"Longitud: "<<palabra.length()<<std::endl;
    }
}

void ProcesadorComandos::pruebaPalabrasPrefijo(std::string prefijo, TreeNode<Letra>* root){
    TreeNode<Letra>* nodoActual = root;
    prefijo = enMayuscula(prefijo); 
    //Recorro la lista de la raiz buscando la primera letra del prefijo
    for (char c: prefijo){
        nodoActual = buscarNodo(nodoActual, c);
        if (nodoActual == nullptr){
            std::cout<<"Prefijo " <<prefijo<< " no pudo encontrarse en el diccionario"<<std::endl;
            return;
        }
       
    }
    std::cout<<"Las palabras que terminan con este prefijo son: " <<std::endl;
    recorrerHojas(nodoActual);
}

void ProcesadorComandos::recorrerHojas(TreeNode<Letra>* nodo){
    if (nodo == nullptr)
        return;

    if (!nodo->getData().getPalabra().empty()) {
        // Si el nodo no tiene hijos, es una hoja
        
         std::cout<<"palabra: "<<nodo->getData().getPalabra()
                    <<" Puntaje: "<<nodo->getData().getPuntajePalabra()<<"Longitud: "<<nodo->getData().getPalabra().length()<<std::endl; // Imprime el valor de la hoja
    } else {
        // Si el nodo tiene hijos, recorre cada hijo de manera recursiva
        for (TreeNode<Letra>* hijo : nodo->getChildren()) {
            recorrerHojas(hijo);
        }
    }
}

TreeNode<Letra>* ProcesadorComandos::buscarNodo(TreeNode<Letra>* nodo, char c){
    std::list<TreeNode<Letra>*>* listaHijos = nodo->getChildrenRef();
    for (auto it = (*listaHijos).begin(); it != (*listaHijos).end(); ++it){
        if((*it)->getData().getValor() == c){
                nodo = *it;
                return nodo;
            }
    }
    nodo = nullptr;
    return nodo;
}

void ProcesadorComandos::palabrasPorSufijo(std::string sufijo, TreeNode<Letra>* root){
     TreeNode<Letra>* nodoActual = root;
    sufijo = enMayuscula(sufijo);
    std::reverse(sufijo.begin(), sufijo.end()); 
    //Recorro la lista de la raiz buscando la primera letra del prefijo
    for (char c: sufijo){
        nodoActual = buscarNodo(nodoActual, c);
        if (nodoActual == nullptr){
            std::reverse(sufijo.begin(), sufijo.end()); 
            std::cout<<"Sufijo " <<sufijo<< " no pudo encontrarse en el diccionario"<<std::endl;
            return;
        }
    }
    std::cout<<"Las palabras que terminan con este sufijo son: " <<std::endl;
    recorrerHojasInverso(nodoActual);
}

void ProcesadorComandos::recorrerHojasInverso(TreeNode<Letra>* nodo){
    if (nodo == nullptr)
        return;

    if (!nodo->getData().getPalabra().empty()) {
        // Si el nodo no tiene hijos, es una hoja
        std::string palabraImprimir; 
        palabraImprimir = nodo->getData().getPalabra();
        std::reverse(palabraImprimir.begin(), palabraImprimir.end());
         std::cout<<"palabra: "<<palabraImprimir
                    <<" Puntaje: "<<nodo->getData().getPuntajePalabra()<<" Longitud: "<<nodo->getData().getPalabra().length()<<std::endl; // Imprime el valor de la hoja
    } 
        // Si el nodo tiene hijos, recorre cada hijo de manera recursiva
        for (TreeNode<Letra>* hijo : nodo->getChildren()) {
            recorrerHojasInverso(hijo);
        }
}

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