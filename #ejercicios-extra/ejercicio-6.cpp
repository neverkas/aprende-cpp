/*
 * Crear un programa que gestione una matriz de enteros de 4 x 3, permita ingresar
 * todos sus elementos por consola y ofrezca las siguientes operaciones a partir de
 * estas funciones:
 * mostrarMatriz(), sumarFilas(), mayorPorFila(), menorPorFila()
 * 
 * Las funciones recibiran por parametro la referencia a la matriz y mostrarC!n por 
 * pantalla los resultados por fila. Permitir al usuario seleccionar operaciones a
 * travC)s de un menC: de opciones. 
 * 
 * main() debera permitir ingresar valores a los elementos de la matriz
 * Cuando el usuario seleccione las opciones "Mayor por fila" o "Menor por fila", main() invocara a
 * esas funciones que recibiran la matriz y convertiran las filas en vectores (1 dimension) de forma tal
 * de utilizar las funciones ya desarrolladas que localizan maximo y minimo en un array
 * unidimensional. Ejemplo:
 * > carga valores a la matriz
 * > muestra las opciones
 * > invoca a la funciones (que reciben matriz[][])
 * 
 * Maximo
 * > recibe un array unidimensional y retorna la posicion del elemento con el mayor valor
 * 
 */
#include <iostream>
#include <iomanip>

using namespace std;

//
// # Variables Globales
// 
const int MATRIZ_FILAS = 4;
const int MATRIZ_COLUMNAS = 3;

// 
// # Prototipos
// 
void cargarMatriz(int [MATRIZ_FILAS][MATRIZ_COLUMNAS]);
void mostrarMatriz(int [MATRIZ_FILAS][MATRIZ_COLUMNAS]);
void sumarFilas(int [MATRIZ_FILAS][MATRIZ_COLUMNAS]);
void menorPorFila(int [MATRIZ_FILAS][MATRIZ_COLUMNAS]);
void mayorPorFila(int [MATRIZ_FILAS][MATRIZ_COLUMNAS]);
void menu(int [MATRIZ_FILAS][MATRIZ_COLUMNAS]);

int maximo(int [], int);
int minimo(int [], int);

/*********************************************************************/

//
// # Main
//
int main(){
	int matriz[MATRIZ_FILAS][MATRIZ_COLUMNAS];	 // 4x3
	cargarMatriz(matriz);		
	menu(matriz);	
}

/*********************************************************************/

//
// # Funciones
//
void cargarMatriz(int matriz[MATRIZ_FILAS][MATRIZ_COLUMNAS]){
	cout << "Cargar valores a la matriz:" << endl;
	
	// Cargar valores a la matriz
	for (int fila = 0; fila < MATRIZ_FILAS; fila++){
		for (int col = 0; col < MATRIZ_COLUMNAS; col++){
			// Solicita el valor que ira 
			cout<<"Valor["<<fila<<"]["<<col<<"]:";
			cin >> matriz[fila][col];
		}
	}
}

void menu(int matriz[MATRIZ_FILAS][MATRIZ_COLUMNAS]){
	int opcion;
	cout << "MENU DE OPCIONES" << endl;
	
	cout << "\t0: Salir" << endl;
	cout << "\t1: Mostrar matriz" << endl;
	cout << "\t2: Sumar Filas" << endl;
	cout << "\t3: Menor por fila" << endl;
	cout << "\t4: Mayor por fila" << endl;

	cout << "Opcion: ";
	cin >> opcion;
	
	// Bucle controlado por centinela que es 'opcion'
	// sigue iterando mientras 'opcion' sea distinto a cero
	while(opcion != 0){				
		switch(opcion){
			case 1:
				mostrarMatriz(matriz);
			break;
			case 2:
				sumarFilas(matriz);
			break;
			case 3:
				menorPorFila(matriz);
			break;
			case 4:
				mayorPorFila(matriz);
			break;
			} // end switch		 		 
			cout << endl;
			 
		cout << "Opcion: ";
		cin >> opcion;
	 } // end while
}

