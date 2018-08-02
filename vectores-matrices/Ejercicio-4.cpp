/*
 *
 * Definir una matriz mxn
 * Pedir cantidad de filas, columnas y el valor que de
 * cada fila columna, guardar en la matriz definida.
 * Por último mostrar la matriz generada.
 *
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	// 1. Defino las variables
	
	int matriz[100][100]; // Defino la matriz donde se guardaran los datos
	int mfilas, ncolumnas;

	// 2. Pido la información necesaria para generar la matriz
	cout << "Filas: "; cin >> mfilas;
	cout << "Columnas: "; cin >> ncolumnas;

	// 3. Genero la matriz
	
	// Recorro cada fila (i)
	for(int i=0; i < mfilas; i++){
		// Recorro cada columna (j)
		for(int j=0; j < ncolumnas; j++){
			// Pregunto por el valor de la fila columna
			printf("[%d][%d]: ", i, j);
			// Lo guardo en la matriz
			cin>>matriz[i][j];
		}
	}
	
	cout << "\n";

	cout << "Matriz: " << endl;
	// 4. Muestro la matriz
	for(int i=0; i < mfilas; i++){
		// Recorro cada columna (j)
		for(int j=0; j < ncolumnas; j++){
			// Muestro los datos
			printf("%d ", matriz[i][j]);
		}
		
		cout << "\n"; // Salto de linea por cada fila
	}

	
	return 0;
}
