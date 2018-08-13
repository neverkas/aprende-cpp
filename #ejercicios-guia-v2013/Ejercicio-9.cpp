/*
 * Aviso:
 * # Si solo queres usar la funcion to_string()
 * # En la terminal deberás agregar el parametro -std=c++0x
 * # algunos compiladores tiran error al usar to_string() de <string>
 * # Ej.: g++ -std=c++0x MyFile.cpp 
 *
 * Dadas dos fechas, informar cual es la más reciente.
 * Determinar cuales deben ser los datos de entrada y
 * en que formato los debe ingresar el usuario.
 * Nota: COnsidere que las fechas ingresadas pueden ser
 * anteriores, posteriores o bien una podría ser anterior
 * y la otra posterior a la fecha actual,
 *
 * 
*/

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using std::string;

//
// # Main
//
//
int main(){
	//
	// # 1. Defino las variables
	//
	int dia1, mes1, anio1, primer_fecha_formato;
	int dia2, mes2, anio2, segunda_fecha_formato;
	 // Esto permite convertir int a string para concatenar
	// utilizo <sstream> porque mi compilador retorna error con to_string()
	// sino tenes el mismo problema utiliza solo to_string()
 stringstream primer_fecha, segunda_fecha, fecha_actual;
	
	//
	// # 2. Entrada de datos
	//
	cout << "El formato de la fecha debe estar separado por espacios" << endl;
	cout << "(Ej.: 04 12 2016)" << endl;
	cout << '\n';
	cout << "Ingrese la primera fecha: ";
	cin >> dia1 >> mes1 >> anio1;

	cout << "Ingrese la segunda fecha: ";
	cin >> dia2 >> mes2 >> anio2;
	
	cout << '\n';
	
	//
	// # 3. Proceso la información
	//
	// El formato quedará: 31/12/2016 (sin los espacios)
	// Utilizo la biblioteca <sstream> para convertir int a string
	// y concatenar los datos de la fecha
	
	// Concateno la primera fecha
	primer_fecha << dia1 << '/' << mes1 << '/' << anio1;
	// Concateno la segunda fecha
	segunda_fecha << dia2 << '/' << mes2 << '/' << anio2;
 
	// El formato quedará: 2016 12 31 (sin los espacios)
	primer_fecha_formato = (anio1 * 10000) + (mes1 * 100) + dia1;
	segunda_fecha_formato = (anio2 * 10000) + (mes2 * 100) + dia2;

	// Verificar cual es la fecha mas reciente,
	// segun cual sea mayor
	if(primer_fecha_formato > segunda_fecha_formato){
		//	Guardo en la variable fecha_actual en formato string
		fecha_actual << primer_fecha.str();
	}else{
		//	Guardo en la variable fecha_actual en formato string		
		fecha_actual << segunda_fecha.str();		
	}

	//
	// # 3. Salida de datos
	//
	// Para mostrar en formato string se usa variable.str()
	cout << "La fecha mas actual es " << fecha_actual.str() << endl;
	 
	return 0;
}
