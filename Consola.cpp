#include "Consola.h"
#include "ProcesadorComandos.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>


void ayuda (){
    std::cout << "Lista de comandos permitidos:\n";
    std::cout << "1. inicializar diccionario.txt\n";
    std::cout << "2. iniciar_inverso diccionario.txt\n";
    std::cout << "3. puntaje palabra\n";
    std::cout << "4. iniciar_arbol diccionario.txt\n";
    std::cout << "5. iniciar_arbol_inverso diccionario.txt\n";
    std::cout << "6. palabras_por_prefijo prefijo\n";
    std::cout << "7. palabras_por_sufijo sufijo\n";
    std::cout << "8. grafo_de_palabras\n";
    std::cout << "9. posibles_palabras letras\n";
    std::cout << "10. cls\n";
    std::cout << "11. salir\n";
    std::cout<<std::endl;
}

void ayudaComando (const char* comandoAyuda){
    if (strcmp(comandoAyuda, "inicializar") == 0){
        std::cout<<"Uso comando: inicializar <archivo diccionario>"<<std::endl;
        std::cout<<"Descripcion: inicializa el sistema a partir del archivo <archivo diccionario>"<<std::endl;
    }
    else if (strcmp(comandoAyuda, "iniciar_inverso") == 0){
        std::cout<<"Uso comando: iniciar_inverso <archivo diccionario>"<<std::endl;
        std::cout<<"Descripcion: inicializa el sistema a partir del archivo <archivo diccionario>.\nAlmacena las palabras en sentido inverso"<<std::endl;
    }
    else if (strcmp(comandoAyuda, "puntaje") == 0){
        std::cout<<"Uso comando: puntaje <palabra>"<<std::endl;
        std::cout<<"Descripcion: el comando permite conocer la puntuacion que puede obtenerse de la <palabra>, de acuerdo a la tabla de puntuacion"<<std::endl;
    }
        else if (strcmp(comandoAyuda, "iniciar_arbol") == 0){
        std::cout<<"Uso comando: iniciar_arbol <archivo diccionario>"<<std::endl;
        std::cout<<"Descripcion: inicializa el sistema a partir del archivo <archivo diccionario>, lo hace en uno o mas arboles"<<std::endl;

    }
        else if (strcmp(comandoAyuda, "iniciar_arbol_inverso") == 0){
        std::cout<<"Uso comando: iniciar_arbol_inverso <archivo diccionario>"<<std::endl;
        std::cout<<"Descripcion: inicializa el sistema a partir del archivo <archivo diccionario>, lo hace en uno o mas arboles y en sentido inverso"<<std::endl;
    }
        else if (strcmp(comandoAyuda, "palabras_por_prefijo") == 0){
        std::cout<<"Uso coamando: palabras_por_prefijo <prefijo>"<<std::endl;
        std::cout<<"Descripcion: dado un prefijo de pocas letras, el comando recorre los arboles de letras para ubicar todas las palabras posibles a construir a partir de ese prefijo."<<std::endl;
    
    }
        else if (strcmp(comandoAyuda, "palabras_por_sufijo") == 0){
        std::cout<<"Uso comando: palabras_por_sufijo <sufijo>"<<std::endl;
        std::cout<<"Descripcion: dado un sufijo de pocas letras, el comando recorre los arboles de letras para ubicar todas las palabras posibles a construir a partir de ese sufijo."<<std::endl;
    
    }
        else if (strcmp(comandoAyuda, "grafo_de_palabras") == 0){
        std::cout<<"UUso comando: grafo_de_palabras "<<std::endl;
        std::cout<<"Descripcion: con las palabras ya almacenadas en el diccionario, construye un grafo de palabras, en donde cada palabra se conecta a las demas si y solo si difieren en una unica letra"<<std::endl;
    }
        else if (strcmp(comandoAyuda, "posibles_palabras") == 0){
        std::cout<<"Uso comando: posibles_palabras <cadena letras>"<<std::endl;
        std::cout<<"Descripcion: dadas <cadena letras>, presenta en pantalla todas las posibles palabras validas a construir, indicando la longitud de cada una y la puntuacion que se puede obtener con cada una."<<std::endl;
    }
        else if (strcmp(comandoAyuda, "cls") == 0){
        std::cout<<"Uso comando: cls"<<std::endl;
        std::cout<<"Descripcion: limpia la pantalla"<<std::endl;
    }
        else if (strcmp(comandoAyuda, "salir") == 0){
        std::cout<<"Uso comando: salir"<<std::endl;
        std::cout<<"Descripcion: Termina la ejecucion de la aplicacion."<<std::endl;
    }
    else{
        std::cout<<"Comando no reconocido"<<std::endl;
    }
    
std::cout<<std::endl;
}

void recibirComando(char* comando){
    while (true)
        {
            //Lógica y manejo de la entrada del usuario
            std::cout << "$";
            std::cin.getline(comando, 1024);
            // Verificar si la comando está vacía
            if (comando[0] == '\0') {
                //El comando se encuentra vacío
                continue;
            }

            char *copia = new char[1024];

            strcpy(copia, comando);
        
        
            //Variable donde se guardarán las diferentes palabras del comando ingresado, separado por " "
            char *comando1 = strtok(copia, " ");
            // Acceder a la segunda palabra
            char *comando2 = strtok(nullptr, " ");

            //Condicionales que determinan a qué función se llamará, dependiendo de los comandos ingresados.        
            //Métodos de Configuración del juego
            std::string parametro = comando2; 
            if (strcmp(comando1, "inicializar") == 0){
                if (comando2 != nullptr, ""){
                    ProcesadorComandos::inicializarDiccionario(parametro);
                }
            }
            else if (strcmp(comando1, "iniciar_inverso") == 0){
                    ProcesadorComandos::inicializarDiccionarioInverso(parametro);
            }
            else if (strcmp(comando1, "puntaje") == 0){
                    ProcesadorComandos::puntajePalabra(parametro);
            }

            //Métodos de Búsqueda de Palabras
            else if (strcmp(comando1, "iniciar_arbol") == 0){
                    ProcesadorComandos::iniciarArbolDiccionario(parametro);
            }        
            else if (strcmp(comando1, "iniciar_arbol_inverso") == 0){
                    ProcesadorComandos::iniciarArbolDiccionarioInverso(parametro);
            }
            else if (strcmp(comando1, "palabras_por_prefijo") == 0){
                    ProcesadorComandos::palabrasPorPrefijo(parametro);
            }
            else if (strcmp(comando1, "palabras_por_sufijo") == 0){
                    ProcesadorComandos::palabrasPorSufijo(parametro);
            }


            //Métodos de Combinaciones de Letras
            else if (strcmp(comando1, "grafo_de_palabras") == 0){
                    ProcesadorComandos::grafoDePalabras();
            }
            else if (strcmp(comando1, "posibles_palabras") == 0){
                    ProcesadorComandos::posiblesPalabras(comando2);
            }
            

            else if (strcmp(comando1, "ayuda") == 0){
                if (comando2 != nullptr && strcmp(comando2, "") != 0) {
                    ayudaComando(comando2);
                }
                else {
                    ayuda();
                }
            }
            else if (strcmp(comando1,"salir") == 0){
                break;
            }
            else if (strcmp(comando1, "cls") == 0){
                system("CLS");
            }
            
            //En el caso de no hacer match con ninguno, se entrará al else y se notificará al usuario el error
            else{
                std::cout << "Comando incorrecto \nPara ver todos los comandos ingrese el comando 'ayuda'\n";
            }  
        }
}