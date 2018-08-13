/*
 *
 * Dados n valores numéricos, informar el mayor, el menor
 * y en que posición del conjunto fueron ingresados 
 * cada uno de ellos.
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
	int contador=0;
	int cantidad_ingresos;
	int numero;
	int numero_mayor=0, numero_mayor_posicion=0;
	int numero_menor=0, numero_menor_posicion=0;
	
	/*********************************************************************/
	
	//
	// # 2. Entrada de datos && Proceso la información
	//
	cout << "Cuantos numeros desea ingresar? ";
	cin >> cantidad_ingresos;
	
	if(cantidad_ingresos > 1){
		for(int posicion = 0; posicion < cantidad_ingresos; posicion++){
			cout << "Ingresar un numero: ";
			cin >> numero;
			
			if(posicion == 1){
				numero_menor = numero;
				numero_mayor = numero;
			}
			else{
				if(numero > numero_mayor){
					numero_mayor = numero;
					numero_mayor_posicion = posicion;
				}
				else if(numero < numero_menor){
					numero_menor = numero;
					numero_menor_posicion = posicion;
				}
			} // end if
		} // end for
	} // end if
	
	/*********************************************************************/

	//
	// # 3. Salida de datos
	//
	cout << "Numero mayor: " << numero_mayor << endl;
	cout << "Numero mayor posicion: " << numero_mayor_posicion << endl;
	cout << "Numero menor: " << numero_menor << endl;
	cout << "Numero menor posicion: " << numero_menor_posicion << endl;
	
	return 0;
}
