#include "Letra.h"


     Letra::Letra(){
        puntaje = 0;
    }

    Letra::Letra(char v){
        setPuntaje(calcularPuntaje(v));
        setValor(v);
    }

    // Getter para obtener el puntaje
    int Letra::getPuntaje() {
        return puntaje;
    }

    // Setter para establecer el puntaje
    void Letra::setPuntaje(int puntaje) {
        puntaje = puntaje;
    }

    // Getter para obtener el valor
    char Letra::getValor() {
        return valor;
    }

    // Setter para establecer el valor
    void Letra::setValor(char v) {
        valor = v;
    }

    int Letra::calcularPuntaje (char v){
    if (v == 'A' || v == 'E' || v == 'I' || v == 'L' || v == 'N' || v == 'O' || v == 'R' || v == 'S' || v == 'T' || v == 'U') {
        puntaje = 1;
    } else if (v == 'D' || v == 'G') {
        puntaje = 2;
    } else if (v == 'B' || v == 'C' || v == 'M' || v == 'P') {
        puntaje = 3;
    } else if (v == 'F' || v == 'H' || v == 'V' || v == 'W' || v == 'Y') {
        puntaje = 4;
    } else if (v == 'K') {
        puntaje = 5;
    } else if (v == 'J' || v == 'X') {
        puntaje = 8;
    } else if (v == 'Q' || v == 'Z') {
        puntaje = 10;
    }
    return puntaje;

    }
