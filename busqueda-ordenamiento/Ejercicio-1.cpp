/*
 * # Búsqueda secuencial
 *
 * Exercise 1:
 * Dado un vector A que contiene como números naturales el 3,6,7,2 y 9,
 * que estan en ese orden. Desarrollar un programa que encuentre la posición
 * de un número que ingrese por teclado.
 * Mostrar en pantalla los siguientes datos:
 * -Si el número ingresado se encuentra o no entre los elementos del vector.
 * -Si se encuentra elemento, informar su valor y posición.
 *
*/

#include <iostream>
#include <cstdio> // printf

using namespace std;

int main(){
	//
	// #1. DEFINO LAS VARIABLES
	//
	int A[] = {3, 6, 7, 2, 9}; // Vector A

	int posicion = 0; // incremental 
	bool encontrado = false; // flag
	int elemento;
	int elemento_posicion;
	int elemento_ingresar;

	//
	// #2. ENTRADA DE DATOS
	//
	cout << "Ingrese un numero: "; cin >> elemento_ingresar;

	//
	// 3. PROCESO LA INFORMACIÓN
  //

	// El bucle dejará de ejecutarse/iterar si se cumple las siguientes condiciones:
	// 1. El incremental 'posicion' es menor a 5
	// 2. El valor del flag 'encontrado' es igual a true
	// Mientras no se cumplan esas condiciones, seguirá iterando.
	while(posicion < 5 && encontrado == false){
		// Utilizo el valor de 'posicion' que incrementa +1
		// para recorrer los elementos del vector 'A' y lo guardo en 'elemento'
		// Ej.:
		// A[0] obtiene el valor del primer elemento
		// A[4] obtiene el valor del último elemento
		elemento = A[posicion];

		//printf("%d == %d \n", elemento, elemento_ingresar);
		
		// Por cada iteración/ejecución del bucle
		// comparo cada elemento del vector con el valor ingresado
		if(elemento == elemento_ingresar){
			// Si coincide cambio el flag 'encontrado' a true
			// para detener la ejecución del bucle
			encontrado = true;
			// y guardo el indice/posición que tiene el elemento
			elemento_posicion = posicion;
		}

		// Agrego el incremental al final del bucle
		// para considerar al primer elemento que tiene posición cero.
		posicion++;
	} // end while
	
	//
	// #4. SALIDA DE DATOS
	//

	if(encontrado == true)
		printf("El numero %d fue encontrado en la posición %d. \n", elemento, elemento_posicion);
	else
		printf("El numero %d no se encuentra en el vector. \n", elemento_ingresar);
	
	return 0;
}
