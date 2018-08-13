/*
 *
 * Dados 50 números enteros, 
 * informar el promedio de los mayores que 100
 * y la suma de los menores que -10
 *
 * Tips: 
 * El promedio de una lista de números se calcula
 * con la sumatoria de todos los numeros, dividido por la cantidad.
 * Ej.: El promedio de 2,2,3 es 2+2+3=7 => 7/3 (3 es la cant. de numeros)
 *
*/
#include <iostream>

using namespace std;

//
// # Main
//
int main(){
	//
	// # 1. Defino las variables
	//
	int contador = 0; // Inicio del bucle
	int cantidadEnteros = 50; // Final del bucle
	int numeroEntero;
	
	int enterosPositivos = 0;
	int enterosPositivosCantidad = 0;
	int enterosPositivosPromedio;
	int enterosNegativos = 0;
	
	/*********************************************************************/

	//
	// # 2. Entrada de datos && Proceso la información
	//
	// Bucle que seguirá iterando mientras se cumpla
	// la condición de 'contador' menor a 'cantidadEnteros'
	while(contador < cantidadEnteros){
		contador++;
		cout << "Ingrese un numero entero: ";
		cin >> numeroEntero;

		// Si el numero ingresado es mayor a 100
		if(numeroEntero > 100){
			// Los voy sumando
			enterosPositivos+=numeroEntero;
			// Cuento la cantidad de numeros ingresados
			enterosPositivosCantidad++;
		}
		
		// Si el numero ingresado es menor a -10
		else if(numeroEntero < -10)			
			enterosNegativos+=numeroEntero; // Los voy sumando
		
	} // end while

	// Calculo el promedio de los enteros positivos
	// La sumatoria de todos los numeros dividido la cantidad de numeros
	enterosPositivosPromedio = (enterosPositivos / enterosPositivosCantidad);
	
	/*********************************************************************/

	//
	// # 3. Salida de datos
	//
	cout << "El promedio de los mayores que 100 es: ";
	cout << enterosPositivosPromedio << endl;
	
	cout << "La suma de los menores que -10 es: ";
	cout << enterosNegativos << endl;
	
	return 0;
}
