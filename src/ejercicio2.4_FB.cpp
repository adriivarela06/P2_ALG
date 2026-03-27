#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;

int inversionesFB(vector<int>& vec){
  int contador = 0;
  int tam = vec.size();

  for(int i = 0;i < tam;i++){
    for(int j = i + 1;j < tam;j++){
      if(vec[i] > vec[j]){
        contador++;
      }
    }
  }

  return contador;

}


int main(int argc, char *argv[]) {
	
	int n, i;
  chrono::time_point<std::chrono::high_resolution_clock> t0, tf; // Para medir el tiempo de ejecución
	unsigned long int semilla;
	
	if (argc != 3) {
		cerr << "Uso: " << argv[0] << " semilla tam\n";
		return -1;
	}
	
	semilla = atoi(argv[1]);
	srand(semilla);	// Inicializamos generador de no. aleatorios

	n= atoi(argv[2]);
  vector<int> v(n);
	int invert=0;
	// Generamos vector aleatorio de prueba, con componentes entre 0 y n-1
	for (i= 0; i<n; i++)
		v[i]= rand()%n;
			
	t0= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecuciÛn del algoritmo
	invert = inversionesFB(v); 
	tf= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecuciÛn del algoritmo
	
	double tejecucion= std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();
  tejecucion= tejecucion/1000000.0; // Convertimos a segundos
	
	cout << "para " << n <<" inversiones: "<< invert <<" tiempo: "<< tejecucion << endl;
	
	return 0;

}