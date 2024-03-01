    #include <iostream>
    #include <cstring>
    #include "Sistema.h"
    #include "ProcesadorComandos.h"
    using namespace std;
    int main() {
        Sistema ayudaScrabble;
        char *entrada = new char[1024];
        ayudaScrabble.recibirComando(entrada);
    }