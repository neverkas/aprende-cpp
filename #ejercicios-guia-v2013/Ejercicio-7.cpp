/*
 *
 * Dada una terna de números naturales que representan
 * el día, el mes y el año de una determinada fecha
 * informarla como un solo número natural de 8 digitos
 * con formato (aaaammdd)
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
	int dia, mes, anio, fecha;

	cout << "Ingresar la fecha en formato dd/mm/aaaa" << endl;
	cout << "separada por espacios" << endl;
	cout << "Ej.: 22 12 2018" << endl;
	cout << '\n'; // new line

	//
	// # 2. Entrada de datos
	//
	cout << "Fecha: ";
	cin >> dia >> mes >> anio;

	//
	// # 3. Proceso la información
	//
	fecha = (anio * 10000) + (mes * 100) + dia;
	
	//
	// # 4. Salida de datos
	//
	cout << "Fecha en formato (aaaammdd): " << fecha << endl;
}
