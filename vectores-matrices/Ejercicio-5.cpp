/*
 *
 * Definir una matriz 4x3, que tenga el número 1 en 
 * cada fila de la segunda columna, y completar el resto
 * con número el 0.
 * Mostrar la matriz, con el numero de fila y columna entre corchetes.
 *
 * Se debe visualizar de la siguiente manera
 * [0]	[1] [2] [3] 
 * [1]	 0	 1	 0
 * [2] 	 0	 1	 0
 * [3]	 0	 1	 0
 * [4]	 0	 1	 0
 *
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	// 1. Defino variables
	int mfilas = 4;
	int ncolumnas = 3;
	
	int matriz[4][3] = {{0,1,0}, {0,1,0}, {0,1,0}, {0,1,0}};

	// Recorro las filas
	for(int i=0; i < 4+1; i++){
		// Recorro las columnas
		for(int j=0; j < 3+1; j++){
			if(j == 0) // Si es la primera columna
				printf("[%d]", i);
			else if(i == 0) // Si es la primera fila
				printf("[%d]", j); //
			else // mostrar los valores de la matriz
				printf(" %d ", matriz[i-1][j-1]);
		} // end for
		
		cout << "\n"; // Salto de linea por cada fila
	}
	
	return 0;
}
