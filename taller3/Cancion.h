#ifndef CANCION_H
#define CANCION_H

#include <string>

class Cancion {
    
protected:
    static int contador;
    int id;
    std::string titulo;
    std::string album;
    std::string genero;
    std::string artista;

public:
    // ructores
    Cancion();
    Cancion(std::string titulo,  std::string album,  std::string genero,  std::string artista);

    // Getters
    int getId() ;
    std::string getTitulo() ;
    std::string getAlbum() ;
    std::string getGenero() ;
    std::string getArtista() ;

    // Setters
    void setId(int id);
    void setTitulo( std::string titulo);
    void setAlbum( std::string album);
    void setGenero( std::string genero);
    void setArtista( std::string artista);
};

#endif