void mostrarMatriz(int matriz[MATRIZ_FILAS][MATRIZ_COLUMNAS]){
	// Recorro las filas
	for (int fila = 0; fila < MATRIZ_FILAS; fila++){
		// Recorro las columnas
		for (int col = 0; col < MATRIZ_COLUMNAS; col++){
			cout << setw(2) << matriz[fila][col] << " ";
		}
		
		cout<<endl;
	}
}

void sumarFilas(int matriz[MATRIZ_FILAS][MATRIZ_COLUMNAS]){
	int suma = 0;
	
	// Recorro las filas
	for (int fila = 0; fila < MATRIZ_FILAS; fila++){
		// Recorro las columnas
		for (int col = 0; col < MATRIZ_COLUMNAS; col++){
			// Sumo el valor de cada fila y lo acumulo en 'suma'
			suma += matriz[fila][col];
		}
		
		cout << "Suma de la fila " << fila << " es " << suma << endl;
		// Vuelvo a cero 'suma' para sumar cada fila
		suma = 0;
	}
	
}

void mayorPorFila(int matriz[MATRIZ_FILAS][MATRIZ_COLUMNAS]){		
	int arr[MATRIZ_FILAS] = {0};
	int pos;
	int valor;
	// 4 filas, 3 columnas
	
	// Recorro las filas
	for (int fila = 0; fila < MATRIZ_FILAS; fila++){		
		// Recorro las columnas
		for (int col = 0; col < MATRIZ_COLUMNAS; col++){
			// Almaceno el valor de cada fila en un array unidimensional
			arr[col] = matriz[fila][col];
		}
		// Le paso a la funcion 'maximo' 
		// el array con los valores de cada fila, y el tamanio del vector
		// y me devuelve la posicion del elemento con mayor valor
		pos = maximo(arr, MATRIZ_FILAS);
		// Reutilizo la posicion que me devuelve la funcion
		// y se lo paso como indice al vector que guarda los valores de las filas
		valor = arr[pos];
		cout << "El mayor de la FILA " << fila	<< " es " << valor << endl;		
	}
}

void menorPorFila(int matriz[MATRIZ_FILAS][MATRIZ_COLUMNAS]){
	int arr[MATRIZ_FILAS] = {0};
	int pos;
	int valor;
	
	// Recorro las filas
	for (int fila = 0; fila < MATRIZ_FILAS; fila++){		
			// Recorro las columnas
		for (int col = 0; col < MATRIZ_COLUMNAS; col++){
			// Almaceno el valor de cada fila en un array unidimensional
			arr[col] = matriz[fila][col];
		}
		
		// Le paso a la funcion 'maximo' 
		// el array con los valores de cada fila, y el tamanio del vector
		// y me devuelve la posicion del elemento con menor valor		
		pos = minimo(arr, MATRIZ_FILAS);		
		// Reutilizo la posicion que me devuelve la funcion
		// y se lo paso como indice al vector que guarda los valores de las filas
		valor = arr[pos];
		cout << "El menor de la FILA " << fila	<< " es " << valor << endl;
	}
}

// Devuelve la posicion del elemento con mayor valor
// requiere pasar un array unidimensional y el tamanio (cantidad de elementos)
int maximo(int array[], int tamanio) {
	int pos = 0, max;
	max = array[0];
	for(int j = 0; j<=tamanio-1; j++) {
		if(array[j]>max) {
			pos = j;
			max = array[j];
		}
	}
	return pos;
}

// Devuelve la posicion del elemento con menor valor
// requiere pasar un array unidimensional y el tamanio (cantidad de elementos)
int minimo(int array[], int tamanio) {
	int j = 0;
	int posic, min;
	while(j<=tamanio&&array[j]==0) {
		j++;
	}
	posic = j;
	min = array[j];
	for(j = posic + 1 ; j<=tamanio-1; j++) {
		if(array[j]!=0&&array[j]<min) {
			posic = j;
			min = array[j];
		}
	}
	return posic;
}
