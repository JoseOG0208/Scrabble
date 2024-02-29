#ifndef LETRA_H   
#define LETRA_H


class Letra {

    int puntaje;
    char valor; 

public:
    Letra();
    Letra (char v);
    int getPuntaje();
    void setPuntaje(int puntaje);
    char getValor(); 
    void setValor(char v); 
    int calcularPuntaje (char v); 
};

#endif