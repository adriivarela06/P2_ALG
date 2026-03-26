#include <iostream>
#include <chrono>

using namespace std;

pair<int, int> max2_matriz(int **matriz, int filas, int columnas){
   pair<int, int> output;

   if(filas > 0 && columnas > 0){
      output.first = matriz[0][0];

      for(int i = 0; i < filas; ++i){
         for(int j = 0; i < columnas; ++j){
            int num = matriz[i][j];
            if(num > output.first){
               output.second = output.first;
               output.first = num;
            }
            else if(num > output.second && num < output.first)
               output.second = num;
         }
      }
   }

   return output;
}

int main(int argc, char *argv[]) {
   int **v;
	int filas, columnas, total;
	chrono::high_resolution_clock::time_point t0, tf;
	chrono::duration<double> duracion;

	if (argc != 4) {
		cerr << "Uso: " << argv[0] << " semilla tam\n";
		return -1;
	}

	unsigned long int semilla;
	semilla = atoi(argv[1]);
	srand(semilla);	// Inicializamos generador de no. aleatorios
	
	filas = atoi(argv[2]);
   columnas = atoi(argv[3]);
   total = filas * columnas;

	
   v = new int*[filas];
   for(int i = 0; i < filas; ++i)
      v[i] = new int[columnas];
	
	// Generamos vector aleatorio de prueba, con componentes entre 0 y n-1
	for (int i = 0; i < filas; ++i)
      for(int j = 0; j < columnas; ++j)
		   v[i][j] = rand() % total;
			
	t0 = std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecuciÛn del algoritmo
	 
	tf = std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecuciÛn del algoritmo
	
	duracion = std::chrono::duration_cast<std::chrono::duration<double>>(tf - t0);
	cout << filas * columnas << " " << duracion.count() << endl;
	
   for(int i = 0; i < filas; ++i)
	   delete[] v[i];
   delete[] v;

	return 0;
}