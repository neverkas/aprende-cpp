/*
 *  ORDENAMIENTO BURBUJA
 * (Se utiliza para la busqueda binaria)
 *
 * Exercise 4:
 * Dado un vector con los elementos desordenados {1,3,2},
 * desarrollar un programa que:
 * -Muestre el vector original
 * -Muestre el vector ordenado
 *
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int numeros[] = {1,3,2};
	int cantidad_numeros = 3;
	int numero;
	bool flag = false;

	// Con incremental
	cout << "Lista desordenada: ";
	for(int i=0; i < cantidad_numeros; i++){
		cout << numeros[i];
		
		if(i < cantidad_numeros-1)
			cout << ", ";
	}
	
	cout << endl;
	cout << endl;
	
	for(int i=0; i < cantidad_numeros; i++){
		// Sino resto 1 a la cantidad de numeros,
		// numeros[j+1] que devuelve el elemento siguiente,
		// devolvería un elemento con un indice mayor que no existe en la lista
		// Ej.: Si tengo 5 elementos, devolvería sexto elemento que no existe
		
		for(int j=0; j < cantidad_numeros-1; j++){
			printf("(%d > %d)? %s \n", numeros[j], numeros[j+1], (numeros[j] > numeros[j+1]) ? "si" : "no" );

			// Si el número actual es mayor que el siguiente
			if(numeros[j] > numeros[j+1]){				
				printf("*cambio %d por %d\n", numeros[j], numeros[j+1]);
				printf("*cambio %d por %d\n", numeros[j+1], numeros[j]);

				// almaceno en 'numero' el valor del número
				// para reutilizar al cambiar el valor del número siguiente,
				// sino estaría usando el valor modificado y no el anterior
				numero = numeros[j];				
				
				// cambio de lugar el numero actual por el siguiente,
				numeros[j] = numeros[j+1];
				// y viceversa				
				numeros[j+1] = numero;
			}
		} // end for
		cout << endl;
	} // end for


	cout << "Lista ordenada: ";
	for(int i=0; i < cantidad_numeros; i++){
		cout << numeros[i];
		
		if(i < cantidad_numeros-1)
			cout << ", ";
	} // end of
	
	cout << endl;

	//
	// Otras maneras de hacerlo
	//
	
	// 1. Version mejorada con flag
	for(int i=0; i < cantidad_numeros; i++){
		flag = false;
		
		for(int j=0; j < cantidad_numeros-1; j++){
			if(numeros[j] > numeros[j+1]){
				flag = true;
				
				numero = numeros[j];				
				numeros[j] = numeros[j+1];
				numeros[j+1] = numero;
			}
		} // end for

		if(flag == false)
			break;
	} // end for
	
	// 2. Con decremental
	for(int i=0; i < cantidad_numeros; i++){
		for(int j=cantidad_numeros-1; j > 0  ; j--){			
			if(numeros[j] < numeros[j-1]){
				numero = numeros[j];

				numeros[j] = numeros[j-1];
				numeros[j-1] = numero;
			}
		} // end for
	} // end for

	// 3. Otra manera
	for(int i=0; i < cantidad_numeros; i++){
		for(int j=i+1; j < cantidad_numeros; j++){
			if(numeros[j] < numeros[i]){
				numero = numeros[i];
				
				numeros[i] = numeros[j];
				numeros[j] = numero;
			} // end if
		} // end for
	} // end for
	
	return 0;
}

