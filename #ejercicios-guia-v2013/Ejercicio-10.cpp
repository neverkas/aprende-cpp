/*
 *
 * Dado un triángulo representado por sus lados
 * lado1, lado2, y lado3.
 * Determinar e indiciar según corresponda como:
 * equilátero, isósceles, o escaleno.
 *
 * Tips:
 * -Equilatero, tiene todos sus lados iguales.
 * -Isósceles, tiene 2 lados iguales.
 * -Escaleno, 3 lados distintos.
 * 
*/
#include <iostream>
#include <string>

using namespace std;
using std::string;

//
// # Main
//
int main(){
	//
	// # 1. Defino las variables
	//
	int lado1, lado2, lado3;
	string triangulo_tipo;
	
	//
	// # 2. Entrada de datos
	//
	cout << "Ingrese la longitud de cada lado del triangulo, ";
	cout << "separado por espacios." << endl;
	
	cout << "(Ej.: 30 2 10)" << endl;
	cout << "Ingrese los datos: ";
	cin >> lado1 >> lado2 >> lado3;
	cout << '\n'; // new line							
	
	//
	// # 3. Proceso la información
	//
	// Triangulo isósceles, todos los lados iguales
	// Ej. lado1=10, lado2=10, lado3=10
	if(lado1 == lado2 && lado2 == lado3){
		triangulo_tipo = "Isosceles";
	}
	// Triangulo equilateros, dos lados iguales
	else if(lado1 == lado2 || lado2 == lado3 || lado3 == lado1){
		triangulo_tipo = "Equilatero";
	}
	// Triangulo escaleno, todos lados distintos
	else{
		triangulo_tipo = "Escaleno";
	}

	//
	// # 4. Salida de datos
	//
	cout << "Según los datos ingresados el triangulo es " << triangulo_tipo << endl;
	
	return 0;
}
