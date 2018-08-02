/*
 *
 * Declarar dos matrices cuadradas A, y B de 4x4 con valores al azar,
 * sumar ambas y guardar la sumatoria en una tercera matriz C.
 * Mostrar la matriz A,B, y la resultante.
 *
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int A[4][4] = {{1, 2, 3, 1}, {1, 3, 2, 1}, {1, 4, 2, 1}, {1, 2, 4, 1} };
	int B[4][4] = {{2, 4, 2, 2}, {4, 2, 2, 4}, {3, 1, 3, 1}, {1, 2, 4, 1} };
	int C[4][4];

	// Recorro las filas (i)
	for(int i=0; i < 4; i++){
		// Recorro las columnas
		for(int j=0; j < 4; j++){
			// Sumo cada valor de fila columna de las Matrices A, B
			// lo almaceno en la misma posicion a la Matriz C
			C[i][j] = A[i][j] + B[i][j];
		}
	}

	cout << "Matriz A" << endl;
	// Recorro las filas (i)
	for(int i=0; i < 4; i++){
		// Recorro las columnas
		for(int j=0; j < 4; j++){
			// Muestro el valor de cada fila columna
			printf("%d ", A[i][j]);
		}

		cout << "\n"; // Salto de linea por cada fila
	}
	
	cout << "\n"; // Salto de linea

	cout << "Matriz B" << endl;
	// Recorro las filas (i)
	for(int i=0; i < 4; i++){
		// Recorro las columnas
		for(int j=0; j < 4; j++){
			// Muestro el valor de cada fila columna
			printf("%d ", B[i][j]);
		}

		cout << "\n"; // Salto de linea por cada fila
	}

	cout << "\n"; // Salto de linea
	
	cout << "Matriz resultante de A+B" << endl;
	// Recorro las filas (i)
	for(int i=0; i < 4; i++){
		// Recorro las columnas
		for(int j=0; j < 4; j++){
			// Muestro el valor de cada fila columna
			printf("%d ", C[i][j]);
		}

		cout << "\n"; // Salto de linea por cada fila
	}
	
	return 0;
}
