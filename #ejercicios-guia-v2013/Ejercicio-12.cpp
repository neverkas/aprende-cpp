/*
 *
 * Se ingresa la edad de un socio de un club, 
 * se pide mostrar por pantalla alguna de las siguientes leyendas:
 * - Menor: si la edad es menor o igual a 12.
 * - Cadete: si la edad está comprendida entre 13 y 18.
 * - Juvenil: si la edad es mayor que 18, y no supera los 26.
 * - Mayor: si	no cumple ninguna de las condiciones anteriores.
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
	short edad;
	string mensaje;

	//
	// # 2. Entrada de datos
	//
	cout << "Ingrese su edad: ";
	cin >> edad;

	//
	// # 3. Proceso la información
	//
	if(edad <= 12)
		mensaje = "menor";
	else if(edad >= 13 && edad <= 18)
		mensaje = "cadete";
	else if(edad > 18 && edad <= 26)
		mensaje = "juvenil";
	else
		mensaje = "mayor";

	//
	// # 4. Salida de datos
	//
	cout << "Según la edad ingresada, la persona es " << mensaje << endl;
	
	return 0;
}


