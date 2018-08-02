/*
 *
 * Se ingresa un valor numérico entero, se pide
 * calcular e informar su factorial.
 *
 * Tip: El factorial de un número es el producto de 
 * multiplicar el número 'x', por los numeros naturales
 * o enteros positivos desde el primero hasta el nùmero 'x'.
 * (Ej.: El factorial de 5 es 120 a causa de	1*2*3*4*5=120)
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
	int numero, resultado, contador;

	/*********************************************************************/
	
	//
	// # 2. Entrada de datos
	//
	cout << "Ingrese el numero del que quiere su factorial: ";
	cin >> numero;

	/*********************************************************************/
	
	//
	// # 3. Proceso la información && Salida de datos
	//
	
	contador	= 1;
	resultado = 1;	// se multiplicará con el incremental

	cout << "La forma factorial del numero " << numero << " es:" << endl;
	cout << numero << "!=" << resultado;
	
	while(contador < numero){
		contador++;

		// Esto es lo mismo que
		// resultado = resultado * contador;
		// se guardara el resultado de la operacion y
		// seguira operando hasta finalizar el bucle
		resultado *= contador;

		cout << "*" << contador;
	}

	cout << "=" << resultado << endl;
	
	return 0;
}
