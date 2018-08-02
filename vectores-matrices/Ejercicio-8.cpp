/*
 * Definir una matriz cuadrada de 10x10 y rellenar con ceros
 * Pedir como datos de entrada cantidad de filas, y de columnas, 
 * para generar un ciclo que permita cargar los valores de cada 
 * elemento de la matriz, luego guardarlos.
 * Determinar si la matriz es simétrica, y mostrar un mensaje si
 * lo es o no.
 * 
 * 2 1 6			2 1 6
 * 1 5 4	=>	1 5 4
 * 6 4 9			6 4 9
 *
 * Nota:
 * Una matriz es simétrica si cumple las siguientes condiciones:
 * 1. Misma cantidad de filas que columnas, que corresponde
 * a la definición de una matriz cuadrada, es decir m=n.
 * 2. Es igual que su matriz transpuesta, esto quiere decir que los valores
 * de la primera columna son igual que los de la primera fila, los de la 
 * segunda columna iguales a los de la segunda fila, y asi con cada fila columna.
 * 
 * https://es.wikipedia.org/wiki/Matriz_simétrica
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int matriz[10][10] = {0};
	int mfilas, ncolumnas;
	bool es_simetrica = false; // bandera o centinela
	int contador = 0;

	cout << "Filas: "; cin >> mfilas;
	cout << "Columnas: "; cin >> ncolumnas;

	// Si la cantidad de filas y columnas es igual
	if(mfilas == ncolumnas){
		// Genero la Matriz
		// Recorro las filas
		for(int i=0; i < mfilas; i++){
			// Recorro las columnas
			for(int j=0; j < ncolumnas; j++){
				// Pregunto por el valor de cada elemento				
				printf("[%d][%d]: ", i, j);
				// Lo guardo en la matriz
				cin >> matriz[i][j];
			}
		
			cout << "\n";
		}

		// Verifico la Matriz es igual a su Matriz Transpuesta
		// Recorro las filas
		for(int i=0; i < mfilas; i++){
			// Recorro las columnas
			for(int j=0; j < ncolumnas; j++){
				// Verifico si el valor de las columnas y filas
				// es la misma en la matriz, y su matriz transpuesta				
				if(matriz[i][j] == matriz[j][i])
					contador++;
			}
		}

		if(contador == (mfilas * ncolumnas))
			es_simetrica = true;
		
	}
	
	if(es_simetrica == true)
		cout << "La matriz es simetrica" << endl;
	else
		cout << "La matriz no es simetrica" << endl;		
	
	return 0;
}
