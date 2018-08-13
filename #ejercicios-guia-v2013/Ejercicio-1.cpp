/*
 * Dados dos valores numericos enteros a y b
 * Calcular e informar
 * -La suma de a+b
 * -La diferencia a-b
 * -El producto a*b
*/
#include <iostream>

using namespace std;

//
// # Prototipos
//
int sumar(int a, int b);
int restar(int a, int b);
int multiplicar(int a, int b);

/*********************************************************************/

//
// # Main
//
int main(){	
	//
	// # 1. Defino las variables
	//
	int a,b;

	//
	// # 2. Entrada de datos
	//
	cout << "Ingrese el primer número: ";
	cin>>a;
	cout << "Ingrese el segundo número: ";
	cin>>b;

	cout << "Operaciones efectuadas: " << endl;
					
	//
	// # 3.  Proceso la información && Salida de datos
	//
	cout << "La suma de a+b es " << sumar(a, b) << endl;
	cout << "La resta a-b es " << restar(a, b) << endl;
	cout << "La multiplicacion a*b es " << multiplicar(a, b) << endl;
}

/*********************************************************************/
//
// # Funciones
//
int sumar(int a, int b){
	return (a + b);
}

int restar(int a, int b){
	return (a - b);
}

int multiplicar(int a, int b){
	return (a * b);
}
