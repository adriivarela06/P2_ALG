#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;

int contInversiones(vector<int>& v, int inicio, int medio, int fin){
  int contador = 0;
  int i= inicio;
  int j= medio+1;
  vector<int> vaux;

  while(i <= medio && j <= fin){
    if(v[i]<=v[j]){
      vaux.push_back(v[i]);
      i++;
    }
    else{
        
      vaux.push_back(v[j]);
      contador+=(medio-i+1);
      j++;
    }
  }
  while(i <= medio){
    vaux.push_back(v[i]);
    i++;
  }
  while(j <= fin){
      vaux.push_back(v[j]);
      j++;
  }
  for (int k = 0; k < (int)vaux.size(); k++) {
    v[inicio + k] = vaux[k];
  }

  return contador;
}



int inversiones(vector<int>& v, int inicio, int final){

    int contador = 0;
    if(inicio < final){
        int medio = (inicio + final) / 2;
        contador += inversiones(v, inicio, medio);
        contador += inversiones(v, medio + 1, final);
        contador += contInversiones(v, inicio, medio, final);
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
   vector<int> vaux(n);
	int invert=0;
	// Generamos vector aleatorio de prueba, con componentes entre 0 y n-1
	for (i= 0; i<n; i++)
		v[i]= rand()%n;
			
	t0= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecuciÛn del algoritmo
	invert = inversiones(v,0,n-1); 
	tf= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecuciÛn del algoritmo
	
	double tejecucion= std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();
   tejecucion= tejecucion/1000000.0; // Convertimos a segundos
	
	cout << "para " << n <<" inversiones: "<< invert <<" tiempo: "<< tejecucion << endl;
	
	return 0;

}