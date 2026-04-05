PRACTICA 2: ALGORITMOS DE FUERZA BRUTA Y DIVIDE Y VENCERAS

Este repositorio contiene el codigo fuente,con los datos empiricos y las graficas que hemos generado para esta Practica 2. 
El objetivo de la practica es ir comparando la eficiencia de los algoritmos diseñados mediante primero la Fuerza Bruta y despues con el Divide y Venceras.


/// ESTRUCTURA DEL PROYECTO  ///

El directorio esta organizado de la siguiente manera para separar el codigo fuente (los.cpp),los ejecutables,los datos de prueba de cad algortimo y los graficos de gnuplot:

* CARPETA SRC (el codigo Fuente): Contiene las implementaciones en C++ de los ejercicios propuestos.
  - ejercicio2.2_FB.cpp: Solucion por Fuerza Bruta para encontrar los dos valores maximos de una matriz.
  - ejercicio2.2_DV.cpp: Solucion por Divide y Venceras para encontrar los dos valores maximos de una matriz.
  - ejercicio2.4_FB.cpp: Solucion por Fuerza Bruta para el recuento de inversiones en un vector.
  - ejercicio2.4_DV.cpp: Solucion por Divide y Venceras para el recuento de inversiones en un vector.

* CARPETA BIN (los ejecutables): Tiene los archivos ejecutables, que se generan automaticos con el makefile.

* CARPETA DATA (los datos): Es el directorio donde se almacenan los archivos .dat generados tras la ejecucion de los algoritmos, estos archivos tienen los valores (Tamaño del problema y Tiempo de ejecucion) utilizados para el analisis empirico.
  - Algunos ejemplos son: ejercicio2.4_FB.dat, ejercicio2.4_DV.dat,...

* CARPETA GNUPLOT (las graficas y script): Contiene todas las graficas de rendimiento asintotico.
  - umbral.gp: Es un script de Gnuplot utilizado para generar las graficas comparativas.
  - fit.log: Archivo de registro generado por Gnuplot con los parametros de los ajustes matematicos (ej. O(n^2) y O(n*log(n))).
  - archivos.png: SOn las imagenes finales con graficas de eficiencia y las comparativas de umbral entre Fuerza Bruta y Divide y Venceras.

* MAKEFILE Archivo de configuracion para automatizar la compilacion de todos los archivos fuente en la carpeta src/ y tener los ejecutables resultantes en la carpeta bin/.


/// EJECUCION DEL PROGRAMA ///

Para generar los ejecutables en el directorio bin/., podemos usar make y para ejecutar cualquier programa,utiliza la ruta al binario pasando como argumentos la semilla para la generacion aleatoria y el tamaño del problema. 

Ejemplo:

    ./bin/ejercicio2.4_FB <semilla> <N>