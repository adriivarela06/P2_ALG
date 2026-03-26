#include <vector>
#include <iostream>
#include <climits>

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

int main() {
    // Ejemplo de matriz 3x4
    vector<vector<int>> matriz = {
        {10, 2, 33, 4},
        {5, 61, 7, 8},
        {9, 10, 11, 12}
    };

    int filas = matriz.size();
    int cols = matriz[0].size();

    // Llamada inicial: desde (0,0) hasta el final (n-1, m-1)
    pair<int, int> resultado = parejaMaxima(matriz, 0, 0, filas - 1, cols - 1);

    cout << "El maximo de la matriz es: " << resultado.first << ", " << resultado.second << endl;

    return 0;
}
