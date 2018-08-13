/*
 *
 * Generar una matriz cuadrada mxn.
 * Pedir la cantidad de filas y columnas a mostrar 
 * Mostrar solo numeros 1
 *
*/

#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

int main(){
	int filas_columnas;

	cout << "Filas y Columnas a mostrar: ";
	cin >> filas_columnas;


	for(int fila=1; fila <= filas_columnas; fila++){
		for(int columna=1; columna <= filas_columnas; columna++){
			cout << 1 << " ";
		}

		cout << "\n";
	}
	
	return 0;
}
