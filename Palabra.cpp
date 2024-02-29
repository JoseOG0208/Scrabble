#include "Palabra.h"
#include"Letra.h"


// Constructor sin atributos
Palabra::Palabra(){}

// Constructor con atributos
Palabra::Palabra(std::list<Letra> _letras) {
    letras = _letras;
    puntaje = calcularPuntaje();
}

Palabra::Palabra(std::string cadena){
    for(int i = 0; i < cadena.length(); i++){
        Letra l(cadena[i]);
        letras.push_back(l);
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
void Palabra::setPuntaje(int puntaje) {
    puntaje = puntaje;
}


 std::list<Letra>Palabra::palabraInversa(){
    std::list<Letra> palabraInversa;
    //Recorrer lista de palabras hacia atras
    std::list<Letra>::reverse_iterator rit;
    for (rit = getLetras().rbegin(); rit != getLetras().rend(); ++rit) {
        //Guardar valor en la lista de palabras auc
        palabraInversa.push_back(*rit);
    }
    return palabraInversa;
}
int Palabra::calcularPuntaje(){
    std::list<Letra>::iterator it;
    int puntajePalabra;
    for (it = getLetras().begin(); it != getLetras().end(); ++it) {
        puntajePalabra += it ->getPuntaje();
    }    
    return puntajePalabra; 
}

void Palabra::agregarLetra(Letra l){
    letras.push_back(l);
}
