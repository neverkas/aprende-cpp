/*
 *
 * PENDIENTE
 *
 * Desarrollar y probar una funcion que reciba un valor entero y retorne su factorial.
 * EL prototipo de la funcion debe ser el siguiente:
 * int factorial(int n);
 *
 * Analice las siguientes situaciones:
 * 1. Compruebe el comportamiento de la funcion factorial cuando recibe valores
 *		pequenios como parametro.
 * 2. Compruebe que el comportamiento de la funcion cuando recibe valores grandes
 *		(por ejemplo mayores que 100)
 * 3. Si en (2) experimento algun tipo de error, ¿cual considera que peude ser la causa 
 *		del problema y como lo solucionaria?
*/
#include <iostream>

using namespace std;

long double factorial(int);

int main(){
	int n = 100;
	long double resultado = factorial(n);

	cout << sizeof(int) << endl;
	cout << sizeof(n) << endl;
	cout << sizeof(resultado) << endl;
	cout << "factorial: " << resultado << endl;
	
	return 0;
}

long double factorial(int n){
	long double x = 1;
	
	for(int i=1; i <= n; i++){
		x *= i;
		//cout << i << ") " << x << endl;
	}

	return x;
}
