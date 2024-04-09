#ifndef Sistema_H   
#define Sistema_H
#include "Diccionario.h"

class Sistema{
    Diccionario diccionarioNormal;
    Diccionario diccionarioInverso;

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

#endif