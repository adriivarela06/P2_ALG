#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>

using namespace std;

pair<int, int> max2_matriz(const vector<vector<int>> &matriz,int inicio_i,int inicio_j,int final_i,int final_j){
   pair<int, int> output;

   if(final_i - inicio_i > 0 && final_j - inicio_j > 0){
      output = {matriz[0][0], -1};

      for(int i = inicio_i; i <= final_i; ++i){
         for(int j = inicio_j; j <= final_j; ++j){
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
   vector<vector<int>> v;
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

   v.reserve(filas);
	
	// Generamos vector aleatorio de prueba, con componentes entre 0 y n-1
	for (int i = 0; i < filas; ++i){
      vector<int> temporal;
      temporal.reserve(columnas);

      for(int j = 0; j < columnas; ++j)
		   temporal.push_back(rand() % total);

      v.push_back(temporal);
   }		

	t0 = std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecuciÛn del algoritmo
	max2_matriz(v, 0, filas - 1, 0, columnas - 1);
	tf = std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecuciÛn del algoritmo
	
	duracion = std::chrono::duration_cast<std::chrono::duration<double>>(tf - t0);
	cout << filas * columnas << " " << duracion.count() << endl;

	return 0;
}