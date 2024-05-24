# Scrabble Helper System

## Descripción
Este programa es un sistema de ayuda para el juego Scrabble. Permite a los usuarios inicializar un diccionario de palabras válidas, un diccionario inverso para búsquedas eficientes, y obtener el puntaje de palabras específicas de acuerdo con las reglas de Scrabble.

## Cómo comenzar

### Prerrequisitos
- Compilador de C++ (GCC recomendado)
- Sistema operativo: Windows, Linux o macOS

### Instalación y compilación

1. Clona el repositorio o descarga el código fuente.
2. Abre una terminal o línea de comandos en la carpeta del código fuente.
3. Compila el código fuente utilizando el compilador de C++. Por ejemplo, con GCC escribirías:
   ```sh
   g++ -o scrabble_helper main.cpp scrabble_helper_functions.cpp

## Ejecuta el programa compilado:
-  En Windows:
   scrabble_helper
-  En Linux/macOS:
   ./scrabble_helper

## Uso
   Una vez que el programa esté ejecutándose, puedes utilizar los siguientes comandos:

-  'ayuda': Muestra un mensaje de ayuda con todos los comandos disponibles.
-  'iniciar_diccionario [ruta]': Inicializa el diccionario principal con la ruta al archivo de diccionario.
-  'iniciar_inverso [ruta]': Inicializa el diccionario inverso con la ruta al archivo de diccionario inverso.
-  'puntaje_palabra [palabra]': Calcula y muestra el puntaje de una palabra específica.
-  'salir': Termina la ejecución del programa.

## Licencia
   Este proyecto está licenciado bajo la Licencia MIT - vea el archivo LICENSE.md para más detalles.
