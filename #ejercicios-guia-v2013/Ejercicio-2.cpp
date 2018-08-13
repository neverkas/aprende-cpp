/*
 * Dados dos valores numericos enteros a y b 
 * calcular e informar el cosiente a/b
 * Considere que b puede ser cero,
 * en ese caso mostrar el correspondiente mensaje de error
 * 
 * MODIFICACION:
 * En este caso se utiliza condicionales para verificar que
 * el resultado sea distinto de cero
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
	int a, b, result;

	//
	// # 2. Entrada de datos
	//
	cout << "Ingrese el primer numero ";
	cin >> a;

	cout << "Ingrese el segundo numero ";
	cin >> b;

	//
	// # 3. Proceso la información && Salida de datos
	//
	// Si el segundo numero, que es el divisor es igual a cero
	if(b == 0){
		// Mostrar el mensaje que no se puede dividir por cero
		cout << "No se puede dividir por cero!" << endl;
	}
	else{
		// Si el divisor es distinto a cero
		// Divir a por b
		int dividir = (a / b);
		
		cout << "La divisón a/b es " << dividir << endl;	
	}
	
	return 0;
}
