/*
Código de barras. Un sistema de gestión de logística debe almacenar en memoria los códigos de
barra de los paquetes a medida que son leídos por un scanner. El líder técnico determinó que la
mejor estructura para este caso sería una matriz bidimensional que almacene hasta 100 códigos.
Como se desea que no haya repetición de datos, el array también almacenará la cantidad de lecturas
sobre un mismo código, como se muestra en este ejemplo:

Se p​ ide: Crear la función nuevaLectura() que recibirá por parámetro: la matriz, el valor del índice al
próximo elemento y el nuevo código a ingresar. Si el array no tiene más capacidad, deberá retornar el
valor ‘-1’. También se deberá crear la definición de la función validar() que buscará lecturas erróneas
(identificadas con el código de valor ‘0’) y en cuyo caso se deberá eliminar la fila desplazando las
siguientes de modo tal que no queden elementos vacíos intermedios (sólo podrá haber una fila con
error). Por último, también se pide implementar la función ordenar() para ordenar las filas de la
matriz ascendentemente por la columna ‘cantidad’.
*/

#include <iostream>
#include <cstdio>

const int MATRIZ_FILAS = 3;
const int MATRIZ_COLUMNAS = 2;
const int CODIGOS_CANTIDAD = 2;

using namespace std;

// prototipos
void nuevaLectura(int [MATRIZ_FILAS][MATRIZ_COLUMNAS], int, int);
void mostrar(int [MATRIZ_FILAS][MATRIZ_COLUMNAS]);
//void validar(int [MATRIZ_FILAS][MATRIZ_COLUMNAS]);
//void ordenar();

int main(){
	int matriz[MATRIZ_FILAS][MATRIZ_COLUMNAS];

	for(int i=0; i<MATRIZ_FILAS; i++){
		cout << "Codigo: ";
		cin >> matriz[i][0];

		cout << "Cantidad: ";
		cin >> matriz[i][1];
	}
	
	for(int i=0; i<=CODIGOS_CANTIDAD; i++){
		printf("Codigo: %i , Cantidad: %i \n", matriz[i][0], matriz[i][1]);
	}
	
	/*
	for(int i=0; i < CODIGOS_CANTIDAD; i++){	
		cout << "Codigo: ";
		cin >> codigo;

		cout << "Cantidad: ";
		cin >> cantidad;

		nuevaLectura(matriz, codigo, cantidad);
	}
	
	
	mostrar(matriz);
	*/
	return 0;
}
	//for(int i=0; i < CODIGOS_CANTIDAD; i++){

void mostrar(int matriz[MATRIZ_FILAS][MATRIZ_COLUMNAS]){
	for(int i=0; i<CODIGOS_CANTIDAD; i++){
		printf("Codigo: %i , Cantidad: %i \n", matriz[i][0], matriz[i][1]);
	}
}

void nuevaLectura(int matriz[MATRIZ_FILAS][MATRIZ_COLUMNAS], int codigo, int cantidad){
		matriz[codigo][0] = codigo;
		matriz[codigo][1] = cantidad; 
}
