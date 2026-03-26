#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int contInversiones(vector<int>& v, int inicio, int medio, int fin){
  int contador = 0;
  int i= inicio;
  int j= medio+1;
  vector<int> vaux;
  while(i<medio && j<fin){
    if(v[i]<v[j]){
      vaux.push_back(v[i]);
      i++;
    }
    else{
        
      vaux.push_back(v[j]);
      contador+=(medio-i+1);
      j++;
    }
  }
  while(i<medio){
    vaux.push_back(v[i]);
  }
  while(j<fin){
      vaux.push_back(v[j]);
  }
  for (int k = 0; k < vaux.size(); k++) {
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