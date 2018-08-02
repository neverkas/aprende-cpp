/*
 *
 * Dados dos valores numéricos enteros,
 * calcular e informar su producto mediante sumas sucesivas
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
	int a,b, resultado;
	int numero_menor, numero_mayor;
	int contador = 0;
	
	/*********************************************************************/

	//
	// # 2. Entrada de datos
	//
	cout << "Ingrese dos numeros separados por un espacio." << endl;
	cout << "(Ej. 2 10)" << endl;
	cout << "Ingrese los numeros: ";
	cin >> a >> b;
	cout << '\n'; // new line
	
	/*********************************************************************/
	
	//
	// # 3. Proceso la información
	//
	// Para generar un loop con menos iteraciones	
	// 1. Guardar el numero mayor 'a' y 'b' este el valor que se sumara
	// 2. Guardar el numero menor entre 'a' y 'b' este sera la cantidad de iteraciones del oop	
	if(a > b){
		numero_mayor = a;
		numero_menor = b;
	}else{
		numero_mayor = b;
		numero_menor = a;
	}	

	// Asigno valor cero a 'resultado' para que pueda sumar
	resultado = 0;
	// Bucle que itera tantas veces el valor de 'numero_menor'
	while(contador < numero_menor){
		contador++;
		// Sumo a 'resultado' el valor 'numero_mayor'
		resultado +=numero_mayor;
	}
	
	/*********************************************************************/

	//
	// # 3. Salida de datos
	//
	cout << "(*) El resultado de multiplicar " << a << " por " << b << " es " << resultado;
	cout << '\n'; // new line
		
	cout << "(*) Sumar el " << numero_mayor << " unas " << numero_menor << " veces es " << resultado;
	cout << '\n'; // new line
	
	return 0;
}
