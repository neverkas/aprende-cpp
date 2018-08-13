/*
 *
 * Declarar una matriz cuadrada 5x5, rellenar sólo con nùmeros 1.
 * Desarrollar un ciclo for incremental que muestre solo su diagonal principal,
 * sino lo es mostrar ceros.
 * Mostrar el resultado del ciclo, y luego la matriz original con
 * con un decremental al recorrer las filas y columnas.
 * Se debe visualizar de la siguiente manera:
 *
 * 1 0 0 0 0
 * 0 1 0 0 0
 * 0 0 1 0 0
 * 0 0 0 1 0
 * 0 0 0 0 1
 *
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int matriz[5][5] = {{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1}};
	int fila, columna;

	cout << "Matriz con la diagonal principal: " << endl;
	// Recorro las filas
	for(int i=0; i < 5; i++){
		// Recorro las columnas
		for(int j=0; j < 5; j++){
			// Si el indice de la fila es igual que la columna
			// entonces forma parte de la diagonal principal
			if(i==j)
				// mostrar solo los numeros de la diagonal principal
				cout << matriz[i][j] << " ";
			// Si indice de la fila es distinto que el de la columna			
			else
				// mostrar ceros
				cout << 0 << " ";
		}
		
		cout << "\n"; // salto de linea por cada fila
	}
	
	cout << "\n";

	cout << "Matriz: " << endl;
	// Recorro las filas,
	// desde el último elemento hasta el primero
	// le resto 1 al total de filas, para que se entienda mejor
	for(int i=5-1; i>=0; i--){		
	// Recorro las columnas,
	// desde el último elemento hasta el primero		
	// le resto 1 al total de columnas, para que se entienda mejor
		for(int j=5-1; j>=0; j--){
			fila = 4-i; // Le resto al total de filas el decremental
			columna = 4-j; // Le resto al total de columnas el decremental
			cout << matriz[fila][columna] << " ";
		}
		
		cout << "\n"; // salto de linea por cada fila
	}

	cout << "\n";
		
	return 0;
}
