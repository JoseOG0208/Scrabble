#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

// Declaraciones de funciones
void inicializarDiccionario(const std::string& rutaDiccionario);
void inicializarDiccionarioInverso(const std::string& rutaDiccionario);
void puntajePalabra(const std::string& palabra);
void mostrarAyuda();
void procesarComando(const std::string& comando);

// Diccionario principal donde la clave es la palabra y el valor es la puntuación
std::map<std::string, int> diccionario;

int main() {
    std::string comando;
    std::cout << "Sistema de Ayuda de Scrabble" << std::endl;
    std::cout << "Escribe 'ayuda' para desplegar la lista de comandos." << std::endl;

    // Bucle principal de comandos
    while (true) {
        std::cout << "$ ";
        std::getline(std::cin, comando);

        // Verificar si el usuario desea salir
        if (comando == "salir") {
            break;
        }

        // Procesar el comando
        procesarComando(comando);
    }

    return 0;
}

void inicializarDiccionario(const std::string& rutaDiccionario) {
    // Implementación pendiente
    std::cout << "Diccionario inicializado correctamente desde " << rutaDiccionario << std::endl;
}

void inicializarDiccionarioInverso(const std::string& rutaDiccionario) {
    // Implementación pendiente
    std::cout << "Diccionario inverso inicializado desde " << rutaDiccionario << std::endl;
}

void puntajePalabra(const std::string& palabra) {
    // Implementación pendiente
    std::cout << "Puntaje para la palabra '" << palabra << "': [puntaje]" << std::endl;
}

void mostrarAyuda() {
    std::cout << "Comandos disponibles:" << std::endl;
    std::cout << "  ayuda                    - Muestra este mensaje de ayuda" << std::endl;
    std::cout << "  inicializar diccionario.txt      - Inicializa el diccionario" << std::endl;
    std::cout << "  inicializar inverso.txt          - Inicializa el diccionario inverso" << std::endl;
    std::cout << "  puntaje_palabra [palabra]- Muestra el puntaje de una palabra" << std::endl;
    std::cout << "  salir                    - Sale del programa" << std::endl;
}

void procesarComando(const std::string& comando) {
    if (comando == "ayuda") {
        mostrarAyuda();
    } else if (comando == "iniciar_diccionario") {
        inicializarDiccionario("ruta/a/diccionario.txt");
    } else if (comando == "iniciar_inverso") {
        inicializarDiccionarioInverso("ruta/a/diccionario_inverso.txt"); // Actualizar cuando esté implementado
    } else if (comando.rfind("puntaje_palabra", 0) == 0) {
        std::string palabra = comando.substr(16); // Asumiendo que "puntaje_palabra " tiene 16 caracteres
        puntajePalabra(palabra);
    } else {
        std::cout << "Comando desconocido. Escribe 'ayuda' para ver la lista de comandos." << std::endl;
    }
}

