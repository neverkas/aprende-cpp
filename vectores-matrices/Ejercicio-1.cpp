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

void generarMatrizCuadrada(int tam);

int main(){
	int filas_columnas;

	cout << "Filas y Columnas a mostrar: ";
	cin >> filas_columnas;

	generarMatrizCuadrada(filas_columnas);
	
	return 0;
}

void generarMatrizCuadrada(int tam){
	// defino la matriz
	int matriz[tam][tam];

	// cargo los datos en la matriz
	for(int fila=0; fila < tam; fila++){
		for(int columna=0; columna < tam; columna++){
			matriz[fila][columna] = 1;
		}
	}

	// imprimo la matriz
	for(int fila=0; fila < tam; fila++){
		for(int columna=0; columna < tam; columna++){
			cout << matriz[fila][columna] << " ";
		}
		cout << endl;
	}

}
