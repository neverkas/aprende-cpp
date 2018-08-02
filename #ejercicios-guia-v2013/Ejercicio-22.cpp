/*
 *
 * Dado un conjunto de nombres y fechas de nacimiento 
 * con formato ddmmaaaa, que finaliza cuando se ingrese 
 * un nombre igual a "fin", informar el nombre de la 
 * persona con mayor edad y el de la más joven.
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
	int fecha_ingresada;
	string nombre_ingresado;			
	int mas_joven_fecha = 0;
	int mas_viejo_fecha = 0;
	string mas_viejo_nombre = "";
	string mas_joven_nombre = "";
	int fecha_formateada = 0;
	int contador = 0;
	
	/*********************************************************************/

	//
	// # 2. Entrada de datos && Proceso la información
	//
	while(nombre_ingresado != "fin"){
		contador++;
		
		cout << "nombre: ";
		cin >> nombre_ingresado;

		if(nombre_ingresado != "fin"){
			cout << "fecha: ";
			cin >> fecha_ingresada;

			fecha_formateada += (fecha_ingresada / 1000000); // día
			fecha_formateada += ((fecha_ingresada % 1000000) / 10000 ); // mes
			fecha_formateada += (fecha_ingresada % 10000); // año

			cout << fecha_formateada << endl;
		
			if(contador == 1){
				mas_joven_fecha = fecha_formateada;
				mas_viejo_fecha = fecha_formateada;
				mas_joven_nombre = nombre_ingresado;
				mas_viejo_nombre = nombre_ingresado;
			}
			else{
				if(fecha_formateada > mas_joven_fecha){
					mas_joven_fecha = fecha_formateada;
					mas_joven_nombre = nombre_ingresado;
				}
				else if(fecha_formateada < mas_viejo_fecha){
					mas_viejo_fecha = fecha_formateada;
					mas_viejo_nombre = nombre_ingresado;
				}
			} // end if			
		} // end if				
	} // end while
	
	/*********************************************************************/

	//
	// # 3. Salida de datos
	//
	cout << "Mas joven: " <<  mas_joven_nombre << endl;
	cout << "Mas viejo: " << mas_viejo_nombre << endl;
	
	return 0;
}
