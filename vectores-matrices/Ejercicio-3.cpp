/*
 *
 * Definir una matriz mxn, que tenga 3 filas, 4 columnas
 * La primera fila rellenar ceros, las demás unos
 * y mostrar la matriz con sus elementos
 *
 * Se debe visualizar de la siguiente manera
 * 0 0 0 0 0
 * 1 1 1 1 1
 * 1 1 1 1 1
 *
*/

#include <iostream>

using namespace std;

int main(){
	int filas = 3;
	int columnas = 4;
	
	int matriz[3][4] = {{0,0,0,0}, {1,1,1,1}, {1,1,1,1}};

	for(int i=0; i < filas; i++){
		for(int j=0; j < columnas; j++){
			cout << matriz[i][j] << " ";
		}
		
		cout << "\n";
	}
	
	return 0;
}
