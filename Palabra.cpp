#include "Palabra.h"
#include"Letra.h"
#include <iostream>


// Constructor sin atributos
Palabra::Palabra(){}

// Constructor con atributos
Palabra::Palabra(std::list<Letra> _letras) {
    letras = _letras;
    puntaje = 0;
}

Palabra::Palabra(std::string cadena){
    for(int i = 0; i < cadena.length(); i++){
        Letra l(cadena[i]);
        if(l.verificarValor()){
            letras.push_back(l);
            //std::cout<<"La letra fue agregada a la lista letras"<<std::endl;
        }
    }
}
// Getter para obtener las letras
std::list<Letra> Palabra::getLetras() {
    return letras;
}

// Setter para establecer las letras
void Palabra::setLetras(std::list<Letra> _letras) {
    letras = _letras;
}

int Palabra::getPuntaje() {
    return puntaje;
}

// Setter para establecer las letras
void Palabra::setPuntaje(int elPuntaje) {
    puntaje = elPuntaje;
}


 std::list<Letra>Palabra::palabraInversa(){
    std::list<Letra> palabraInversa;
    std::list <Letra> letras = getLetras();
    /*for (Letra l : letras){
        std::cout<<"Lista letras:"<<l.getValor()<<std::endl;
    }*/
    //Recorrer lista de palabras hacia atras
    std::list<Letra>::reverse_iterator rit;
    for (rit = letras.rbegin(); rit != letras.rend(); ++rit) {
        //Guardar valor en la lista de palabras auc
        palabraInversa.push_back(*rit);
    }
    /*for (Letra l : palabraInversa){
        std::cout<<"Lista letras:"<<l.getValor()<<std::endl;
    }
    */
    return palabraInversa;
}
int Palabra::calcularPuntaje(){
    std::list<Letra>::iterator it;
    std::list<Letra> letras = getLetras();
    int puntajePalabra = 0;
    for (it = letras.begin(); it != letras.end(); ++it) {
        puntajePalabra += it->getPuntaje();
    }     
    return puntajePalabra; 
}

void Palabra::agregarLetra(Letra l){
    letras.push_back(l);
}

std::string Palabra::imprimirLetras(){
    std::string palabra;
    for (Letra l : letras){
        //palabra += l.getValor() + " " + std::to_string(l.getPuntaje());
        palabra += l.getValor();
    }
    return palabra;
}

std::string Palabra::stringPalabra(){
    std::string palabra;
    for (Letra l : letras){
        palabra += l.getValor();
    }
    return palabra;
}
