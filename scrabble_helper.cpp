#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <unordered_map>
#include <cctype>

// Declaraciones de funciones
void inicializarDiccionario(const std::string& rutaDiccionario);
void inicializarDiccionarioInverso(const std::string& rutaDiccionario);
void puntajePalabra(const std::string& palabra);
void mostrarAyuda();
void procesarComando(const std::string& comando);
bool verificarPalabra(std::string palabra);
int calcularPuntaje(std::string palabra);
std::string enMinuscula(std::string palabra); 

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
    std::ifstream archivo(rutaDiccionario);
    if (!archivo.is_open()){
            std::cerr << "El archivo diccionario.txt no existe o no puede ser leído." << rutaDiccionario << std::endl;
            return;
    }
    std::string palabra;
    while (std::getline(archivo, palabra)) {
        if (verificarPalabra(palabra)){
            diccionario[enMinuscula(palabra)] = calcularPuntaje(palabra);
            std::cout<<"palabra: "<<palabra<<" "<<"puntaje: "<<diccionario[palabra];
            std::cout<<"Se agrego correctamente"<<std::endl; 
        }
        else{
            std::cout<<"La palabra: "<<palabra<<" no se agrego ya que contiene algun caracter invalido"<<std::endl;  
        }
    }
    
    // Cerrar el archivo
    archivo.close();
    std::cout << "Diccionario inicializado correctamente desde " << rutaDiccionario << std::endl;
    for (const auto& par : diccionario) {
        std::cout << "Clave: " << par.first << ", Valor: " << par.second << std::endl;
    }
    
    
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
        inicializarDiccionario("diccionario.txt");
    } else if (comando == "iniciar_inverso") {
        inicializarDiccionarioInverso("ruta/a/diccionario_inverso.txt"); // Actualizar cuando esté implementado
    } else if (comando.rfind("puntaje_palabra", 0) == 0) {
        std::string palabra = comando.substr(16); // Asumiendo que "puntaje_palabra " tiene 16 caracteres
        puntajePalabra(palabra);
    } else {
        std::cout << "Comando desconocido. Escribe 'ayuda' para ver la lista de comandos." << std::endl;
    }
}

int calcularPuntaje(std::string palabra){
      std::unordered_map<char, int> puntajes {
        {'E', 1}, {'A', 1}, {'I', 1}, {'O', 1}, {'N', 1},
        {'R', 1}, {'T', 1}, {'L', 1}, {'S', 1}, {'U', 1},
        {'D', 2}, {'G', 2},
        {'B', 3}, {'C', 3}, {'M', 3}, {'P', 3},
        {'F', 4}, {'H', 4}, {'V', 4}, {'W', 4}, {'Y', 4},
        {'K', 5},
        {'J', 8}, {'X', 8},
        {'Q', 10}, {'Z', 10}
    };

    int puntajePalabra = 0;
    for (int i = 0; i < palabra.length(); i++){
        puntajePalabra += puntajes[toupper(palabra[i])];
    }

    return puntajePalabra;
}

bool verificarPalabra(std::string palabra){
    for(int i = 0; i < palabra.length(); i++){
        if (!isalpha(palabra[i])){
            std::cout<<palabra[i]<<std::endl;
            return false;  
        }
    }
    return true;
}


std::string enMinuscula(std::string palabra){
    std::string palabraMinuscula; 
    for (int i = 0; i < palabra.length(); i++){
        palabraMinuscula[i] = tolower(palabra[i]);
    }
    return palabraMinuscula; 
}