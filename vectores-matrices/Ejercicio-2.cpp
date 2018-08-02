/*
 *
 * Generar una matriz cuadrada mxn.
 * Pedir la cantidad de filas y columnas a mostrar 
 * Mostrar de forma aleatoria solo ceros y unos
 *
*/

#include <iostream>
#include <cstdio> // printf, NULL
#include <cstdlib> // srand, rand
#include <ctime> // time

using namespace std;

int main(){
	srand(time(NULL));
	
	int filas_columnas;
	int numero;

	cout << "Filas y Columnas a mostrar: ";
	cin >> filas_columnas;


	for(int fila=1; fila <= filas_columnas; fila++){
		for(int columna=1; columna <= filas_columnas; columna++){
			numero = rand() % 2;
				
			cout << numero << " ";
		}

		cout << "\n";
	}
	
	return 0;
}
