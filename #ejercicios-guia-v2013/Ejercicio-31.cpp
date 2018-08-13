/*
 *
 * Dado un valor entero n, informar los primeros n numeros primos.
 * Ej.: Si n==6 entonces la salida debe ser 1,2,3,5,7,11
 *
 *********************************************************************
 * 
 * SUGERENCIA:
 * Los numeros primos son los que son divisibles solo por si mismos, y por 1 y -1.
 *
 */

#include <iostream>
#include <iomanip>

using namespace std;

//
// # Main
//
int main(){
	//
	// # 1. Defino las variables
	//
	int cantidad_primos;

	/*********************************************************************/

	//
	// # 2. Entrada de datos
	//
	cout << "Cantidad de numeros primos a mostrar: ";
	cin >> cantidad_primos;

	/*********************************************************************/

	//
	// # 3. Proceso la información && Salida de datos
	//
	// verifico si cantidad_primos es un entero positivo
	if(cantidad_primos > 0){
		int i = 1;
		int repetir_loop = 1;
		int numeros_divisibles;
		bool es_compuesto;
		
		// Imprimo el primer valor
		// El numero 1, es el primer primo
		cout << i; // Imprimo el numero 1

		// Bucle va a iterar mientras 'i' sea menor a 'cantidad_primos'
		// mientras la condicion sea 'verdadero' seguira incrementando a 'i'
		while(repetir_loop < cantidad_primos){
			i++;
			// Cada vez que itera, reestablezco 'numeros_divisibles'	a 0
			numeros_divisibles = 0;
			// Bucle que va desde 1 hasta 'i' que va en incremento
			for(int x = 1; x <= i; x++){
				// Si 'i' dividido 'x' da como resto cero, es compuesto
				es_compuesto = (i % x == 0);
			
				// contar por cuantos numeros que divide da resto 0
				if(es_compuesto){
					numeros_divisibles++;
				}
			} // end for

			// Un numero primo es divisible por 2 numeros,
			// por 1 y por si mismo, por eso el 2
			if(numeros_divisibles == 2){
				// repetir el loop por la cantidad de numeros compuestos
				repetir_loop++;
				
				//
				// # 4. Salida de datos
				//
				cout << setw(3) << i;
			} // end if

		} // end while
	
		cout << endl;
	}
	
	return 0;
}
