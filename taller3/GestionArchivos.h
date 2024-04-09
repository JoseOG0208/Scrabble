#ifndef GESTIONARCHIVOS_H   
#define GESTIONARCHIVOS_H
#include <string>
#include "Cancion.h"
#include "Sistema.h"

 class GestionArchivos{
  public:  
    static void leerArchivoCanciones(std:: string nombreArchivo, Sistema* sistema);
    static Cancion* procesarLineaCancion(std::string linea);
};

#endif

