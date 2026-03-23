
void parejaMaxima(vector<vector<int>> M,int inicio_i,int inicio_j,int final_i,int final_j, pair<int,int> &pmaximo){

	if(i_inicio==i_final && j_inicio==j_final){
		return;
	}
	
	
	int mitad_i = (inicio_i+final_i)/2;
        int mitad_j = (inicio_j+final_j)/2;
	int max1=M[inicio_i][inicio_j];
	int max2=M[mitad_i][mitad_j];
	if(max1>max2) pmaximo={max1,max2};
	else pmaximo={max2,max1};
	
	parejaMaxima(inicio_i,inicio_j,mitad_i,mitad_j,pmaximo);
	parejaMaxima(mitad_i+1,mitad_j+1,final_i,final_j,pmaximo);
	parejaMaxima(mitad_i+1,inicio_,final_i,mitad_j,pmaximo);
	parejaMaxima(inicio_i,mitad_j,mitad_i,final_j,pmaximo);
	
	if(pmaximo<


}
