#ifndef Sistema_H   
#define Sistema_H
#include "Tree.h"
#include "Diccionario.h"

class Sistema{
    Diccionario diccionarioNormal;
    Diccionario diccionarioInverso;
    Tree<Letra> arbolNormal;
    Tree<Letra> arbolInverso; 

    public:
    Sistema();
    Sistema (Diccionario dN, Diccionario dI);
    Diccionario getDiccionarioInverso();
    void setDiccionarioInverso(Diccionario dI);
    Diccionario getDiccionarioNormal();
    void setDiccionarioNormal(Diccionario dN);
    void recibirComando( char* comando); 
    //Otros método 
    void ayuda ();
    void ayudaComando (const char* comandoAyuda);
}; 
#include "Sistema.cpp"
#endif