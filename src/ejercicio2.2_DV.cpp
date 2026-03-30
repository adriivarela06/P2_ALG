#include <vector>
#include <iostream>
#include <climits>
#include <chrono>

using namespace std;

void calcularMaximo(pair<int, int> &maximo, pair<int, int> p){
	if (p.first > maximo.first) {
        maximo.second = maximo.first;
        maximo.first = p.first;
    } else if (p.first < maximo.first && p.first > maximo.second) {
        maximo.second = p.first;
    }
    if (p.second > maximo.second && p.second < maximo.first) {
        maximo.second = p.second;
    }
}
pair<int, int> parejaMaxima(const vector<vector<int>> &M,int inicio_i,int inicio_j,int final_i,int final_j){

	if(inicio_i == final_i && inicio_j == final_j){
		return pair<int, int> {M[inicio_i] [inicio_j], INT_MIN};
	}
		
	int mitad_i = (inicio_i+final_i)/2;
    int mitad_j = (inicio_j+final_j)/2;
	
	pair<int, int> pmaximo = parejaMaxima(M, inicio_i,inicio_j,mitad_i,mitad_j);
	if (mitad_i < final_i && mitad_j < final_j){
		pair<int, int> p1 = parejaMaxima(M, mitad_i+1,mitad_j+1,final_i,final_j);
		calcularMaximo(pmaximo, p1);
	}
	
	if (mitad_i < final_i){
		pair<int, int> p2 = parejaMaxima(M, mitad_i+1,inicio_j,final_i,mitad_j);
		calcularMaximo(pmaximo, p2);
	}

	if (mitad_j < final_j){
		pair<int, int> p3 = parejaMaxima(M, inicio_i,mitad_j+1,mitad_i,final_j);
		calcularMaximo(pmaximo, p3);
	}
	return pmaximo;
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
   pair<int, int> resultado = parejaMaxima(v, 0, 0, filas - 1, columnas - 1);
	tf = std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecuciÛn del algoritmo
   
   cerr << "Resultado ignorado para evitar optimización: " << resultado.first << endl;

	duracion = std::chrono::duration_cast<std::chrono::duration<double>>(tf - t0);
	cout << filas * columnas << " " << duracion.count() << endl;

	return 0;
}