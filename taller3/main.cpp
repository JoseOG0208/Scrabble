#include "Sistema.h"
//#include "AVLTree.hxx"
#include "AVLTree.h"
#include <iostream>

using namespace std;
    int main(){
    Sistema sistema;
    Cancion cancion1("a",  "x",  "y", "z");
    Cancion cancion2("b",  "x",  "y", "z");
    Cancion cancion3("c",  "x",  "y", "z");
    sistema.agregarCancion(cancion1);
    sistema.agregarCancion(cancion2);
    sistema.agregarCancion(cancion3);
    cout<<"raiz del arbol: "<<sistema.getPorTitulo().getRoot()->getData().getTitulo()<<endl;
    cout<<"hijo derecho: "<<sistema.getPorTitulo().getRoot()->getRightChild()->getData().getTitulo();
    return 0;
}