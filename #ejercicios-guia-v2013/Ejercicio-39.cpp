/*
 *
 * Desarrolle y pruebe la funcion unificarFecha que recibe tres parametros que 
 * representan el dia, mes y anio de una fecha y retorna la fecha unificada en un entero
 * largo de 8 digitos con el siguiente formato aaaammdd
 * El prototipo de la funcion debe ser el siguiente:
 * long unificarFecha(int dia, int mes, int anio);
 *
 *
*/
#include <iostream>

using namespace std;

long unificarFecha(int dia, int mes, int anio){
	long formatoFecha = 0;

	// multiplico por 10.000 para agregar 4 ceros a su derecha
	formatoFecha+=(anio*10000);
	// agrego 2 ceros a la derecha del numero de mes
	formatoFecha+=(mes*100);
	//
	formatoFecha+=dia;

	return formatoFecha;
}
int main(){
	cout << unificarFecha(30,12,2010);
	cout << endl;
	
	return 0;
}
